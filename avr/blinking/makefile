BAUD = 115200
MCU = atmega2560
PORT = /dev/ttyACM0
PROGRAMMER = wiring
DELAY = 200

CC = avr-gcc
CFLAGS = -Wall -Wextra -Werror -mmcu=$(MCU) -Os

TARGET = blinking
SRC = $(TARGET).c
OBJ = $(TARGET).o
HEX = $(TARGET).hex

compile: $(HEX)

$(HEX): $(OBJ)
	avr-objcopy -O ihex $< $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -D DELAY=$(DELAY) -o $@ $<

clean:
	@rm -vrf $(OBJ) $(HEX)

flash: $(HEX)
	@avrdude -v -p $(MCU) -P $(PORT) -D -U flash:w:$(HEX):i -c $(PROGRAMMER) -b $(BAUD)

.PHONY: compile clean flash
