#ifndef _REGISTERS_H_
#define _REGISTERS_H_

#include <cstdint>

// > for AVR ATmega32

namespace mcal {
    namespace reg {
        constexpr std::uint8_t SREG = UINT8_C(0x5F);
        constexpr std::uint8_t SPH = UINT8_C(0x5E);
        constexpr std::uint8_t SPL = UINT8_C(0x5D);
        constexpr std::uint8_t OCR0 = UINT8_C(0x5C);
        constexpr std::uint8_t GICR = UINT8_C(0x5B);
        constexpr std::uint8_t GIFR = UINT8_C(0x5A);
        constexpr std::uint8_t TIMSK = UINT8_C(0x59);
        constexpr std::uint8_t TIFR = UINT8_C(0x58);
        constexpr std::uint8_t SPMCR = UINT8_C(0x57);
        constexpr std::uint8_t TWCR = UINT8_C(0x56);
        constexpr std::uint8_t MCUCR = UINT8_C(0x55);
        constexpr std::uint8_t MCUCSR = UINT8_C(0x54);
        constexpr std::uint8_t TCCR0 = UINT8_C(0x53);
        constexpr std::uint8_t TCNT0 = UINT8_C(0x52);
        constexpr std::uint8_t OSCCAL = UINT8_C(0x51);
        constexpr std::uint8_t OCDR = UINT8_C(0x51);
        constexpr std::uint8_t SFIOR = UINT8_C(0x50);
        constexpr std::uint8_t TCCR1A = UINT8_C(0x4F);
        constexpr std::uint8_t TCCR1B = UINT8_C(0x4E);
        constexpr std::uint8_t TCNT1H = UINT8_C(0x4D);
        constexpr std::uint8_t TCNT1L = UINT8_C(0x4C);
        constexpr std::uint8_t OCR1AH = UINT8_C(0x4B);
        constexpr std::uint8_t OCR1AL = UINT8_C(0x4A);
        constexpr std::uint8_t OCR1BH = UINT8_C(0x49);
        constexpr std::uint8_t OCR1BL = UINT8_C(0x48);
        constexpr std::uint8_t ICR1H = UINT8_C(0x47);
        constexpr std::uint8_t ICR1L = UINT8_C(0x46);
        constexpr std::uint8_t TCCR2 = UINT8_C(0x45);
        constexpr std::uint8_t TCNT2 = UINT8_C(0x44);
        constexpr std::uint8_t OCR2 = UINT8_C(0x43);
        constexpr std::uint8_t ASSR = UINT8_C(0x42);
        constexpr std::uint8_t WDTCR = UINT8_C(0x41);
        constexpr std::uint8_t UBRRH = UINT8_C(0x40);
        constexpr std::uint8_t UCSRC = UINT8_C(0x40);
        constexpr std::uint8_t EEARH = UINT8_C(0x3F);
        constexpr std::uint8_t EEARL = UINT8_C(0x3E);
        constexpr std::uint8_t EEDR = UINT8_C(0x3D);
        constexpr std::uint8_t EECR = UINT8_C(0x3C);
        constexpr std::uint8_t PORTA = UINT8_C(0x3B);
        constexpr std::uint8_t DDRA = UINT8_C(0x3A);
        constexpr std::uint8_t PINA = UINT8_C(0x39);
        constexpr std::uint8_t PORTB = UINT8_C(0x38);
        constexpr std::uint8_t DDRB = UINT8_C(0x37);
        constexpr std::uint8_t PINB = UINT8_C(0x36);
        constexpr std::uint8_t PORTC = UINT8_C(0x35);
        constexpr std::uint8_t DDRC = UINT8_C(0x34);
        constexpr std::uint8_t PINC = UINT8_C(0x33);
        constexpr std::uint8_t PORTD = UINT8_C(0x32);
        constexpr std::uint8_t DDRD = UINT8_C(0x31);
        constexpr std::uint8_t PIND = UINT8_C(0x30);
        constexpr std::uint8_t SPDR = UINT8_C(0x2F);
        constexpr std::uint8_t SPSR = UINT8_C(0x2E);
        constexpr std::uint8_t SPCR = UINT8_C(0x2D);
        constexpr std::uint8_t UDR = UINT8_C(0x2C);
        constexpr std::uint8_t UCSRA = UINT8_C(0x2B);
        constexpr std::uint8_t UCSRB = UINT8_C(0x2A);
        constexpr std::uint8_t UBRRL = UINT8_C(0x29);
        constexpr std::uint8_t ACSR = UINT8_C(0x28);
        constexpr std::uint8_t ADMUX = UINT8_C(0x27);
        constexpr std::uint8_t ADCSRA = UINT8_C(0x26);
        constexpr std::uint8_t ADCH = UINT8_C(0x25);
        constexpr std::uint8_t ADCL = UINT8_C(0x24);
        constexpr std::uint8_t TWDR = UINT8_C(0x23);
        constexpr std::uint8_t TWAR = UINT8_C(0x22);
        constexpr std::uint8_t TWSR = UINT8_C(0x21);
        constexpr std::uint8_t TWBR = UINT8_C(0x20);

        // # Bit Position Values
        // Bit-position values.
        constexpr std::uint8_t bitPos0 = UINT8_C(1U << 0U);
        constexpr std::uint8_t bitPos1 = UINT8_C(1U << 1U);
        constexpr std::uint8_t bitPos2 = UINT8_C(1U << 2U);
        constexpr std::uint8_t bitPos3 = UINT8_C(1U << 3U);
        constexpr std::uint8_t bitPos4 = UINT8_C(1U << 4U);
        constexpr std::uint8_t bitPos5 = UINT8_C(1U << 5U);
        constexpr std::uint8_t bitPos6 = UINT8_C(1U << 6U);
        constexpr std::uint8_t bitPos7 = UINT8_C(1U << 7U);
    }  // namespace reg
}  // namespace mcal

#endif /* _REGISTERS_H_ */
