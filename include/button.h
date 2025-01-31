// definições inciais

const uint Button_A = 5;
const uint Button_B = 6;

// 2. O botão A deve incrementar o número exibido na matriz de LEDs cada vez que for pressionado.
// 3. O botão B deve decrementar o número exibido na matriz de LEDs cada vez que for pressionado.

void init_buton_gpio()
{
    gpio_init(Button_A);
    gpio_init(Button_B);

    gpio_set_dir(Button_A, GPIO_IN);
    gpio_set_dir(Button_B, GPIO_IN);

    gpio_pull_up(Button_A);
    gpio_pull_up(Button_B);
}