#include "pico/stdlib.h"
#include "EPD_Test.h"

int main() {    
    // Initialize chosen serial port
    stdio_init_all();

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    //const uint LED_PIN = 25;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    //Blink Once
    gpio_put(LED_PIN, 1);
    sleep_ms(250);
    gpio_put(LED_PIN, 0);
    sleep_ms(60*1000);
    printf("Starting EPD.......\r\n");

    DEV_Delay_ms(500);
    
    EPD_1in54_V2_test();

    printf("Going to blink now.......\r\n");
    while (true) {
        //Keep Blinking
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(1000);
    }
    return 0;
}