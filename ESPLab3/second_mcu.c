#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void print_0()
{
    PORT_LED_A ^= (1<<LED_A);
    PORT_LED_B ^= (1<<LED_B);
    PORT_LED_C ^= (1<<LED_C);
    PORT_LED_D ^= (1<<LED_D);
    PORT_LED_E ^= (1<<LED_E);
    PORT_LED_F ^= (1<<LED_F);
}

void print_1()
{
    PORT_LED_B ^= (1<<LED_B);
    PORT_LED_C ^= (1<<LED_C);
}

void print_2()
{
    PORT_LED_A ^=(1<<LED_A);
    PORT_LED_B ^= (1<<LED_B);
    PORT_LED_D ^= (1<<LED_D);
    PORT_LED_E ^= (1<<LED_E);
    PORT_LED_G ^= (1<<LED_G);
}

void print_3()
{
    PORT_LED_A ^=(1<<LED_A);
    PORT_LED_B ^= (1<<LED_B);
    PORT_LED_C ^= (1<<LED_C);
    PORT_LED_D ^= (1<<LED_D);
    PORT_LED_G ^= (1<<LED_G);
}

void print_4()
{
    PORT_LED_B ^= (1<<LED_B);
    PORT_LED_C ^= (1<<LED_C);
    PORT_LED_F ^= (1<<LED_F);
    PORT_LED_G ^= (1<<LED_G);
}

void print_5()
{
    PORT_LED_A ^= (1<<LED_A);
    PORT_LED_C ^= (1<<LED_C);
    PORT_LED_D ^= (1<<LED_D);
    PORT_LED_F ^= (1<<LED_F);
    PORT_LED_G ^= (1<<LED_G);
}

void print_ERROR()
{
    PORT_LED_A ^= (1<<LED_A);
    PORT_LED_D ^= (1<<LED_D);
    PORT_LED_E ^= (1<<LED_E);
    PORT_LED_F ^= (1<<LED_F);
    PORT_LED_G ^= (1<<LED_G);
}

void clear()
{
    PORT_LED_A &= ~(1<<LED_A);
    PORT_LED_B &= ~(1<<LED_B);
    PORT_LED_C &= ~(1<<LED_C);
    PORT_LED_D &= ~(1<<LED_D);
    PORT_LED_E &= ~(1<<LED_E);
    PORT_LED_F &= ~(1<<LED_F);
    PORT_LED_G &= ~(1<<LED_G);

}

ISR(USART_RXC_vect){
    char digit =UDR;
    clear();
    switch(digit-'0'+1)
    {
        case 1:
            print_1();
            break;
        case 2:
            print_2();
            break;
        case 3:
            print_3();
            break;
        case 4:
            print_4();
            break;
        case 5:
            print_5();
            break;
        default:
            if(digit=='f')
                print_0();
            else
                print_ERROR();
    }
}

int main()
{
    //LED_A
    DDR_LED_A |= (1<<LED_A); // выход
    PORT_LED_A &= ~(1<<LED_A); // выключен

    //LED_B
    DDR_LED_B |= (1<<LED_B); // выход
    PORT_LED_B &= ~(1<<LED_B); // выключен

    //LED_A
    DDR_LED_C |= (1<<LED_C); // выход
    PORT_LED_C &= ~(1<<LED_C); // выключен

    //LED_A
    DDR_LED_D |= (1<<LED_D); // выход
    PORT_LED_D &= ~(1<<LED_D); // выключен

    //LED_A
    DDR_LED_E |= (1<<LED_E); // выход
    PORT_LED_E &= ~(1<<LED_E); // выключен

    //LED_F
    DDR_LED_F |= (1<<LED_F); // выход
    PORT_LED_F &= ~(1<<LED_F); // выключен

    //LED_F
    DDR_LED_G |= (1<<LED_G); // выход
    PORT_LED_G &= ~(1<<LED_G); // выключен

    //add customizing???????
    //USART Baud Rate Registers: скорость=частота_кварца/(16*битрейт -1)
    UBRRL=round(F_CPU/(16*9600-1.0));//103
    //USART Control and Status Register B: receiver enable, rx complete interrupt enable
	UCSRB=(1<<RXEN)|(1<<RXCIE);
    //USART Control and Status Register C:  register select, 8N1
	UCSRC=(1<<URSEL)|(3<<UCSZ0);

    sei(); 
    
    while(1)
    {}
}