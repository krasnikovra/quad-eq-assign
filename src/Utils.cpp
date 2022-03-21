#include "Utils.h"

using namespace std;

bool operator==(const Complex& a, const Complex& b) noexcept {
    return a.real() == b.real() && a.imag() == b.imag();
}

bool operator==(const QuadEqRoots& a, const QuadEqRoots& b) noexcept {
    // roots can be exchanged but are being assumed still equal
    return ((a.x1 == b.x1 && a.x2 == b.x2) || (a.x1 == b.x2 && a.x2 == b.x1)) && a.cnt == b.cnt;
}

QuadEqRoots SolveQuadEqCorrect(const QuadEq& eq) noexcept {
    if (eq.a == 0.0) {
        if (eq.b == 0.0)
            return eq.c == 0.0 ? INF_ROOTS : NO_ROOTS;
        Complex root(-eq.c / eq.b);
        return QuadEqRoots(root, root, 1);
    }
    Complex discriminantSqrt = sqrt(Complex(eq.b * eq.b - 4 * eq.a * eq.c));
    return QuadEqRoots((-eq.b + discriminantSqrt) / (2 * eq.a),
        (-eq.b - discriminantSqrt) / (2 * eq.a), 2);
}