#include "pico/stdlib.h"
#include "EPD_Test.h"
#include "EPD_1in54_V2.h"

int main() {    
    // Initialize chosen serial port
    stdio_init_all();
    printf("Pico Started, will wait 1 minute before EPD actions...\r\n");

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    //const uint LED_PIN = 25;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    //Blink Once
    gpio_put(LED_PIN, 1);
    sleep_ms(250);
    gpio_put(LED_PIN, 0);
    sleep_ms(250);
    //sleep_ms(60*1000);
    printf("Starting EPD.......\r\n");

    DEV_Delay_ms(500);
    
    EPD_1in54_V2_test();

    UBYTE *BlackImage;
    UWORD Imagesize = ((EPD_1IN54_V2_WIDTH % 8 == 0)? (EPD_1IN54_V2_WIDTH / 8 ): (EPD_1IN54_V2_WIDTH / 8 + 1)) * EPD_1IN54_V2_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        return -1;
    }

    // The image of the previous frame must be uploaded, otherwise the
    // first few seconds will display an exception.
    EPD_1IN54_V2_DisplayPartBaseImage(BlackImage);
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);
    // enter partial mode
    EPD_1IN54_V2_Init_Partial();
    printf("Partial refresh\r\n");

    printf("Going to blink LED now, and brief animation of letter 'A'.......\r\n");
    int xpos = 0; 
    int ypos= 0;
    int xinc = 17;
    int yinc = 24;
    int xfact = 1;
    int yfact = 1;
    int ledval = 1;
    int countdown = 100;
    bool lastTime = true;
    while (true) {
        //Keep Blinking
        gpio_put(LED_PIN, ledval);

        //Animate the character (countdown) times.
        if (countdown > 0)
        {
            //sleep_ms(250);
            Paint_ClearWindows(xpos, ypos, xpos + Font24.Width, ypos + Font24.Height, WHITE);
            Paint_DrawChar(xpos, ypos, 'A', &Font24, BLACK, WHITE);
            EPD_1IN54_V2_DisplayPart(BlackImage);
            DEV_Delay_ms(100);

            //gpio_put(LED_PIN, 0);
            Paint_ClearWindows(xpos, ypos, xpos + Font24.Width, ypos + Font24.Height, WHITE);
            Paint_DrawChar(xpos, ypos, ' ', &Font24, BLACK, WHITE);
            //sleep_ms(2000);
            EPD_1IN54_V2_DisplayPart(BlackImage);
            DEV_Delay_ms(100);

            if (xpos>=0 && xpos+(xfact*xinc)<=EPD_1IN54_V2_WIDTH-1)
                xfact = xfact;
            if (xpos>=0 && xpos+(xfact*xinc)>EPD_1IN54_V2_WIDTH-1)
                xfact = -1 * xfact;
            if (xpos<0)
                xfact = -1 * xfact;
            //Update x-position                
            xpos = xpos + (xfact*xinc);

            if (ypos>=0 && ypos+(yfact*yinc)<=EPD_1IN54_V2_HEIGHT-1)
                yfact = yfact;
            if (ypos>=0 && ypos+(yfact*yinc)>EPD_1IN54_V2_HEIGHT-1)
                yfact = -1 * yfact;
            if (ypos<0)
                yfact = -1 * yfact;
            //Update y-position
            ypos = ypos + (yfact*yinc);

            countdown = countdown - 1 ;
        }
        else
            if (lastTime) {
                EPD_1IN54_V2_Init();
                EPD_1IN54_V2_Clear();

                printf("Goto Sleep...\r\n");
                EPD_1IN54_V2_Sleep();
                free(BlackImage);
                BlackImage = NULL;
                DEV_Delay_ms(2000);//important, at least 2s
                // close 5V
                printf("close 5V, Module enters 0 power consumption ...\r\n");
                DEV_Module_Exit();

                lastTime = !(lastTime);
            }
            else
                sleep_ms(500);
        
        //flip LED state in next iteration
        ledval = ledval ^ 1;
    }

    return 0;
}