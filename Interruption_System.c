#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/uart.h"
#include "hardware/clocks.h"

#include "ws2812.pio.h"

#include "include/leds.h"
#include "include/matrix5x5.h"
#include "include/button.h"

int main()
{
    stdio_init_all();

    init_gpio();       // inicia os leds
    init_buton_gpio(); // inicia os botões

    PIO pio = pio0;                                      // Configuração do PIO 0
    int sm = 0;                                          // Define o estado da máquina de estado do PIO (SM)
    uint offset = pio_add_program(pio, &ws2812_program); // Vai carregar o programa do PIO para controlar os LEDs WS2812

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW); // Vai inicializar o programa de controle do WS2812 no PIO

    // Configuração da interrupção com callback para botão A E B
    gpio_set_irq_enabled_with_callback(Button_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(Button_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    // Obs: Foi utilizado a interrupção de borda de descida (falling edge)

    // Exibir o primeiro número ao iniciar
    display_number(current_number);

    while (true)
    {
        blink_led(); // Função que faz o LED vermelho piscar continuamente 5 vezes por segundo (definida em leds.h)
    }
}