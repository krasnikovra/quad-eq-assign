#include "Utils.h"
#include <assert.h>

using namespace std;

bool operator==(const Complex& a, const Complex& b) noexcept {
    return a.real() == b.real() && a.imag() == b.imag();
}

bool QuadEqRoots::operator==(const QuadEqRoots& roots) noexcept {
    switch (_count) {
    case Count::NO:
    case Count::INF:
        return _count == roots._count;
    case Count::ONE:
        return (_count == roots._count) && (_x1 == roots._x1);
    case Count::TWO:
        // roots can be exchanged but are being assumed still equal
        return _count == roots._count && 
            ((_x1 == roots._x1 && _x2 == roots._x2) || (_x1 == roots._x2 && _x2 == roots._x1));
    default:
        assert(1);
        return false;
    }
}

QuadEqRoots SolveQuadEqCorrect(const QuadEq& eq) noexcept {
    if (eq.a == 0.0) {
        if (eq.b == 0.0)
            return eq.c == 0.0 ? QuadEqRoots::InfRoots() : QuadEqRoots::NoRoots();
        return QuadEqRoots(-eq.c / eq.b);
    }
    Complex discriminantSqrt = sqrt(Complex(eq.b * eq.b - 4 * eq.a * eq.c));
    return QuadEqRoots((-eq.b + discriminantSqrt) / (2 * eq.a),
        (-eq.b - discriminantSqrt) / (2 * eq.a));
}