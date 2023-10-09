#ifndef _REGISTERS_H_
#define _REGISTERS_H_

#include <cstdint>

// > for AVR ATmega32

namespace mcal {
    namespace reg {
        constexpr std::uint8_t SREG = (0x5F);
        constexpr std::uint8_t SPH = (0x5E);
        constexpr std::uint8_t SPL = (0x5D);
        constexpr std::uint8_t OCR0 = (0x5C);
        constexpr std::uint8_t GICR = (0x5B);
        constexpr std::uint8_t GIFR = (0x5A);
        constexpr std::uint8_t TIMSK = (0x59);
        constexpr std::uint8_t TIFR = (0x58);
        constexpr std::uint8_t SPMCR = (0x57);
        constexpr std::uint8_t TWCR = (0x56);
        constexpr std::uint8_t MCUCR = (0x55);
        constexpr std::uint8_t MCUCSR = (0x54);
        constexpr std::uint8_t TCCR0 = (0x53);
        constexpr std::uint8_t TCNT0 = (0x52);
        constexpr std::uint8_t OSCCAL = (0x51);
        constexpr std::uint8_t OCDR = (0x51);
        constexpr std::uint8_t SFIOR = (0x50);
        constexpr std::uint8_t TCCR1A = (0x4F);
        constexpr std::uint8_t TCCR1B = (0x4E);
        constexpr std::uint8_t TCNT1H = (0x4D);
        constexpr std::uint8_t TCNT1L = (0x4C);
        constexpr std::uint8_t OCR1AH = (0x4B);
        constexpr std::uint8_t OCR1AL = (0x4A);
        constexpr std::uint8_t OCR1BH = (0x49);
        constexpr std::uint8_t OCR1BL = (0x48);
        constexpr std::uint8_t ICR1H = (0x47);
        constexpr std::uint8_t ICR1L = (0x46);
        constexpr std::uint8_t TCCR2 = (0x45);
        constexpr std::uint8_t TCNT2 = (0x44);
        constexpr std::uint8_t OCR2 = (0x43);
        constexpr std::uint8_t ASSR = (0x42);
        constexpr std::uint8_t WDTCR = (0x41);
        constexpr std::uint8_t UBRRH = (0x40);
        constexpr std::uint8_t UCSRC = (0x40);
        constexpr std::uint8_t EEARH = (0x3F);
        constexpr std::uint8_t EEARL = (0x3E);
        constexpr std::uint8_t EEDR = (0x3D);
        constexpr std::uint8_t EECR = (0x3C);
        constexpr std::uint8_t PORTA = (0x3B);
        constexpr std::uint8_t DDRA = (0x3A);
        constexpr std::uint8_t PINA = (0x39);
        constexpr std::uint8_t PORTB = (0x38);
        constexpr std::uint8_t DDRB = (0x37);
        constexpr std::uint8_t PINB = (0x36);
        constexpr std::uint8_t PORTC = (0x35);
        constexpr std::uint8_t DDRC = (0x34);
        constexpr std::uint8_t PINC = (0x33);
        constexpr std::uint8_t PORTD = (0x32);
        constexpr std::uint8_t DDRD = (0x31);
        constexpr std::uint8_t PIND = (0x30);
        constexpr std::uint8_t SPDR = (0x2F);
        constexpr std::uint8_t SPSR = (0x2E);
        constexpr std::uint8_t SPCR = (0x2D);
        constexpr std::uint8_t UDR = (0x2C);
        constexpr std::uint8_t UCSRA = (0x2B);
        constexpr std::uint8_t UCSRB = (0x2A);
        constexpr std::uint8_t UBRRL = (0x29);
        constexpr std::uint8_t ACSR = (0x28);
        constexpr std::uint8_t ADMUX = (0x27);
        constexpr std::uint8_t ADCSRA = (0x26);
        constexpr std::uint8_t ADCH = (0x25);
        constexpr std::uint8_t ADCL = (0x24);
        constexpr std::uint8_t TWDR = (0x23);
        constexpr std::uint8_t TWAR = (0x22);
        constexpr std::uint8_t TWSR = (0x21);
        constexpr std::uint8_t TWBR = (0x20);

        // # Bit Position Values
        // Bit-position values.
        constexpr std::uint8_t bit0 = 1U;
        constexpr std::uint8_t bit1 = 1U << 1U;
        constexpr std::uint8_t bit2 = 1U << 2U;
        constexpr std::uint8_t bit3 = 1U << 3U;
        constexpr std::uint8_t bit4 = 1U << 4U;
        constexpr std::uint8_t bit5 = 1U << 5U;
        constexpr std::uint8_t bit6 = 1U << 6U;
        constexpr std::uint8_t bit7 = 1U << 7U;
    }  // namespace reg
}  // namespace mcal

#endif /* _REGISTERS_H_ */
