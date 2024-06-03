#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <math.h> // Include math.h for the 'round' function

const int delay_mode[5] = { 9999, 5000, 1000, 600, 300 };
int current_speed = 2;
bool reverse_flag;
bool power_flag;

void delay()
{
    switch (current_speed) {
    case 0: _delay_ms(delay_mode[0]); break;
    case 1: _delay_ms(delay_mode[1]); break;
    case 2: _delay_ms(delay_mode[2]); break;
    case 3: _delay_ms(delay_mode[3]); break;
    case 4: _delay_ms(delay_mode[4]); break;
    }
}

void StepForward()
{
    if (!reverse_flag && power_flag)
    {
        PORT_STEPPER_PA ^= (1 << STEPPER_PA);
        PORT_STEPPER_PA &= ~(1 << STEPPER_PA);
        delay();
        if (!reverse_flag && power_flag)
        {
            PORT_STEPPER_PB ^= (1 << STEPPER_PB);
            PORT_STEPPER_PB &= ~(1 << STEPPER_PB);
            delay();
            if (!reverse_flag && power_flag)
            {
                PORT_STEPPER_NA ^= (1 << STEPPER_NA);
                PORT_STEPPER_NA &= ~(1 << STEPPER_NA);
                delay();
                if (!reverse_flag && power_flag)
                {
                    PORT_STEPPER_NB ^= (1 << STEPPER_NB);
                    PORT_STEPPER_NB &= ~(1 << STEPPER_NB);
                    delay();
                }
            }
        }
    }
}

void StepBackward()
{
    if (reverse_flag && power_flag)
    {
        PORT_STEPPER_NB ^= (1 << STEPPER_NB);
        PORT_STEPPER_NB &= ~(1 << STEPPER_NB);
        delay();
        if (reverse_flag && power_flag)
        {
            PORT_STEPPER_NA ^= (1 << STEPPER_NA);
            PORT_STEPPER_NA &= ~(1 << STEPPER_NA);
            delay();
            if (reverse_flag && power_flag)
            {
                PORT_STEPPER_PB ^= (1 << STEPPER_PB);
                PORT_STEPPER_PB &= ~(1 << STEPPER_PB);
                delay();
                if (reverse_flag && power_flag)
                {
                    PORT_STEPPER_PA ^= (1 << STEPPER_PA);
                    PORT_STEPPER_PA &= ~(1 << STEPPER_PA);
                    delay();
                }
            }
        }
    }
}

ISR(USART_RXC_vect)
{
    char input = UDR;
    switch (input)
    {
    case 's':
        if (!power_flag)
        {
            power_flag = true;
            UDR = current_speed + '0';
            PORT_ON ^= (1 << ON);
            if (reverse_flag)
                PORTREVERS ^= (1 << REVERS);
            else
                PORTREVERS &= ~(1 << REVERS);
        }
        break;
    case 'f':
        if (power_flag)
        {
            power_flag = false;
            UDR = 'f';
            PORT_ON &= ~(1 << ON);
            PORTREVERS &= ~(1 << REVERS);
        }
        break;
    case 'r':
        if (power_flag)
        {
            reverse_flag = !reverse_flag;
            if (reverse_flag)
                PORTREVERS ^= (1 << REVERS);
            else
                PORTREVERS &= ~(1 << REVERS);
        }
        break;
    default:
        break;
    }
}

bool debounce(uint8_t pin, uint8_t bit)
{
    if (!(pin & (1 << bit))) // Проверка, нажата ли кнопка
    {
        _delay_ms(50); // Задержка для подавления дребезга
        if (!(pin & (1 << bit))) // Проверка снова после задержки
        {
            return true;
        }
    }
    return false;
}

int main()
{
    reverse_flag = false;
    power_flag = false;

    // up button
    DDR_BUTTON_UP &= ~(1 << BUTTON_UP); // вход
    PORT_BUTTON_UP |= (1 << BUTTON_UP); // подтяжка

    // down button
    DDR_BUTTON_DOWN &= ~(1 << BUTTON_DOWN); // вход
    PORT_BUTTON_DOWN |= (1 << BUTTON_DOWN); // подтяжка

    DDR_ON |= (1 << ON); // выход
    PORT_ON &= ~(1 << ON); // выключен

    DDRREVERS |= (1 << REVERS); // выход
    PORTREVERS &= ~(1 << REVERS); // выключен

    // stepper positive A
    DDR_STEPPER_PA |= (1 << STEPPER_PA); // выход
    PORT_STEPPER_PA &= ~(1 << STEPPER_PA); // выключен

    // stepper positive B
    DDR_STEPPER_PB |= (1 << STEPPER_PB); // выход
    PORT_STEPPER_PB &= ~(1 << STEPPER_PB); // выключен

    // stepper negative A
    DDR_STEPPER_NA |= (1 << STEPPER_NA); // выход
    PORT_STEPPER_NA &= ~(1 << STEPPER_NA); // выключен

    // stepper negative B
    DDR_STEPPER_NB |= (1 << STEPPER_NB); // выход
    PORT_STEPPER_NB &= ~(1 << STEPPER_NB); // выключен

    // USART Baud Rate Registers: скорость=частота_кварца/(16*битрейт -1)
    UBRRL = round(F_CPU / (16 * 9600 - 1.0)); //103
    // USART Control and Status Register B: transmitter enable, receiver enable, rx complete interrupt enable
    UCSRB = (1 << TXEN) | (1 << RXEN) | (1 << RXCIE);
    // USART Control and Status Register C: register select, 8N1
    UCSRC = (1 << URSEL) | (3 << UCSZ0);

    UDR = 'f';

    sei();

    while (1)
    {
        while (power_flag)
        {
            if (debounce(PIN_BUTTON_UP, BUTTON_UP)) // up
            {
                current_speed = current_speed + 1 < 5 ? current_speed + 1 : 4;
                UDR = current_speed + '0';
                _delay_ms(200); // Дополнительная задержка для предотвращения повторных нажатий
            }

            if (debounce(PIN_BUTTON_DOWN, BUTTON_DOWN)) // down
            {
                current_speed = current_speed - 1 > 0 ? current_speed - 1 : 0;
                UDR = current_speed + '0';
                _delay_ms(200); // Дополнительная задержка для предотвращения повторных нажатий
            }

            if (reverse_flag)
                StepBackward();
            else
                StepForward();
        }
        while (!(UCSRA & (1 << UDRE))) {};
    }
}
