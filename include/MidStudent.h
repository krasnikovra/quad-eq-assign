#pragma once

#include "Student.h"

class MidStudent : public Student {
public:
    MidStudent() noexcept : Student(), _rightAnsProb(0.5) {}
    MidStudent(const std::string& name) noexcept : Student(name), _rightAnsProb(0.5) {}
    MidStudent(const std::string& name, const double rightAnsProb) noexcept : Student(name),
        _rightAnsProb(rightAnsProb) {}
    QuadEqRoots solveQuadEq(const QuadEq& eq) const noexcept override;
private:
    double _rightAnsProb;
};
