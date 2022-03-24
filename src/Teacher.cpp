#include "Teacher.h"
#include "Student.h"
#include <iostream>

using namespace std;

void Teacher::clearResults() noexcept {
    _results.clear();
}

void Teacher::clearSolutions() noexcept {
    _solutions.clear();
}

void Teacher::checkSolutions() noexcept {
    for (auto& solution : _solutions) {
        ++_results[solution.name].total;
        if (solution.eqRoots == SolveQuadEqCorrect(solution.eq))
            ++_results[solution.name].solved;
    }
}

void Teacher::publishResults() const noexcept {
    cout << "Teacher: " + _name << endl;
    for (auto& result : _results)
        cout << result.first << "\t " << result.second.solved << " of "
            << result.second.total << endl;
}