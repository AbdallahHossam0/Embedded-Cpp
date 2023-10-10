#include "Reg_Access.h"
#include "cstdint.h"
#include "dio.h"
#include "registers.h"

extern int wait(void);

int main(void) {
    using D0 = DIO<std::uint8_t, std::uint8_t, mcal::reg::PORTD, UINT8_C(0x00)>;
    D0::setPinHigh();
    D0::setDirectionOutput();
    int v{wait()};
    for(;;) {
        for(uint32_t i{static_cast<uint32_t>(v)}; i < 0xFF'FF; ++i) {
            continue;
        }
        D0::setPinLow();
        for(uint32_t i{}; i < 0xFF'FF; ++i) {
            continue;
        }
        D0::setPinHigh();
    }
}
