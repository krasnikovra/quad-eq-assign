#include "MidStudent.h"
#include <cstdlib>

QuadEqRoots MidStudent::solveQuadEq(const QuadEq& eq) const noexcept {
    return rand() / (double)RAND_MAX < _rightAnsProb ? SolveQuadEqCorrect(eq) : QuadEqRoots(0);
}
