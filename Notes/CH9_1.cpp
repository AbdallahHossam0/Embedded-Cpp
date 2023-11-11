// > Low Level HW Drivers in C++

// DIO Driver

// I/O ports can be controller 3 regs:
// 1-   Direction reg
// 2-   I/P data reg
// 3-   O/P data reg

// # Design of the Driver

template<typename AddrType, typename RegType, const AddrType addr,
         const RegType pin>
class DIO {
   public:
    static void setDirectionOutput(void);
    static void setDirectionInput(void);
    static void enablePullUpRes(void);
    static void setPinHigh(void);
    static void setPinLow(void);
    static void toggle(void);
    static bool readInputValue(void);
    static bool isPinOutput(void);
};

#include <cstdint>
#define PORTB 5
// ?How to use it?
void test(void) {
    using pinD4 = DIO<uint8_t, uint8_t, PORTB, UINT8_C(0)>;
    pinD4::setPinHigh();
    pinD4::setDirectionOutput();
    // set the pin to High before setting its direction to output to avoid
    // spikes ^^
}

// todo: It is recommended to ensure that pin is output before setting the logic
// todo: level.
