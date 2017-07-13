#define F_CPU 16000000ul

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    
    DDRD |= (1<<DDD2); /* set PIND2 as ouput */
    DDRD |= (0<<DDD3); /* set PIND3 as input */
    PORTD |= (1<<PORTD2); /* turn the LED on at PIND2*/

    while (1) {
        if (PIND & (1<<PIND3)) { /* if PIND3 is high, turn LED off */
            /* PORTD &= ~(1<<PORTD2); */
            PIND |= (1<<PIND2);
            _delay_ms(300);
        }
    }
}
