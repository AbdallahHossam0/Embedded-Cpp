// > Accessing MicroController Register

#include <cstdint>

// How to access a reg in C++
namespace mcal {
    namespace reg {
        constexpr std::uint8_t portB{UINT8_C(0x25)};
    }
}  // namespace mcal

// OR

namespace mcal {
    struct reg0 {
        static constexpr std::uint8_t portA{UINT8_C(0x22)};
    };
}  // namespace mcal

// TO access it, Do The following

void doSomething(void) {
    *reinterpret_cast<volatile uint8_t*>(mcal::reg0::portA) = UINT8_C(0);
}

// # I prefer namespaces rather than struct

// ! RegStaticAccess is used for Addresses and Values known at compile-time only
// ! RegDynamicAccess is used for Addresses and Values will be known at runtime
// # RegStaticAccess
template<typename AddrType, typename RegType, const AddrType addr,
         const RegType val>
struct RegStaticAccess final {
    static RegType regGet(void) {
        return static_cast<RegType>(*reinterpret_cast<volatile RegType*>(addr));
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
    template<const RegType mask_value>
    static void reg_msk() {
        *reinterpret_cast<volatile register_value_type*>(address) =
            register_value_type(
                register_value_type(reg_get() &
                                    register_value_type(~mask_value)) |
                register_value_type(value & mask_value));
    }
    template<const RegType maskValue>
    static void regMsk(void) {
        *reinterpret_cast<volatile RegType*>(addr) =
            static_cast<RegType>(static_cast<RegType>(regGet & (~maskValue)) |
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
        return static_cast<bool>(*reinterpret_cast<volatile RegType*>(addr) &
                                 static_cast<RegType>(1U << val));
    }
    static bool bitIsSet(void) {
        return static_cast<bool>(*reinterpret_cast<volatile RegType*>(addr) &
                                 static_cast<RegType>(1U << val));
    }
    static bool bitIsClear(void) {
        return !static_cast<bool>(*reinterpret_cast<volatile RegType*>(addr) &
                                  static_cast<RegType>(1U << val));
    }
};

// How to use this RegStaticAccess
void doSomething1(void) {
    RegStaticAccess<std::uint8_t, std::uint8_t, mcal::reg::portB,
                    UINT8_C(0x00)>::regSet;
}

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
        *reinterpret_cast<volatile RegType*>(address) = static_cast<RegType>(
            (regGet(address) & (~maskValue)) | (value & maskValue));
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
    static bool bitIsClear(const AddrType address, const RegType value) {
        return static_cast<bool>(!bitGet(address, value));
    }
    static bool bitIsSet(const AddrType address, const RegType value) {
        return static_cast<bool>(bitGet(address, value));
    }
    static bool bitIsClear(const AddrType address, const RegType value) {
        return static_cast<bool>(!bitGet(address, value));
    }
};
