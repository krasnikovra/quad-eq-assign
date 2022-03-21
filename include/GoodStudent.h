#pragma once

#include "Student.h"

class GoodStudent : public Student {
public:
    GoodStudent() noexcept : Student() {}
    GoodStudent(const std::string& name) noexcept : Student(name) {}
    QuadEqRoots SolveQuadEq(const QuadEq& eq) const override;
};

