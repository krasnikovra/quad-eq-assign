#pragma once

#include "Student.h"

class BadStudent : public Student {
public:
    BadStudent() noexcept : Student() {}
    BadStudent(const std::string& name) noexcept : Student(name) {}
    QuadEqRoots SolveQuadEq(const QuadEq& eq) const override;
};