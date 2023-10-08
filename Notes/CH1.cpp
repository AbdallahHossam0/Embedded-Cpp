// * it is recommended to set the pin to low before its direction is set to
// output
// * to eliminate potential spikes on I/O pins

// Constant member must be initialized in the constructor initialization list
// The order they are initialized with is the order they are declared in the
// class
// ! not the order of they appear in the constructor initializer list

// Note: A function implemented directly in the class declaration is by default
// inline

// It is better to use structs for classes that have data members only

// By default: Start up code is Compiler responsibilities

// Anonymous [unnamed] namespaces are used to limit the scope of anything within
// to file-level equivelent to static in C, static is also can be used in C++

// it is always good to use <cstdint> types and macro literals instead of
// user-defined ones

// * C++ provides 5 specific cast operators:
// 1- static_cast => for primitive types
// 2- reinterpret_cast => more powerful and less safer than static cast
//    you can use it to cast pointer to integer and the opposite
//    Please, ensure that the integral type is large enough to hod a pointer
// 3- std::bit_cast => for bits
// 4- dynamic_cast
// 5- const_cast

// ! Example of use for reinterpret_cast
constexpr unsigned int port{0x25};
constexpr unsigned int bval{1 << 5};
int func(void) { *reinterpret_cast<volatile unsigned int*>(port) ^= bval; }

// * Note the use of constexpr {compile-time constants} instead of C-style
// * #define helps CPU to do what it needs  without using the stack or
// * intermediate CPU registers
// * This efficient kind of optimization is called "Constant Folding"
