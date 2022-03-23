#include "Student.h"
#include "Teacher.h"
#include <fstream>

using namespace std;

void Student::SendSolution(const QuadEq& eq, Teacher& teacher) const noexcept {
    teacher._solutions.push_back(Solution(eq, SolveQuadEq(eq), GetName()));
}

void Student::SendFileAssignmentSolution(const string& filename, Teacher& teacher) const {
    ifstream fileIn(filename);
    if (!fileIn.is_open())
        throw runtime_error(string("Student ") + _name + string("Could not open ")
            + filename + string(" file!"));
    while (!fileIn.eof()) {
        QuadEq eq;
        fileIn >> eq.a >> eq.b >> eq.c;
        if (fileIn.fail())
            break;
        SendSolution(eq, teacher);
    }
    fileIn.close();
}
