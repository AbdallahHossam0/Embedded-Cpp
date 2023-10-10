#ifndef _DIO_H_
#define _DIO_H_

#include "Reg_Access.h"
#include "registers.h"

template<typename AddrType, typename RegType, const AddrType addr,
         const RegType pin>
class DIO {
   public:
    static void setDirectionOutput(void) {
        mcal::reg::RegStaticAccess<AddrType, RegType, addr - 1, pin>::bitSet();
    }
    static void setDirectionInput(void) {
        mcal::reg::RegStaticAccess<AddrType, RegType, addr - 1,
                                   pin>::bitClear();
    }
    static void enablePullUpRes(void) {
        mcal::reg::RegStaticAccess<AddrType, RegType, addr - 2, pin>::bitSet();
    }
    static void setPinHigh(void) {
        mcal::reg::RegStaticAccess<AddrType, RegType, addr, pin>::bitSet();
    }
    static void setPinLow(void) {
        mcal::reg::RegStaticAccess<AddrType, RegType, addr, pin>::bitClear();
    }
    static void toggle(void) {
        mcal::reg::RegStaticAccess<AddrType, RegType, addr, pin>::bitNot();
    }
    static bool readInputValue(void) {
        return mcal::reg::RegStaticAccess<AddrType, RegType, addr - 2,
                                          pin>::bitGet();
    }
    static bool isPinOutput(void) {
        return mcal::reg::RegStaticAccess<AddrType, RegType, addr - 1,
                                          pin>::bitGet();
    }
};

#endif /* _DIO_H_ */
