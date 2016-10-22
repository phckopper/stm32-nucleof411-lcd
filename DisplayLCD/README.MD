#Display LCD

Biblioteca para uso de um display LCD 16x2 com uma placa de desenvolvimento ARM Nucleo F411RE.

No ```main.c``` temos um pequeno exemplo de uso. Na sua aplicação será necessário utilizar apenas os arquivos ```lcd.h``` e ```lcd.c```.

- - -

## Instruções de uso

Primeiramente, importamos a biblioteca

```c
	#include "lcd.h"
```

Inicializamos o clock da _GPIO_ a ser utilizado. A biblioteca (ainda) não faz isso sozinha.

```c
	__GPIOA_CLK_ENABLE();
```

Depois, configuramos o display. Utilizamos a estrutura global ```LCD```, definida no header ```lcd.h```. 
É necessário configurar os pinos de _enable_, _RS_ e os pinos de dados, além da porta onde estão conectados.
Até o presente momento é necessário que todos os pinos estejam na mesma porta.

```c
	LCD.enable = GPIO_PIN_0;
	LCD.rs = GPIO_PIN_1;
	LCD.pinos[0] = GPIO_PIN_5;
	LCD.pinos[1] = GPIO_PIN_6;
	LCD.pinos[2] = GPIO_PIN_7;
	LCD.pinos[3] = GPIO_PIN_8;
	LCD.porta = GPIOA;
```

Por último, chamamos a função de inicialização, sem argumentos:

```c	
	init_display();
```

Após isso, as seguintes funções estarão disponíveis:

```c
clear(void) // Limpa o display (cuidado, função bastante lenta)
printf(const char* format, ...) // mesmo printf da stdlib
gotoxy(int x, int y) // move o cursor para dado ponto da tela
```
- - -
## Ligação elétrica

Para o exemplo acima, o display deve ser ligado conforme o seguinte:

|  ARM  | LCD |
| ----- | --- |
| GND   | RW  |
| GND   | VO  |
| PA0   | EN  |
| PA1   | RS  |
| PA5   | D4  |
| PA6   | D5  |
| PA7   | D6  |
| PA8   | D7  |

Não se esqueça também de alimentar o display corretamente, conferindo a pinagem específica de seu display.

- - -
## Mini-exemplo (não testado)

```c
#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"

#include "lcd.h"

int main(void)
{
	HAL_Init();

	// Configuração e inicialização do display
	LCD.enable = GPIO_PIN_0;
	LCD.rs = GPIO_PIN_1;
	LCD.pinos[0] = GPIO_PIN_5;
	LCD.pinos[1] = GPIO_PIN_6;
	LCD.pinos[2] = GPIO_PIN_7;
	LCD.pinos[3] = GPIO_PIN_8;
	LCD.porta = GPIOA;

	init_display();

	// Limpa o display
	clear();

	// Imprime na tela		
	printf("Oie mundo");
	
	// Espera infinitamente
	while(1);
}
```
