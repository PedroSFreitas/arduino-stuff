PORT = /dev/ttyUSB0
MCU = atmega328p
BAUD = 57600
PROGRAMMER = arduino

SRC = user_main.c
OBJ = $(SRC:.c=.o)
HEX = $(SRC:.c=.hex)

CC = avr-gcc
CFLAGS = -Wall -Werror -pedantic -Os

compile: $(HEX)
	

$(HEX): $(OBJ)
	@avr-objcopy -O ihex $< $@

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -mmcu=$(MCU) $< -o $@

clean:
	@rm -rf $(HEX) $(OBJ)
	
flash:
	@avrdude -P $(PORT) -c $(PROGRAMMER) -p $(MCU) -b $(BAUD) -D -U flash:w:$(HEX):i

.PHONY: compile clean flash
