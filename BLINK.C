#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// Definir o pino do LED interno (GPIO 2)
#define BLINK_GPIO GPIO_NUM_2

// Função para configurar o GPIO
void configure_gpio(void) {
    // Resetar e configurar o pino do LED como saída
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

void app_main(void)
{
    // Configurar o GPIO antes de iniciar o loop principal
    configure_gpio();

    while (1) {
        // Ligar o LED e imprimir "LED ON"
        gpio_set_level(BLINK_GPIO, 1);
        printf("LED ON\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Aguardar 1 segundo

        // Desligar o LED e imprimir "LED OFF"
        gpio_set_level(BLINK_GPIO, 0);
        printf("LED OFF\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Aguardar 1 segundo
    }
}
