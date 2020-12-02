rm admin.hex admin.o
avr-gcc -Os -Wall -DARM7 -DF_CPU=16000000UL -mmcu=atmega328p admin.c vm.c vmstack.c hal.c hal_Out.c bsl_COut.c bsl_xtoa.c -o admin.o
avr-objcopy -O ihex -j .text -j .data admin.o  admin.hex
avrdude -C "C:\Program Files (x86)\Arduino\hardware\tools\avr\etc\avrdude.conf" -c arduino -p atmega328p -b 57600 -P COM6 -D -Uflash:w:admin.hex:i
pause
