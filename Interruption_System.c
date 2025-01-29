#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/uart.h"
#include "hardware/clocks.h"

#include "ws2812.pio.h"

/*Descrição do Projeto:
Neste projeto, você deverá utilizar os seguintes componentes conectados à placa BitDogLab:
• Matriz 5x5 de LEDs (endereçáveis) WS2812, conectada à GPIO 7.
• LED RGB, com os pinos conectados às GPIOs (11, 12 e 13).
• Botão A conectado à GPIO 5.
• Botão B conectado à GPIO 6.


Funcionalidades do Projeto
1. O LED vermelho do LED RGB deve piscar continuamente 5 vezes por segundo.
2. O botão A deve incrementar o número exibido na matriz de LEDs cada vez que for pressionado.
3. O botão B deve decrementar o número exibido na matriz de LEDs cada vez que for pressionado.
4. Os LEDs WS2812 devem ser usados para criar efeitos visuais representando números de 0 a 9.
• Formatação fixa: Cada número deve ser exibido na matriz em um formato fixo, como
caracteres em estilo digital (ex.: segmentos iluminados que formem o número).
• Alternativamente, é permitido utilizar um estilo criativo, desde que o número seja claramente
identificável.*/

// Configuração dos pinos
#define NUM_PIXELS 25
#define WS2812_PIN 7
const uint LED_RED = 13;
const uint LED_GREEN = 11;
const uint LED_BLUE = 12;
const uint Button_A = 5;
const uint Button_B = 6;


int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
