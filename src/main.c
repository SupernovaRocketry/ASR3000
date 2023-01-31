#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

void vtask_blink_led(void *parameters){
    gpio_pad_select_gpio (GPIO_NUM_2);
    gpio_set_direction (GPIO_NUM_2, GPIO_MODE_OUTPUT);

    printf("Task do blink LED ...\n");

    int uiCounter = 0;

    while(true){
        gpio_set_level(GPIO_NUM_2, (uiCounter % 2));
        // delay de 1s
        vTaskDelay(1000/portTICK_PERIOD_MS);
        // incrementar o contador
        uiCounter++;
    }
}

void app_main() {
    xTaskCreate(vtask_blink_led,
                "vtask_blink_led",
                1024,
                NULL,
                1,
                NULL);

    // Indicação que a task foi criada
    printf("Task do blink LED foi criada!\n");

}