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

void Teacher::CheckSolutions() {
    for (auto& solution : _solutions) {
        ++_results[solution.pstudent].total;
        if (solution.eqRoots == SolveQuadEqCorrect(solution.eq))
            ++_results[solution.pstudent].solved;
    }
}

void Teacher::PublishResults() const noexcept {
    cout << "Teacher: " + _name << endl;
    for (auto& result : _results)
        cout << result.first->GetName() << "\t " << result.second.solved << " of "
            << result.second.total << endl;
}