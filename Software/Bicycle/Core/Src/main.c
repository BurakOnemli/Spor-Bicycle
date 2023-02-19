#include "main.h"

#include "stm32l0xx_hal.h"
#include "systemclockconfig.h"
#include "adc.h"
#include "exti.h"
#include "gpio.h"
#include "measurements.h"
#include "timer.h"
#include "uart.h"

#define MIN_CYCLING_NUMBER 10
#define GREEN_LED_PIN GPIO_PIN_3
#define RED_LED_PIN GPIO_PIN_4
#define BUZZER_PIN GPIO_PIN_5
#define CHAR_BUFF_SIZE 10

static char * _float_to_char( float x, char *p );
void clearBuffer ( char* buff, size_t size );
bool connectedToPhone ( void );

volatile uint16_t countPerInterrupt = 0;
volatile uint8_t oneSecondIsOver = 0;
char BUFFER[CHAR_BUFF_SIZE];
int main(void)
{
	uint8_t tick = 0;
	uint8_t notGoingToSleep = 0;
	uint8_t readADC = 0;
	HAL_Init();
	SystemClock_Config();
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);
	//
	GPIO_Start_Output(GPIOB, GREEN_LED_PIN, LOW);
	GPIO_Start_Output(GPIOB, RED_LED_PIN, LOW);
	GPIO_Start_Output(GPIOB, BUZZER_PIN, LOW);

	GPIOA->MODER |= GPIO_MODER_MODE15_1; //PIN15 alternative RX
	GPIOA->MODER &= ~GPIO_MODER_MODE15_0;
	GPIOA->AFR[1] |= ( 4 << GPIO_AFRH_AFSEL15_Pos );


	ADC_calibrate(ADC1); // This is used to calibrate the ADC check reference manuel for more information
	ADC_init(ADC1);

	TIM_Start(TIM2);

	UART_init(USART2);
	GPIO_Write(GPIOB, GREEN_LED_PIN, GPIO_HIGH);
	GPIO_Write(GPIOB, RED_LED_PIN, GPIO_HIGH);
	while(connectedToPhone() != true);
	GPIO_Write(GPIOB, RED_LED_PIN, GPIO_LOW);
	GPIO_Write(GPIOB, GREEN_LED_PIN, GPIO_HIGH);

	while (1)
	{

		if(oneSecondIsOver == 1)
		{
			tick ^= tick;
			notGoingToSleep++;
			if(countPerInterrupt > MIN_CYCLING_NUMBER)
			{
				float speedAndDistance = calculateSpeedAndDistance(0.2, countPerInterrupt);
				clearBuffer(BUFFER, CHAR_BUFF_SIZE);
			    _float_to_char(speedAndDistance, BUFFER);
			    BUFFER[0] = 'S';
			    UART_write(USART2, BUFFER, CHAR_BUFF_SIZE);
				notGoingToSleep = 0;
			}
			if(notGoingToSleep >= 5) //System is not used by someone for a long time so the system should be the turned off
			{
				if(tick == 1)
					GPIO_Write(GPIOB, BUZZER_PIN, GPIO_HIGH);
				GPIO_Write(GPIOB, BUZZER_PIN, GPIO_LOW);

			}
			if(readADC == 60)
			{
				uint16_t ADC_reading = ADC_read(ADC1);
				float voltage =  (float)ADC_reading * 0.013; // 3.3 / 255 = 0.013
				readADC = 0;
				clearBuffer(BUFFER, CHAR_BUFF_SIZE);
				_float_to_char(voltage, BUFFER);
				BUFFER[0] = 'V';
				UART_write(USART2, BUFFER, CHAR_BUFF_SIZE);
			}
			readADC++;
			oneSecondIsOver = 0;
		}

	}
}

static char * _float_to_char ( float x, char *p )
{
    char *s = p + CHAR_BUFF_SIZE; // go to end of buffer
    uint16_t decimals;  // variable to store the decimals
    int units;  // variable to store the units (part to left of decimal place)
    if (x < 0) { // take care of negative numbers
        decimals = (int)(x * -100) % 100; // make 1000 for 3 decimals etc.
        units = (int)(-1 * x);
    } else { // positive numbers
        decimals = (int)(x * 100) % 100;
        units = (int)x;
    }

    *--s = (decimals % 10) + '0';
    decimals /= 10; // repeat for as many decimal places as you need
    *--s = (decimals % 10) + '0';
    *--s = '.';

    while (units > 0) {
        *--s = (units % 10) + '0';
        units /= 10;
    }
    if (x < 0) *--s = '-'; // unary minus sign for negative numbers
    return s;
}

void clearBuffer (char* buff, size_t size)
{
    for(int i = 0; i < size; i++)
    {
    	BUFFER[i] = 0;
    }
}

bool connectedToPhone ( void )
{
	while(UART_read(USART2) != 'O'); // Wait untill the device returns 'O'
	return true;
}


