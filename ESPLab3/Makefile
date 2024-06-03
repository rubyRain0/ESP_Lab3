include configuration.mk

OBJCOPY=avr-objcopy
CC=avr-gcc

ifeq ($(findstring B, ${ON}), B)
    PORT_ON=PORTB
    DDR_ON=DDRB
else
    ifeq ($(findstring C, ${ON}), C)
        PORT_ON=PORTC
        DDR_ON=DDRC
    else
        PORT_ON=PORTD
        DDR_ON=DDRD
    endif
endif

ifeq ($(findstring B, ${REVERS}), B)
    PORTREVERS=PORTB
    DDRREVERS=DDRB
else
    ifeq ($(findstring C, ${REVERS}), C)
        PORTREVERS=PORTC
        DDRREVERS=DDRC
    else
        PORTREVERS=PORTD
        DDRREVERS=DDRD
    endif
endif

ifeq ($(findstring B, ${STEPPER_PA}), B)
    PORT_STEPPER_PA=PORTB
    DDR_STEPPER_PA=DDRB
else
    ifeq ($(findstring C, ${STEPPER_PA}), C)
        PORT_STEPPER_PA=PORTC
        DDR_STEPPER_PA=DDRC
    else
        PORT_STEPPER_PA=PORTD
        DDR_STEPPER_PA=DDRD
    endif
endif

ifeq ($(findstring B, ${STEPPER_PB}), B)
    PORT_STEPPER_PB=PORTB
    DDR_STEPPER_PB=DDRB
else
    ifeq ($(findstring C, ${STEPPER_PB}), C)
        PORT_STEPPER_PB=PORTC
        DDR_STEPPER_PB=DDRC
    else
        PORT_STEPPER_PB=PORTD
        DDR_STEPPER_PB=DDRD
    endif
endif

ifeq ($(findstring B, ${STEPPER_NA}), B)
    PORT_STEPPER_NA=PORTB
    DDR_STEPPER_NA=DDRB
else
    ifeq ($(findstring C, ${STEPPER_NA}), C)
        PORT_STEPPER_NA=PORTC
        DDR_STEPPER_NA=DDRC
    else
        PORT_STEPPER_NA=PORTD
        DDR_STEPPER_NA=DDRD
    endif
endif

ifeq ($(findstring B, ${STEPPER_NB}), B)
    PORT_STEPPER_NB=PORTB
    DDR_STEPPER_NB=DDRB
else
    ifeq ($(findstring C, ${STEPPER_NB}), C)
        PORT_STEPPER_NB=PORTC
        DDR_STEPPER_NB=DDRC
    else
        PORT_STEPPER_NB=PORTD
        DDR_STEPPER_NB=DDRD
    endif
endif

ifeq ($(findstring B, ${LED_A}), B)
    PORT_LED_A=PORTB
    DDR_LED_A=DDRB
else
    ifeq ($(findstring C, ${LED_A}), C)
        PORT_LED_A=PORTC
        DDR_LED_A=DDRC
    else
        PORT_LED_A=PORTD
        DDR_LED_A=DDRD
    endif
endif

ifeq ($(findstring B, ${LED_B}), B)
    PORT_LED_B=PORTB
    DDR_LED_B=DDRB
else
    ifeq ($(findstring C, ${LED_B}), C)
        PORT_LED_B=PORTC
        DDR_LED_B=DDRC
    else
        PORT_LED_B=PORTD
        DDR_LED_B=DDRD
    endif
endif

ifeq ($(findstring B, ${LED_C}), B)
    PORT_LED_C=PORTB
    DDR_LED_C=DDRB
else
    ifeq ($(findstring C, ${LED_C}), C)
        PORT_LED_C=PORTC
        DDR_LED_C=DDRC
    else
        PORT_LED_C=PORTD
        DDR_LED_C=DDRD
    endif
endif

ifeq ($(findstring B, ${LED_D}), B)
    PORT_LED_D=PORTB
    DDR_LED_D=DDRB
else
    ifeq ($(findstring C, ${LED_D}), C)
        PORT_LED_D=PORTC
        DDR_LED_D=DDRC
    else
        PORT_LED_D=PORTD
        DDR_LED_D=DDRD
    endif
endif

ifeq ($(findstring B, ${LED_E}), B)
    PORT_LED_E=PORTB
    DDR_LED_E=DDRB
else
    ifeq ($(findstring C, ${LED_E}), C)
        PORT_LED_E=PORTC
        DDR_LED_E=DDRC
    else
        PORT_LED_E=PORTD
        DDR_LED_E=DDRD
    endif
endif

ifeq ($(findstring B, ${LED_F}), B)
    PORT_LED_F=PORTB
    DDR_LED_F=DDRB
else
    ifeq ($(findstring C, ${LED_F}), C)
        PORT_LED_F=PORTC
        DDR_LED_F=DDRC
    else
        PORT_LED_F=PORTD
        DDR_LED_F=DDRD
    endif
endif

ifeq ($(findstring B, ${LED_G}), B)
    PORT_LED_G=PORTB
    DDR_LED_G=DDRB
else
    ifeq ($(findstring C, ${LED_G}), C)
        PORT_LED_G=PORTC
        DDR_LED_G=DDRC
    else
        PORT_LED_G=PORTD
        DDR_LED_G=DDRD
    endif
endif

ifeq ($(findstring B, ${BUTTON_UP}), B)
    PORT_BUTTON_UP = PORTB
    DDR_BUTTON_UP = DDRB
    PIN_BUTTON_UP = PINB
else ifeq ($(findstring C, ${BUTTON_UP}), C)
    PORT_BUTTON_UP = PORTC
    DDR_BUTTON_UP = DDRC
    PIN_BUTTON_UP = PINC
else ifeq ($(findstring D, ${BUTTON_UP}), D)
    PORT_BUTTON_UP = PORTD
    DDR_BUTTON_UP = DDRD
    PIN_BUTTON_UP = PIND
endif

ifeq ($(findstring B, ${BUTTON_DOWN}), B)
    PORT_BUTTON_DOWN = PORTB
    DDR_BUTTON_DOWN = DDRB
    PIN_BUTTON_DOWN = PINB
else ifeq ($(findstring C, ${BUTTON_DOWN}), C)
    PORT_BUTTON_DOWN = PORTC
    DDR_BUTTON_DOWN = DDRC
    PIN_BUTTON_DOWN = PINC
else ifeq ($(findstring D, ${BUTTON_DOWN), D)
    PORT_BUTTON_DOWN = PORTD
    DDR_BUTTON_DOWN = DDRD
    PIN_BUTTON_DOWN = PIND
endif

CFLAGS_main= -std=c99 -Wall -g -Os -mmcu=${MAIN_MCU} -DF_CPU=${F_CPU} \
    -DREVERS=P${REVERS} -DPORTREVERS=${PORTREVERS} -DDDRREVERS=${DDRREVERS} \
    -DON=P${ON} -DPORT_ON=${PORT_ON} -DDDR_ON=${DDR_ON} \
    -DSTEPPER_PA=P${STEPPER_PA} -DPORT_STEPPER_PA=${PORT_STEPPER_PA} -DDDR_STEPPER_PA=${DDR_STEPPER_PA} \
    -DSTEPPER_PB=P${STEPPER_PB} -DPORT_STEPPER_PB=${PORT_STEPPER_PB} -DDDR_STEPPER_PB=${DDR_STEPPER_PB} \
    -DSTEPPER_NA=P${STEPPER_NA} -DPORT_STEPPER_NA=${PORT_STEPPER_NA} -DDDR_STEPPER_NA=${DDR_STEPPER_NA} \
    -DSTEPPER_NB=P${STEPPER_NB} -DPORT_STEPPER_NB=${PORT_STEPPER_NB} -DDDR_STEPPER_NB=${DDR_STEPPER_NB} \
    -DBUTTON_UP=P${BUTTON_UP} -DPORT_BUTTON_UP=${PORT_BUTTON_UP} -DDDR_BUTTON_UP=${DDR_BUTTON_UP} -DPIN_BUTTON_UP=${PIN_BUTTON_UP} \
    -DBUTTON_DOWN=P${BUTTON_DOWN} -DPORT_BUTTON_DOWN=${PORT_BUTTON_DOWN} -DDDR_BUTTON_DOWN=${DDR_BUTTON_DOWN} -DPIN_BUTTON_DOWN=${PIN_BUTTON_DOWN}

TARGET_main=main_mcu
SRC_main=main_mcu.c

CFLAGS_second= -std=c99 -Wall -g -Os -mmcu=${SECOND_MCU} -DF_CPU=${F_CPU} \
        -DLED_A=P${LED_A} -DPORT_LED_A=${PORT_LED_A} -DDDR_LED_A=${DDR_LED_A}\
        -DLED_B=P${LED_B} -DPORT_LED_B=${PORT_LED_B} -DDDR_LED_B=${DDR_LED_B}\
        -DLED_C=P${LED_C} -DPORT_LED_C=${PORT_LED_C} -DDDR_LED_C=${DDR_LED_C}\
        -DLED_D=P${LED_D} -DPORT_LED_D=${PORT_LED_D} -DDDR_LED_D=${DDR_LED_D}\
        -DLED_E=P${LED_E} -DPORT_LED_E=${PORT_LED_E} -DDDR_LED_E=${DDR_LED_E}\
        -DLED_F=P${LED_F} -DPORT_LED_F=${PORT_LED_F} -DDDR_LED_F=${DDR_LED_F}\
        -DLED_G=P${LED_G} -DPORT_LED_G=${PORT_LED_G} -DDDR_LED_G=${DDR_LED_G}\

TARGET_second=second_mcu
SRC_second=second_mcu.c

all:
	${CC} ${CFLAGS_main} -o ${TARGET_main}.bin ${SRC_main}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET_main}.bin ${TARGET_main}.hex

	${CC} ${CFLAGS_second} -o ${TARGET_second}.bin ${SRC_second}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET_second}.bin ${TARGET_second}.hex
