# Interruption-System

## Descrição do Projeto

O **Interruption-System** é um projeto que demonstra o uso de interrupções no microcontrolador RP2040, com foco na manipulação de botões e exibição de números em uma matriz de LEDs WS2812 5x5. O sistema foi desenvolvido para rodar tanto no **Wokwi Simulator** (integrado ao VS Code) quanto em hardware real, utilizando a placa de desenvolvimento **BitDogLab**.

As funcionalidades principais incluem:
- **LED RGB:** Pisca continuamente 5 vezes por segundo.
- **Botões com Interrupção e Debounce:**
  - **Botão A (GPIO 5):** Incrementa os números exibidos na matriz de 0 a 9 a cada pressão.
  - **Botão B (GPIO 6):** Decrementa os números exibidos na matriz de 9 a 0 a cada pressão.
- **Matriz 5x5 WS2812:** Exibe os números com efeitos visuais que representam de forma clara os dígitos de 0 a 9.

---

## Requisitos

- **Microcontrolador:** Raspberry Pi Pico ou Raspberry Pi Pico W
- **Placa de Desenvolvimento:** BitDogLab (opcional)
- **Conta no Wokwi Simulator:** [Wokwi](https://wokwi.com/) (opcional)
- **Editor de Código:** Visual Studio Code (VS Code)
- **SDK do Raspberry Pi Pico** devidamente configurado

---

## Instruções de Uso

### 1. Clone o Repositório

Clone o repositório para o seu computador utilizando o comando abaixo:

```bash
git clone https://github.com/Dann2405/Interruption-System.git
cd Interruption-System
```

---

### 2. Instale as Dependências

Certifique-se de que o SDK do Raspberry Pi Pico está corretamente configurado no VS Code. Recomenda-se a instalação das seguintes extensões:

- **C/C++** (Microsoft)
- **CMake Tools**
- **Wokwi Simulator** (opcional, para simulação no VS Code)
- **[Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico)**

---

### 3. Configure o VS Code

1. Abra o projeto no Visual Studio Code.
2. Verifique se todas as extensões recomendadas estão instaladas.
3. Utilize a interface da extensão do Raspberry Pi Pico para compilar o projeto clicando em **"Compile Project"**.  
    - Esse processo gerará o arquivo `.uf2` necessário para execução em hardware real e no Wokwi Simulator.

---

### 4. Utilizando o Simulador Wokwi Integrado

Para testar o projeto no Wokwi Simulator integrado ao VS Code:

1. Abra o arquivo `diagram.json` no VS Code.
2. Clique no botão **"Play"** para iniciar a simulação.
3. Interaja com os botões presentes na simulação para observar a matriz 5x5 WS2812 incrementando ou decrementando os números, enquanto o LED RGB pisca 5 vezes por segundo.

---

### 5. Teste no Hardware Real

#### Utilizando a Placa BitDogLab com Raspberry Pi Pico W:

1. **Modo de Programação:**
   - Conecte a placa ao computador e coloque-a no modo BOTSEEL:
     - Pressione e segure o botão **BOOTSEL** (na parte de trás da placa) e, em seguida, o botão **RESET** (na frente).
     - Após alguns segundos, solte o botão **RESET** e, em seguida, o botão **BOOTSEL**.
     - A placa entrará no modo de programação.

2. **Compilação e Upload:**
   - No VS Code, com a extensão do [Raspberry Pi Pico W](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico), clique em **"Compile Project"**.
   - Em seguida, clique em **"Run Project USB"** para executar o projeto na placa.

3. **Conexões Alternativas:**
   Caso não esteja utilizando a BitDogLab, é possível montar o circuito em uma protoboard ou outro microcontrolador (como o Arduino) utilizando a seguinte pinagem:

   | **Periférico**      | **Pino GPIO** |
   |---------------------|---------------|
   | Botão A             | GP5           |
   | Botão B             | GP6           |
   | LED RGB             | GP12          |
   | Matriz 5x5 WS2812   | GP7           |

Após realizar a configuração, todos os componentes estarão prontos para a operação do sistema.

---

## Funcionamento do Sistema

- **LED RGB:** Pisca continuamente 5 vezes por segundo.
- **Botão A (GPIO 5):** Incrementa o número exibido na matriz de LEDs 5x5 a cada pressão.
- **Botão B (GPIO 6):** Decrementa o número exibido na matriz de LEDs 5x5 a cada pressão.
- **Matriz de LEDs WS2812:** Exibe números de 0 a 9 com efeitos visuais, permitindo uma visualização clara dos dígitos.

---

## Vídeo de Demonstração

Click [AQUI](https://drive.google.com/file/d/10SKbR7IpSxphw9sJruMMVhffi9yCihAv/view?usp=sharing) para acessar o video de demonstração
