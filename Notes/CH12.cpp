// > Floating Point Math

// * Not commonly used in Embedded Systems

// - float : 4 bytes width - single precision
// - double : 8 bytes width - double precision
// - long double : 16 bytes width - quadruple precision

// # Some Controllers have FPU
// - FPU can make floating point arithmetic as efficient as integer calculations

// * if the controller does not have FPU so the floating point calculations will
// * be performed using Software floating point emulation library
// - this will cause the floating point operations to be slow, large amount of
// code and high resource consumption

// * C++ supports ,amu Floating Point arithmetic in <cmath> and <cstdlib>
// libraries

// * C++ also supports concepts of infinity and NAN representable

// * You can use std::numeric_limits to get the limits od floating point types
// * and constant like epsilon

#include <limits>

float eps{std::numeric_limits<float>::epsilon()};

// ? Have you heard about variable templates?

template<class T>
constexpr T pi{static_cast<T>(3.14159265)};

// To use it
double pi_d{pi<double>};

// # also Boost provides a wide selection of scalable math constants in its
// # "Boost.math.constants" library

// # C++20 also added a common math constants on <numbers> as variables
// # templates

#include <numbers>

constexpr float pi_f{std::numbers::pi_v<float>};

// ! <cmath> contains many math function like sin, cos, ..., asin, acos, ...,
// ! exp, log, ...

// # C++ supports complex values math => with data type std::complex which is
// # defined in <complex> and this is specified only for
// # (float, double, long double)

#include <complex>

int main(void) {
    std::complex<float> z1{5, 4};
    float n = std::norm(z1);
    float a = std::abs(z1);

    std::complex<float> z2;

    z2.real(4);
    z2.imag(5);

    int r = z2.real();
    int i = z2.imag();

    return 0;
}

// Note: Compile-time evaluation of function using constexpr
// * constexpr function is evaluated on the compile-time

template<class T>
constexpr T circleArea(T r) {
    return (pi * r) * r;
}

// * We should use constexpr functions instead of MACROs

// # Remember Floating-Point Literals
auto f{1.23f};   // float
auto d{1.23};    // double
auto ld{1.23l};  // long double
