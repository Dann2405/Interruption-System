// definições inciais

#define NUM_PIXELS 25
#define WS2812_PIN 7
#define IS_RGBW false
#define columns 5
#define rows 5
#define tempo 400

// 4. Os LEDs WS2812 devem ser usados para criar efeitos visuais representando números de 0 a 9.
// • Formatação fixa: Cada número deve ser exibido na matriz em um formato fixo, como
// caracteres em estilo digital (ex.: segmentos iluminados que formem o número).
// • Alternativamente, é permitido utilizar um estilo criativo, desde que o número seja claramente
// identificável.

uint8_t led_r = 0;   // Intensidade do vermelho
uint8_t led_g = 0;   // Intensidade do verde
uint8_t led_b = 200; // Intensidade do azul

bool number0[columns][rows] =
{
    1,0,1,0,1,
    1,0,1,0,1,
    0,0,0,0,0,
    1,0,0,1,0,
    0,1,0,1,0
};

static inline void put_pixel(uint32_t pixel_grb)
{
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b)
{
    return ((uint32_t)(r) << 8) | ((uint32_t)(g) << 16) | (uint32_t)(b);
}

void set_one_led(uint8_t r, uint8_t g, uint8_t b)
{
    // Define a cor com base nos parâmetros fornecidos
    uint32_t color = urgb_u32(r, g, b);

    // Define todos os LEDs com a cor especificada
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (number0[i][j])
            {
                put_pixel(color); // Liga o LED com um no buffer
            }
            else
            {
                put_pixel(0); // Desliga os LEDs com zero no buffer
            }
        }
    }
}