/*
 * Exemplo 1: Manipulação Direta de Portas Digitais (PORTD / DDRD)
 * Disciplina: Sistemas Digitais - UniFG
 * Professor: Ciro Chaves
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Configura os pinos PD4 a PD7 como SAÍDA (1) e PD0 a PD3 como ENTRADA (0)
    // Palavra binária: 1111 0000 -> Hexadecimal: 0xF0
    DDRD = 0xF0;  //Fazendo sem a biblioteca avr, ou swja, em C puro => *(volatile unsigned char *)0x2A = 0xF0;

    // Garante que as saídas iniciem em nível BAIXO (0V)
    PORTD = 0x00;

    while (1) {
        // Liga as saídas PD4 a PD7 (Nível ALTO - 5V)
        // Palavra binária: 1111 0000 -> Hexadecimal: 0xF0
        PORTD = 0xF0;
        _delay_ms(500);

        // Desliga as saídas PD4 a PD7 (Nível BAIXO - 0V)
        // Palavra binária: 0000 0000 -> Hexadecimal: 0x00
        PORTD = 0x00;
        _delay_ms(500);
    }

    return 0;
}