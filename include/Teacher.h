#pragma once

#include "Utils.h"
#include "Student.h"
#include <string>
#include <vector>
#include <map>

class Teacher {
public:
    Teacher() noexcept : _name("Undefined Teacher"),
        _solutions(std::vector<Solution>()), _results(std::map<std::string, Result>()) {}
    Teacher(const Teacher& teacher) noexcept : _name(teacher._name),
        _solutions(std::vector<Solution>()), _results(std::map<std::string, Result>()) {}
    Teacher(const std::string& name) noexcept : _name(name),
        _solutions(std::vector<Solution>()), _results(std::map<std::string, Result>()) {}
    void clearResults() noexcept;
    void clearSolutions() noexcept;
    void checkSolutions() noexcept;
    void publishResults() const noexcept;
    friend void Student::sendSolution(const QuadEq&, Teacher&) const noexcept;
private:
    struct Result {
        size_t solved, total;
    };
    std::string _name;
    std::vector<Solution> _solutions;
    std::map<std::string, Result> _results;
};

