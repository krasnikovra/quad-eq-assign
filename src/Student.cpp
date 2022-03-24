#include "Student.h"
#include "Teacher.h"
#include <fstream>

using namespace std;

void Student::sendSolution(const QuadEq& eq, Teacher& teacher) const noexcept {
    teacher._solutions.push_back(Solution(eq, solveQuadEq(eq), getName()));
}

void Student::sendFileAssignmentSolution(const string& filename, Teacher& teacher) const {
    ifstream fileIn(filename);
    if (!fileIn.is_open())
        throw runtime_error(string("Student ") + _name + string("Could not open ")
            + filename + string(" file!"));
    while (!fileIn.eof()) {
        QuadEq eq;
        fileIn >> eq.a >> eq.b >> eq.c;
        if (fileIn.fail())
            break;
        sendSolution(eq, teacher);
    }
    fileIn.close();
}
