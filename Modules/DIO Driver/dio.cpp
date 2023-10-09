#include "dio.h"

template<typename AddrType, typename RegType, const AddrType addr,
         const RegType pin>
void DIO<AddrType, RegType, addr, pin>::setDirectionOutput(void) {
    mcal::reg::RegStaticAccess<AddrType, RegType, addr - 1, pin>::bitSet();
}

template<typename AddrType, typename RegType, const AddrType addr,
         const RegType pin>
void DIO<AddrType, RegType, addr, pin>::setDirectionInput(void) {
    mcal::reg::RegStaticAccess<AddrType, RegType, addr - 1, pin>::bitClear();
}

template<typename AddrType, typename RegType, const AddrType addr,
         const RegType pin>
void DIO<AddrType, RegType, addr, pin>::enablePullUpRes(void) {
    mcal::reg::RegStaticAccess<AddrType, RegType, addr - 2, pin>::bitSet();
}

template<typename AddrType, typename RegType, const AddrType addr,
         const RegType pin>
void DIO<AddrType, RegType, addr, pin>::setPinHigh(void) {
    mcal::reg::RegStaticAccess<AddrType, RegType, addr, pin>::bitSet();
}

template<typename AddrType, typename RegType, const AddrType addr,
         const RegType pin>
void DIO<AddrType, RegType, addr, pin>::setPinLow(void) {
    mcal::reg::RegStaticAccess<AddrType, RegType, addr, pin>::bitClear();
}

template<typename AddrType, typename RegType, const AddrType addr,
         const RegType pin>
void DIO<AddrType, RegType, addr, pin>::toggle(void) {
    mcal::reg::RegStaticAccess<AddrType, RegType, addr, pin>::bitNot();
}

template<typename AddrType, typename RegType, const AddrType addr,
         const RegType pin>
bool DIO<AddrType, RegType, addr, pin>::readInputValue(void) {
    return mcal::reg::RegStaticAccess<AddrType, RegType, addr, pin>::bitGet();
}

template<typename AddrType, typename RegType, const AddrType addr,
         const RegType pin>
bool DIO<AddrType, RegType, addr, pin>::isPinOutput(void) {
    return mcal::reg::RegStaticAccess<AddrType, RegType, addr - 1,
                                      pin>::bitGet();
}
