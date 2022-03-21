#pragma once

#include "Utils.h"

class Teacher;

class Student {
public:
    Student() noexcept : _name("Undefined Student") {}
    Student(const std::string& name) noexcept : _name(name) {}
    std::string GetName() const noexcept { return _name; }
    void SendSolution(const QuadEq& eq, Teacher& teacher) const noexcept;
    void SendFileAssignmentSolution(const std::string& filename, Teacher& teacher) const;
    virtual QuadEqRoots SolveQuadEq(const QuadEq& eq) const noexcept = 0;
protected:
    std::string _name;
};

