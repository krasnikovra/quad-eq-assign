#include "Teacher.h"
#include "Student.h"
#include <iostream>

using namespace std;

void Teacher::ClearResults() noexcept {
    _results.clear();
}

void Teacher::ClearSolutions() noexcept {
    _solutions.clear();
}

void Teacher::CheckSolutions() noexcept {
    for (auto& solution : _solutions) {
        ++_results[solution.name].total;
        if (solution.eqRoots == SolveQuadEqCorrect(solution.eq))
            ++_results[solution.name].solved;
    }
}

void Teacher::PublishResults() const noexcept {
    cout << "Teacher: " + _name << endl;
    for (auto& result : _results)
        cout << result.first << "\t " << result.second.solved << " of "
            << result.second.total << endl;
}