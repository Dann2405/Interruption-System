#ifndef MATRIX_H
#define MATRIX_H


// definições inciais

#define WS2812_PIN 7
#define IS_RGBW false
#define columns 5
#define rows 5
#define tempo 400

uint8_t led_r = 0;   // Intensidade do vermelho
uint8_t led_g = 0;   // Intensidade do verde
uint8_t led_b = 200; // Intensidade do azul

// BUFFER DE NUMBEROS DE 0 A 9 (O led vai ligar onde tiver 1 e desligar onde tiver 0)
bool number0[columns][rows] =
    {
        0, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        1, 0, 0, 0, 1,
        0, 1, 1, 1, 0
    };

bool number1[columns][rows] =
    {
        0, 0, 1, 0, 0,
        0, 1, 1, 0, 0,
        1, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        1, 1, 1, 1, 1
    };

bool number2[columns][rows] =
    {
        0, 1, 1, 0, 0,
        1, 0, 0, 1, 0,
        0, 0, 1, 0, 0,
        0, 1, 0, 0, 0,
        1, 1, 1, 1, 0
    };

bool number3[columns][rows] =
    {
        0, 1, 1, 0, 0,
        1, 0, 0, 1, 0,
        0, 0, 1, 0, 0,
        1, 0, 0, 1, 0,
        0, 1, 1, 0, 0
    };

bool number4[columns][rows] =
    {
        0, 0, 1, 1, 0,
        0, 1, 0, 1, 0,
        1, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 0, 0, 1, 0
    };


bool number5[columns][rows] =
    {
        1, 1, 1, 1, 0,
        1, 1, 1, 0, 0,
        0, 0, 0, 1, 0,
        1, 0, 0, 1, 0,
        0, 1, 1, 0, 0
    };

bool number6[columns][rows] = 
    {
        1, 1, 1, 1, 0,
        1, 0, 0, 0, 0,
        1, 1, 1, 1, 0,
        1, 0, 0, 1, 0,
        1, 1, 1, 1, 0
    };

bool number7[columns][rows] =
    {
        1, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 0, 1, 0, 0,
        0, 1, 0, 0, 0,
        1, 0, 0, 0, 0
    };

bool number8[columns][rows] =
    {
        0, 1, 1, 0, 0,
        1, 0, 0, 1, 0,
        0, 1, 1, 0, 0,
        1, 0, 0, 1, 0,
        0, 1, 1, 0, 0
    };

bool number9[columns][rows] = 
    {
        0, 1, 1, 0, 0,
        1, 0, 0, 1, 0,
        0, 1, 1, 1, 0,
        0, 0, 1, 0, 0,
        0, 1, 0, 0, 0
    };

// envia o valor da cor para o led
static inline void put_pixel(uint32_t pixel_grb)
{
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

// combina os valores RGB em um inteiro de 32 bits
static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b)
{
    return ((uint32_t)(r) << 8) | ((uint32_t)(g) << 16) | (uint32_t)(b);
}

// SET NUMBERS DE 0 A 9

// number 0 matrix
void set_number0(uint8_t r, uint8_t g, uint8_t b)
{
    // Define a cor com base nos parâmetros fornecidos
    uint32_t color = urgb_u32(r, g, b);

    // Configuração do caminho em zigue zague
    for (int i = columns - 1; i >= 0; i--) // pecorre as linhas de cima para baixo
    {
        if ((columns - i) % 2 == 0) // Colunas ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // (Linhas são lidas da esquerda para a direita (j = 0 a 4))
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
        else // colunas impares tem direção invertida (Linhas são lidas da direita para a esquerda (j = 4 a 0), criando um padrão zigue-zague)
        {
            for (int j = rows - 1; j >= 0; j--) // ler da esquerda para a direita
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
}

// number 1 matrix
void set_number1(uint8_t r, uint8_t g, uint8_t b)
{
    // Define a cor com base nos parâmetros fornecidos
    uint32_t color = urgb_u32(r, g, b);

    // Configuração do caminho em zigue zague
    for (int i = columns - 1; i >= 0; i--) // pecorre as linhas de cima para baixo
    {
        if ((columns - i) % 2 == 0) // Colunas ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // (Linhas são lidas da esquerda para a direita (j = 0 a 4))
            {
                if (number1[i][j])
                {
                    put_pixel(color); // Liga o LED com um no buffer
                }
                else
                {
                    put_pixel(0); // Desliga os LEDs com zero no buffer
                }
            }
        }
        else // colunas impares tem direção invertida (Linhas são lidas da direita para a esquerda (j = 4 a 0), criando um padrão zigue-zague)
        {
            for (int j = rows - 1; j >= 0; j--) // ler da esquerda para a direita
            {
                if (number1[i][j])
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
}

// number 2 matrix
void set_number2(uint8_t r, uint8_t g, uint8_t b)
{
    // Define a cor com base nos parâmetros fornecidos
    uint32_t color = urgb_u32(r, g, b);

    // Configuração do caminho em zigue zague
    for (int i = columns - 1; i >= 0; i--) // pecorre as linhas de cima para baixo
    {
        if ((columns - i) % 2 == 0) // Colunas ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas são lidas da esquerda para a direita (j = 0 a 4)
            {
                if (number2[i][j])
                {
                    put_pixel(color); // Liga o LED com um no buffer
                }
                else
                {
                    put_pixel(0); // Desliga os LEDs com zero no buffer
                }
            }
        }
        else // colunas impares tem direção invertida (Linhas são lidas da direita para a esquerda (j = 4 a 0), criando um padrão zigue-zague)
        {
            for (int j = rows - 1; j >= 0; j--) // ler da esquerda para a direita
            {
                if (number2[i][j])
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
}

// number 3 matrix
void set_number3(uint8_t r, uint8_t g, uint8_t b)
{
    // Define a cor com base nos parâmetros fornecidos
    uint32_t color = urgb_u32(r, g, b);

    // Configuração do caminho em zigue zague
    for (int i = columns - 1; i >= 0; i--)
    {
        if ((columns - i) % 2 == 0) // Colunas ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas são lidas da esquerda para a direita (j = 0 a 4)
            {
                if (number3[i][j])
                {
                    put_pixel(color); // Liga o LED com um no buffer
                }
                else
                {
                    put_pixel(0); // Desliga tods os leds com zero no buffer
                }
            }
        }
        else // colunas impares tem direção invertida (linhas são leidas da direita para a esquerda, j = 4 a 0, criando um padrão zigue zague)
        {
            for (int j = rows - 1; j >= 0; j--)
            {
                if (number3[i][j])
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
}

// number 4 matrix
void set_number4(uint8_t r, uint8_t g, uint8_t b)
{
    // Define a cor com base nos parâmetros fornecidos
    uint32_t color = urgb_u32(r, g, b);

    // Configuração do caminho em zigue zague
    for (int i = columns - 1; i >= 0; i--)
    {
        if ((columns - i) % 2 == 0) // Colunas ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas são lidas da esquerda para a direita (j = 0 a 4)
            {
                if (number4[i][j])
                {
                    put_pixel(color); // Liga o LED com um no buffer
                }
                else
                {
                    put_pixel(0); // Desliga tods os leds com zero no buffer
                }
            }
        }
        else // colunas impares tem direção invertida (linhas são leidas da direita para a esquerda, j = 4 a 0, criando um padrão zigue zague)
        {
            for (int j = rows - 1; j >= 0; j--)
            {
                if (number4[i][j])
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
}

// number 5 matrix
void set_number5(uint8_t r, uint8_t g, uint8_t b)
{
    // Define a cor com base nos parâmetros fornecidos
    uint32_t color = urgb_u32(r, g, b);

    // Configuração do caminho em zigue zague
    for (int i = columns - 1; i >= 0; i--)
    {
        if ((columns - i) % 2 == 0) // Colunas ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas são lidas da esquerda para a direita (j = 0 a 4)
            {
                if (number5[i][j])
                {
                    put_pixel(color); // Liga o LED com um no buffer
                }
                else
                {
                    put_pixel(0); // Desliga tods os leds com zero no buffer
                }
            }
        }
        else // colunas impares tem direção invertida (linhas são leidas da direita para a esquerda, j = 4 a 0, criando um padrão zigue zague)
        {
            for (int j = rows - 1; j >= 0; j--)
            {
                if (number5[i][j])
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
}

// number 6 matrix
void set_number6(uint8_t r, uint8_t g, uint8_t b)
{
    // Define a cor com base nos parâmetros fornecidos
    uint32_t color = urgb_u32(r, g, b);

    // Configuração do caminho em zigue zague
    for (int i = columns - 1; i >= 0; i--)
    {
        if ((columns - i) % 2 == 0) // Colunas ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas são lidas da esquerda para a direita (j = 0 a 4)
            {
                if (number6[i][j])
                {
                    put_pixel(color); // Liga o LED com um no buffer
                }
                else
                {
                    put_pixel(0); // Desliga tods os leds com zero no buffer
                }
            }
        }
        else // colunas impares tem direção invertida (linhas são leidas da direita para a esquerda, j = 4 a 0, criando um padrão zigue zague)
        {
            for (int j = rows - 1; j >= 0; j--)
            {
                if (number6[i][j])
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
}

// number 7 matrix
void set_number7(uint8_t r, uint8_t g, uint8_t b)
{
    // Define a cor com base nos parâmetros fornecidos
    uint32_t color = urgb_u32(r, g, b);

    // Configuração do caminho em zigue zague
    for (int i = columns - 1; i >= 0; i--)
    {
        if ((columns - i) % 2 == 0) // Colunas ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas são lidas da esquerda para a direita (j = 0 a 4)
            {
                if (number7[i][j])
                {
                    put_pixel(color); // Liga o LED com um no buffer
                }
                else
                {
                    put_pixel(0); // Desliga tods os leds com zero no buffer
                }
            }
        }
        else // colunas impares tem direção invertida (linhas são leidas da direita para a esquerda, j = 4 a 0, criando um padrão zigue zague)
        {
            for (int j = rows - 1; j >= 0; j--)
            {
                if (number7[i][j])
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
}

// number 8 matrix
void set_number8(uint8_t r, uint8_t g, uint8_t b)
{
    // Define a cor com base nos parâmetros fornecidos
    uint32_t color = urgb_u32(r, g, b);

    // Configuração do caminho em zigue zague
    for (int i = columns - 1; i >= 0; i--)
    {
        if ((columns - i) % 2 == 0) // Colunas ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // Linhas são lidas da esquerda para a direita (j = 0 a 4)
            {
                if (number8[i][j])
                {
                    put_pixel(color); // Liga o LED com um no buffer
                }
                else
                {
                    put_pixel(0); // Desliga tods os leds com zero no buffer
                }
            }
        }
        else // colunas impares tem direção invertida (linhas são leidas da direita para a esquerda, j = 4 a 0, criando um padrão zigue zague)
        {
            for (int j = rows - 1; j >= 0; j--)
            {
                if (number8[i][j])
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
}

// number 9 matrix
void set_number9(uint8_t r, uint8_t g, uint8_t b)
{
    // Define a cor com base nos parâmetros fornecidos
    uint32_t color = urgb_u32(r, g, b);

    // Configuração do caminho em zigue zague
    for (int i = columns - 1; i >= 0; i--) // pecorre as linhas de cima para baixo
    {
        if ((columns - i) % 2 == 0) // Colunas ler da direita para a esquerda
        {
            for (int j = 0; j < rows; j++) // (Linhas são lidas da esquerda para a direita (j = 0 a 4))
            {
                if (number9[i][j])
                {
                    put_pixel(color); // Liga o LED com um no buffer
                }
                else
                {
                    put_pixel(0); // Desliga os LEDs com zero no buffer
                }
            }
        }
        else // colunas impares tem direção invertida (Linhas são lidas da direita para a esquerda (j = 4 a 0), criando um padrão zigue-zague)
        {
            for (int j = rows - 1; j >= 0; j--) // ler da esquerda para a direita
            {
                if (number9[i][j])
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
}

#endif