#define F_CPU 16000000UL

#ifndef DELAY
#define DELAY 200u
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1<<PORTB7);
    while (1) {
        PINB |= (1<<PINB7);
        _delay_ms(DELAY);
    }
}
