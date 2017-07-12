BAUD = 115200
MCU = atmega2560
PORT = /dev/ttyACM0
TARGET = blinking
SOURCE = ${TARGET}.c
PROGRAMMER = wiring
DELAY = 200

CC = avr-gcc
CFLAGS = -Wall -Wextra -Werror -mmcu=${MCU} -Os

all: ${TARGET}.hex

${TARGET}.hex: ${TARGET}.o
	@avr-objcopy -O ihex $< $@

${TARGET}.o: ${SOURCE}
	@${CC} ${CFLAGS} -D DELAY=${DELAY} -o $@ $<

clean: ${TARGET}.o ${TARGET}.hex
	@rm -vrf ${TARGET}.o ${TARGET}.hex

flash: ${TARGET}.hex
	@avrdude -v -p ${MCU} -P ${PORT} -D -U flash:w:${TARGET}.hex:i -c ${PROGRAMMER} -b ${BAUD}

.PHONY: clean all flash
