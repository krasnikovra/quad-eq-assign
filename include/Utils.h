#pragma once

#include <complex>

using Complex = std::complex<double>;

struct QuadEq {
    double a, b, c;
    QuadEq() noexcept : a(0), b(0), c(0) {}
    QuadEq(const double a_, const double b_, const double c_) noexcept : a(a_), b(b_), c(c_) {}
};

class QuadEqRoots {
public:
    enum class Count {
        NO,
        ONE,
        TWO,
        INF
    };

    QuadEqRoots(const Complex& x) noexcept : _x1(x), _x2(x), _count(Count::ONE) {}
    QuadEqRoots(const Complex& x1, const Complex& x2) noexcept : _x1(x1), _x2(x2),
        _count(x1 == x2 ? Count::ONE : Count::TWO) {}
    Complex getX1() const noexcept { return _x1; }
    Complex getX2() const noexcept { return _x2; }
    Count getCount() const noexcept { return _count; }
    static QuadEqRoots NoRoots() noexcept { return QuadEqRoots(0, 0, Count::NO); };
    static QuadEqRoots InfRoots() noexcept { return QuadEqRoots(0, 0, Count::INF); };
    bool operator==(const QuadEqRoots& roots) noexcept;
private:
    QuadEqRoots(const Complex& x1, const Complex& x2, const Count& count) noexcept :
        _x1(x1), _x2(x2), _count(count) {}

    Complex _x1, _x2;
    Count _count;
};

struct Solution {
    QuadEq eq;
    QuadEqRoots eqRoots;
    std::string name;
    Solution(const QuadEq& eq_, const QuadEqRoots& eqRoots_, const std::string& name_) noexcept :
        eq(eq_), eqRoots(eqRoots_), name(name_) {}
};

bool operator==(const Complex& a, const Complex& b) noexcept;
QuadEqRoots SolveQuadEqCorrect(const QuadEq& eq) noexcept;
