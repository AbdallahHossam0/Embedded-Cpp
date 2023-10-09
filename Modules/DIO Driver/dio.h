#ifndef _DIO_H_
#define _DIO_H_

#include "../Reg_Access.h"
#include "../registers.h"

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

#endif /* _DIO_H_ */
