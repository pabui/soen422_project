#include "bsl_indesc.h"

#include <avr/io.h>

static char RxChar() {
    char c;
    while (!(UCSR0A & (1 << RXC0)));
    c = UDR0;
    return c;
}

static void Console_Getchar(char c) { RxChar(); }

static void CIn_Init(void) {
    // baud rate
    UBRR0 = 103;

    // UART Receipt
    UCSR0B |= (1 << RXEN0);

    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

static void CIn_GetC(char c)        { Console_Getchar(c); }

static IVMInDesc cin = {
    CIn_GetC
};

static bool init = 0;

IIn In_GetFactory(const char* separate) {
    if (!init) {
        separate = 0;
        CIn_Init();
        init = true;
    }
    return &cin;
}
