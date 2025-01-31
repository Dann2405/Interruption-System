#include "include/matrix5x5.h"

// definições inciais

const uint Button_A = 5; // define o button A como a gpio 5 que vai ser responsavel por incrementar o número
const uint Button_B = 6; // define o button B como a gpio 6 que vai ser responsavel por decrementar o número

// função de inicialização dos pinos GPIOs
void init_buton_gpio()
{
    gpio_init(Button_A);
    gpio_init(Button_B);

    gpio_set_dir(Button_A, GPIO_IN);
    gpio_set_dir(Button_B, GPIO_IN);

    gpio_pull_up(Button_A);
    gpio_pull_up(Button_B);
}

volatile int current_number = 0;       // Número atual (de zero a 9)
volatile bool debounce_active = false; // vai controlar se o botão pode ser prssionado novamente
struct repeating_timer debounce_timer; // cria um temporizador para debounce (timer programavel)
volatile uint last_pressed_button = 0; // Último botão pressionado

// Protótipos das funções
void gpio_irq_handler(uint gpio, uint32_t events);
bool debounce_timer_callback(struct repeating_timer *t);

// Vai exibir o número na matrix 5x5 baseado na variável current_number
void display_number(int num)
{
    switch (num)
    {
    case 0:
        set_number0(led_r, led_g, led_b);
        break;
    case 1:
        set_number1(led_r, led_g, led_b);
        break;
    case 2:
        set_number2(led_r, led_g, led_b);
        break;
    case 3:
        set_number3(led_r, led_g, led_b);
        break;
    case 4:
        set_number4(led_r, led_g, led_b);
        break;
    case 5:
        set_number5(led_r, led_g, led_b);
        break;
    case 6:
        set_number6(led_r, led_g, led_b);
        break;
    case 7:
        set_number7(led_r, led_g, led_b);
        break;
    case 8:
        set_number8(led_r, led_g, led_b);
        break;
    case 9:
        set_number9(led_r, led_g, led_b);
        break;

    default:

        break;
    }
}

// Interrupção de GPIO para capturar a pressão do botão (com debounce)
void gpio_irq_handler(uint gpio, uint32_t events)
{
    // Verifica se o debounce não está ativo para permitir a leitura do botão
    if (!debounce_active)
    {
        debounce_active = true;                                                     // Ativa o debounce
        last_pressed_button = gpio;                                                 // Salva qual botão foi pressionado
        add_repeating_timer_ms(50, debounce_timer_callback, NULL, &debounce_timer); // Inicia um timer para o debounce (50ms)
    }
}

// Callback de debounce
bool debounce_timer_callback(struct repeating_timer *t)
{
    // Verifica se o botão pressionado ainda está com nível baixo (pressionado)
    if (gpio_get(last_pressed_button) == 0)
    {
        if (last_pressed_button == Button_A) // Se o botão A for pressionado, incrementa o número
        {
            if (current_number < 9) // incrementa o número se ele for menor que 9
            {
                current_number = (current_number + 1) % 10; // Incrementa até o numero 9 (não passa disso)
            }
        }
        else if (last_pressed_button == Button_B) // Se o botão B for pressionado, decrementa o número
        {
            if (current_number > 0) // Vaidecrementar se ele for maior que 0
            {
                current_number = (current_number - 1 + 10) % 10; // Decrementa até o numero 0 (não passa disso)
            }
        }

        display_number(current_number); // Exibe o número atualizado na matriz de LEDs
    }

    debounce_active = false; // Desativa o debounce para permitir o próximo pressionamento do botão
    return false;            // Não repetir o timer
}
