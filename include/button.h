#include "include/matrix5x5.h"

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

volatile int current_number = 0; //Número atual (de zero a 9)
volatile bool debounce_active = false; // vai controlar se o botão pode ser prssionado novamente
struct repeating_timer debounce_timer; // cria um temporizador para debounce (timer programavel)

// Protótipos das funções
void gpio_irq_handler(uint gpio, uint32_t events);
bool debounce_timer_callback(struct repeating_timer *t);


// Vai exibir número baseado na variável current_number
void display_number(int num)
{
    switch (num)
    {
    case 0:
        set_number0(led_r, led_g, led_b);
        break;
    case 1:
        set_number0(led_r, led_g, led_b);
        break;
    case 2:
        set_number0(led_r, led_g, led_b);
        break;
    case 3:
        set_number0(led_r, led_g, led_b);
        break;
    case 4:
        set_number0(led_r, led_g, led_b);
        break;
    case 5:
        set_number0(led_r, led_g, led_b);
        break;
    case 6:
        set_number0(led_r, led_g, led_b);
        break;
    case 7:
        set_number0(led_r, led_g, led_b);
        break;
    case 8:
        set_number0(led_r, led_g, led_b);
        break;
    case 9:
        set_number0(led_r, led_g, led_b);
        break;
    
    default: 
        set_number0(led_r, led_g, led_b);
        break;
    }
}

// Interrupção do botão com debounce

void gpio_irq_handler(uint gpio, uint32_t events)
{
    if(!debounce_active)
    {
        debounce_active = true;
        add_repeating_timer_ms(50, debounce_timer_callback, NULL, &debounce_timer);
    }
}

// Callback de debounce
bool debounce_timer_callback(struct repeating_timer *t)
{
    if(gpio_get(Button_A) == 0)
    {
        current_number = (current_number + 1) % 10;
        display_number(current_number);
    }
    debounce_active = false;
    return false;
}
