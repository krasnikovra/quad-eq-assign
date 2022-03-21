#include "MidStudent.h"
#include <cstdlib>

QuadEqRoots MidStudent::SolveQuadEq(const QuadEq& eq) const noexcept {
    return rand() / (double)RAND_MAX < _rightAnsProb ? SolveQuadEqCorrect(eq) : QuadEqRoots(0, 0, 1);
}
