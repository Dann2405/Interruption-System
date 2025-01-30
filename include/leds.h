// definições inciais

const uint LED_RED = 13;
const uint LED_GREEN = 11;
const uint LED_BLUE = 12;

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