// it is better to use compile-time initialization instead of run-time
// initialization this can be used using template class

// * It is better declare variables when you need to use them

// use fixed size integers with help of <cstdint>
// ! Example
#include <cstdint>
constexpr std::uint8_t value{INT8_C(0x7fff)};
// it is better to use this technique in C and C++

// * Use namespaces when possible
// Usage if namespaces is optional and it is used to improve organization and
// code readability

// Remember the use of anonymous namespace to limit the scope of a var to the
// file

// C++17 introduced the support of nested namespace
// ! Example
namespace X::Y::Z {
uint8_t value;
}

int func(void) { X::Y::Z::value = UINT8_C(1); }

// One can and really should

// Global non-initialized pointers are defined to nullptr by default
// * Use nullptr instead of NULL

// Note that:
// constexpr can be used for functions, objects and methods if its value is
// known at compile time

// static class member means that only one object is used for all object of that
// class

// constexpr objects are as const ones => they have to be initialized at
// declaration

// Constexpr can bee used to do computations done at compile time (Instead of
// MACROs)

static_assert(true /*condition*/, "Message");
// if the conditions is false a compile-time error occurs

// use static_assert for compile time checks and assert for run time checks

// Remember the use of <limits>

// use std::array instead of C-style arrays
// Drawbacks of Dynamic Memory Allocation
// 1- Memory Fragmentation
// 2- Allocator Complexity

//  Recommended to use <atomics>
// atomic_load() and atomic_store
// good for variables that are changed using ISRs
// you need to load or store it in one atomic instruction

// Since C++14 it is possible to use digit separator
constexpr uint64_t x = UINT64_C(123'131'123);
// also can be used for binaries
constexpr uint8_t x = UINT8_C(0b1010'1001);

// highest level of abstraction, it is recommended to mark it as final
// final classes can inherit form another classes but cannot be derived classes
// for another class

// use alias rather than typedef
#include <array>
using arrInt = std::array<int, 3>;

// Remember C++20 <span>
