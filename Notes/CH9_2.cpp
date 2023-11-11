// > Low Level HW Drivers in C++

// # Programming Interrupts in C++

// Interrupt is an a synchronous signal caused by HW (Usually) or SW event
// (Sometimes) that indicates that a special ISR should execute

// Interrupts usually have higher CPU execution priority than the main function
// priority

// Writing an INT is usually consist of 3 steps:
// 1- Write it ISR
// 2- Put the ISR to the vector table
// 3- Initialize the INT module and Enable INT Enable and Global INT Enable

// ? How to Implement ISR
// 1- Declaration
extern "C" void __vector_timer() __attribute__((interrupt));
// 2- Definition
void __vector_timer(void) {
    // Do Anything
}

// Note: ISR syntax is highly compiler dependent
// As (__attribute__) is an extension for C/C++ by GNU

// ! Clearing the INT flag can be done by HW automatically and by SW manually

// * INT vtable is usually an Array of Pointer functions or a struct of function
// * pointers

// We Use extern "C" with Interrupts to get C-linkage to stop C++ name mangling
// for them

// Vtable is usually a HW and Compiler Dependent

// making nop operation
namespace mcal {
    namespace irq {
        // The no-operation.
        inline void nop() { asm volatile("nop"); }
    }  // namespace irq
}  // namespace mcal

// - Declaration
extern "C" void __unused_isr() __attribute__((interrupt));
// The unused interrupt handler.
// - Definition
extern "C" void __unused_isr() {
    // Generate a loud error. It could be made
    // even louder by toggling an I/O port.
    for(;;) {
        mcal::irq::nop();  // Hanging
    }
}

namespace {  // C-style code
    typedef struct struct_isr_type {
        typedef void (*function_type)();  // make type of function pointer
                                          // called function_type the function
                                          // returns void and take no args

        const unsigned char jmp[2];  // JMP instruction (0x940C): 0x0C = low
                                     // byte, 0x94 = high byte.
        const function_type func;    // The interrupt service routine.
    } isr_type;
}  // namespace

extern "C" void __my_startup()
    __attribute__((section(".startup"), used, noinline));
extern "C" void __vector_unused_irq()
    __attribute__((signal, used, externally_visible));
extern "C" void __vector_16() __attribute__((signal, used, externally_visible));

extern "C" const volatile isr_type isr_vectors[26U] = {
    {{0x0C, 0x94}, __my_startup},    // 1 reset
    {{0x0C, 0x94}, __unused_isr},    // 2 ext0
    {{0x0C, 0x94}, __unused_isr},    // 3 ext1
    {{0x0C, 0x94}, __unused_isr},    // 4 pin0
    {{0x0C, 0x94}, __unused_isr},    // 5 pin1
    {{0x0C, 0x94}, __unused_isr},    // 6 pin2
    {{0x0C, 0x94}, __unused_isr},    // 7 watchdog
    {{0x0C, 0x94}, __unused_isr},    // 8 timer2 cmp a
    {{0x0C, 0x94}, __unused_isr},    // 9 timer2 cmp b
    {{0x0C, 0x94}, __unused_isr},    // 10 timer2 ovf
    {{0x0C, 0x94}, __unused_isr},    // 11 timer1 cap
    {{0x0C, 0x94}, __unused_isr},    // 12 timer1 cmp a
    {{0x0C, 0x94}, __unused_isr},    // 13 timer1 cmp b
    {{0x0C, 0x94}, __unused_isr},    // 14 timer1 ovf
    {{0x0C, 0x94}, __vector_timer},  // 15 timer0 cmp a
    {{0x0C, 0x94}, __unused_isr},    // 16 timer0 cmp b
    {{0x0C, 0x94}, __unused_isr},    // 17 timer0 ovf
    {{0x0C, 0x94}, __unused_isr},    // 18 spi(TM)
    {{0x0C, 0x94}, __unused_isr},    // 19 usart rx
    {{0x0C, 0x94}, __unused_isr},    // 20 usart err
    {{0x0C, 0x94}, __unused_isr},    // 21 usart rx
    {{0x0C, 0x94}, __unused_isr},    // 22 adc
    {{0x0C, 0x94}, __unused_isr},    // 23 eep Ready
    {{0x0C, 0x94}, __unused_isr},    // 24 comparator
    {{0x0C, 0x94}, __unused_isr},    // 25 two-wire
    {{0x0C, 0x94}, __unused_isr}     // 26 spm
};


