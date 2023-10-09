#ifndef __REG_ACCESS_H_
#define __REG_ACCESS_H_

namespace mcal {
    namespace reg {
        // # RegStaticAccess
        template<typename AddrType, typename RegType, const AddrType addr,
                 const RegType val>
        struct RegStaticAccess final {
            static RegType regGet(void) {
                return static_cast<RegType>(
                    *reinterpret_cast<volatile RegType*>(addr));
            }

            static void regSet(void) {
                *reinterpret_cast<volatile RegType*>(addr) = val;
            }

            static void regOr(void) {
                *reinterpret_cast<volatile RegType*>(addr) |= val;
            }

            static void regAnd(void) {
                *reinterpret_cast<volatile RegType*>(addr) &= val;
            }

            template<const RegType maskValue>
            static void regMsk(void) {
                *reinterpret_cast<volatile RegType*>(addr) =
                    static_cast<RegType>(
                        static_cast<RegType>(regGet & (~maskValue)) |
                        static_cast<RegType>(value & maskValue));
            }

            static void bitNot(void) {
                *reinterpret_cast<volatile RegType*>(addr) ^=
                    static_cast<RegType>(1U << val);
            }

            static void bitSet(void) {
                *reinterpret_cast<volatile RegType*>(addr) |=
                    static_cast<RegType>(1U << val);
            }

            static void bitClear(void) {
                *reinterpret_cast<volatile RegType*>(addr) &=
                    ~static_cast<RegType>(1U << val);
            }

            static bool bitGet(void) {
                return static_cast<bool>(
                    *reinterpret_cast<volatile RegType*>(addr) &
                    static_cast<RegType>(1U << val));
            }

            static bool bitIsSet(void) {
                return static_cast<bool>(
                    *reinterpret_cast<volatile RegType*>(addr) &
                    static_cast<RegType>(1U << val));
            }

            static bool bitIsClear(void) {
                return !static_cast<bool>(
                    *reinterpret_cast<volatile RegType*>(addr) &
                    static_cast<RegType>(1U << val));
            }
        };
        // # RegDynamicAccess
        template<typename AddrType, typename RegType>
        struct RegDynamicAccess final {
            static RegType regGet(const AddrType address) {
                return *reinterpret_cast<volatile RegType*>(address);
            }

            static void reg_set(const AddrType address, const RegType value) {
                *reinterpret_cast<volatile RegType*>(address) = value;
            }

            static void reg_and(const AddrType address, const RegType value) {
                *reinterpret_cast<volatile RegType*>(address) &= value;
            }

            static void reg_or(const AddrType address, const RegType value) {
                *reinterpret_cast<volatile RegType*>(address) |= value;
            }

            static void reg_msk(const AddrType address, const RegType value,
                                const RegType maskValue) {
                *reinterpret_cast<volatile RegType*>(address) =
                    static_cast<RegType>((regGet(address) & (~maskValue)) |
                                         (value & maskValue));
            }

            static void bitSet(const AddrType address, const RegType value) {
                *reinterpret_cast<volatile RegType*>(address) |=
                    static_cast<RegType>(1U << value);
            }

            static void bitClear(const AddrType address, const RegType value) {
                *reinterpret_cast<volatile RegType*>(address) &=
                    static_cast<RegType>(~static_cast<RegType>(1U << value));
            }

            static void bitNot(const AddrType address, const RegType value) {
                *reinterpret_cast<volatile RegType*>(address) ^=
                    static_cast<RegType>(1U << value);
            }

            static bool bitGet(const AddrType address, const RegType value) {
                return static_cast<bool>(regGet(address) &
                                         static_cast<RegType>(1U << value));
            }
            static bool bitIsSet(const AddrType address, const RegType value) {
                return static_cast<bool>(bitGet(address, value));
            }
            static bool bitIsClear(const AddrType address,
                                   const RegType value) {
                return static_cast<bool>(!bitGet(address, value));
            }
        };

    }  // namespace reg
}  // namespace mcal

#endif /* __REG_ACCESS_H_ */
