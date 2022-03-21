#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "BadStudent.h"
#include "MidStudent.h"
#include "GoodStudent.h"
#include "Teacher.h"
#include <iostream>
#include <fstream>

using namespace std;

const vector<string> FNAMES = { "John", "Paul", "Smith", "Josh", "George", "Ivan", "Bob"};
const vector<string> SNAMES = { "Brown", "Green", "Orange", "Silver", "Ivanov", "Sidorov"};

double Random(const double min, const double max) noexcept {
    return rand() / (double)RAND_MAX * (max - min) + min;
}

string RandomFullname() noexcept {
    return FNAMES[rand() % FNAMES.size()] + " " + SNAMES[rand() % SNAMES.size()];
}

void GenerateSomeQuadEqs(const string& filename, const size_t count, 
    const double minQuot, const double maxQuot) {
    ofstream fileOut(filename);
    if (!fileOut.is_open())
        throw runtime_error(string("Could not open ") + filename + 
            string(" file to generate quad eqs!"));
    for (size_t i = 0; i < count; i++)
        fileOut << Random(minQuot, maxQuot) << " " << Random(minQuot, maxQuot) << " "
            << Random(minQuot, maxQuot) << "\n";
    fileOut.close();
}

vector<unique_ptr<Student>> GenerateSomeStudents(const size_t count) noexcept {
    vector<unique_ptr<Student>> res(count);
    for (auto& pstudent : res) {
        switch (rand() % 3) {
        case 0:
            pstudent = move(make_unique<BadStudent>(RandomFullname()));
            break;
        case 1:
            pstudent = move(make_unique<MidStudent>(RandomFullname()));
            break;
        case 2:
            pstudent = move(make_unique<GoodStudent>(RandomFullname()));
            break;
        }
    }
    return res;
}

void StudentsSolveTaskFromFile(const string& filename, const vector<unique_ptr<Student>>& students,
    Teacher& teacher) {
    for (auto& pstudent : students)
        pstudent->SendFileAssignmentSolution(filename, teacher);
}

int main() {
    // no mem leaks found :)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    const size_t studentsCnt = 16;
    const size_t eqCnt = 100;
    const double minQuot = -100;
    const double maxQuot = 100;
    const string filename = "input.txt";
    Teacher teacher(RandomFullname());
    // let us have some students
    auto students = GenerateSomeStudents(studentsCnt);
    try {
        // and some equations
        GenerateSomeQuadEqs(filename, eqCnt, minQuot, maxQuot);
        // each of them solve quadratic equations from the 'filename' file
        StudentsSolveTaskFromFile(filename, students, teacher);
        // ... graduation week comes and teacher check students' solutions
        teacher.CheckSolutions();
        // ... and after some time he decide to publish results
        teacher.PublishResults();
        // after all, teacher clears results, solutins to receive and publish new assignment result
        teacher.ClearSolutions();
        teacher.ClearResults();
        // now teacher is ready for the new assignment
    }
    catch (const exception& err) {
        cout << "An error occured:" << endl << err.what() << endl;
    }

    return 0;
}
