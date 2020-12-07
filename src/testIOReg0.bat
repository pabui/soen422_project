rm bsl_TestIOReg0.o  bsl_TestIOReg0.hex
avr-gcc -Os -Wall -D ARM7 -DF_CPU=16000000UL -mmcu=atmega328p bsl_TestIOReg0.c bsl_IOReg.c hal.c hal_Out.c bsl_COut.c bsl_xtoa.c -o bsl_TestIOReg0.o
avr-objcopy -O ihex -j .text -j .data bsl_TestIOReg0.o  bsl_TestIOReg0.hex
avrdude  -C "C:\Program Files (x86)\Arduino\hardware\tools\avr\etc\avrdude.conf" -c arduino -p atmega328p -b 57600 -P COM6 -D -Uflash:w:bsl_TestIOReg0.hex:i
pause
