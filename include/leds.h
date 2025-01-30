// definições inciais

const uint LED_RED = 13;
const uint LED_GREEN = 11;
const uint LED_BLUE = 12;
#define time 100 // tempo de 100 ms

// 1. O LED vermelho do LED RGB deve piscar continuamente 5 vezes por segundo.


// configuração dos pinos GPIOs
void init_gpio()
{
    // inicializando os pinos dos leds

    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);

    // configurando as pinos como saida

    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
}

// Função para o led piscar 5 vezes por segundo
void blink_led()
{
    gpio_put(LED_RED, 1); // liga o led
    sleep_ms(time); // espera 100 ms
    gpio_put(LED_RED, 0); // desliga o led
    sleep_ms(time); // espera 100 ms
}
