#Display LCD

Biblioteca para uso de um display LCD 16x2 com uma placa de desenvolvimento ARM Nucleo F411RE.

No ```main.c``` temos um pequeno exemplo de uso. Na sua aplica��o ser� necess�rio utilizar apenas os arquivos ```lcd.h``` e ```lcd.c```.

- - -

## Instru��es de uso

Primeiramente, importamos a biblioteca

	#include "lcd.h"
	
Inicializamos o clock da _GPIO_ a ser utilizado. A biblioteca (ainda) n�o faz isso sozinha.

	__GPIOA_CLK_ENABLE();

Depois, configuramos o display. Utilizamos a estrutura global ```LCD```, definida no header ```lcd.h```. 
� necess�rio configurar os pinos de _enable_, _RS_ e os pinos de dados, al�m da porta onde est�o conectados.
At� o presente momento � necess�rio que todos os pinos estejam na mesma porta.

	LCD.enable = GPIO_PIN_0;
	LCD.rs = GPIO_PIN_1;
	LCD.pinos[0] = GPIO_PIN_5;
	LCD.pinos[1] = GPIO_PIN_6;
	LCD.pinos[2] = GPIO_PIN_7;
	LCD.pinos[3] = GPIO_PIN_8;
	LCD.porta = GPIOA;
	
Por �ltimo, chamamos a fun��o de inicializa��o, sem argumentos:
	
	init_display();

Ap�s isso, as seguintes fun��es estar�o dispon�veis:

	clear(void) // Limpa o display (cuidado, fun��o bastante lenta)
	printf(const char* format, ...) // mesmo printf da stdlib
	gotoxy(int x, int y) // move o cursor para dado ponto da tela

- - -

## Mini-exemplo (n�o testado)

	#include "stm32f4xx.h"
	#include "stm32f4xx_nucleo.h"
	
	#include "lcd.h"

	int main(void)
	{
		HAL_Init();
	
		// Configura��o e inicializa��o do display
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