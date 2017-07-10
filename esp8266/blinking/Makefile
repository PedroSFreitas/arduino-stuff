CC = xtensa-lx106-elf-gcc
CFLAGS = -I. -mlongcalls -Wall -pedantic
LDLIBS = -nostdlib -Wl,--start-group -lmain -lnet80211 -lwpa -llwip -lpp -lphy -lc -Wl,--end-group -lgcc
LDFLAGS = -Teagle.app.v6.ld

BAUD = 921600

blink-0x00000.bin: blink
	@echo "[*] Converting binary."
	@esptool elf2image $^

blink: blink.o

blink.o: blink.c

flash: blink-0x00000.bin blink-0x10000.bin
	@echo "[*] Flashing program."
	@echo "[*] At speed of: ${BAUD}"
	@esptool -b ${BAUD} write_flash 0 blink-0x00000.bin 0x10000 blink-0x10000.bin

clean:
	@echo "[*] Removing files."
	@rm -fv blink blink.o *.bin
