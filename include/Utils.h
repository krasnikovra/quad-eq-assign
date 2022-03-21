#pragma once
#include <complex>

#define NO_ROOTS QuadEqRoots(0, 0, 0)
#define INF_ROOTS QuadEqRoots(0, 0, INT_MAX)

class Student;
using Complex = std::complex<double>;

struct QuadEq {
    double a, b, c;
    QuadEq() noexcept : a(0), b(0), c(0) {}
    QuadEq(const double a_, const double b_, const double c_) noexcept : a(a_), b(b_), c(c_) {}
};

struct QuadEqRoots {
    Complex x1, x2;
    size_t cnt;
    QuadEqRoots(const Complex& x1_, const Complex& x2_, const size_t cnt_) noexcept : 
        x1(x1_), x2(x2_), cnt(cnt_) {}
};

struct Solution {
    QuadEq eq;
    QuadEqRoots eqRoots;
    const Student* pstudent;
    Solution(const QuadEq& eq_, const QuadEqRoots& eqRoots_, const Student* pstudent_) noexcept :
        eq(eq_), eqRoots(eqRoots_), pstudent(pstudent_) {
    }
};

bool operator==(const Complex& a, const Complex& b) noexcept;
bool operator==(const QuadEqRoots& a, const QuadEqRoots& b) noexcept;
QuadEqRoots SolveQuadEqCorrect(const QuadEq& eq) noexcept;
