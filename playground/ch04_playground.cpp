// Chapter 4 — Advanced Algebra
// Scratch space for the end-of-chapter exercises, once src/Bivector.cpp
// is filled in. This chapter rewards going slower than the first three —
// use this file to try small, concrete examples before trusting the
// general formulas.

#include "Vector.h"
#include "Bivector.h"
#include <cstdio>

using namespace fged;

int main() {
    printf("=== Chapter 4 playground ===\n");

    // --- Quick sanity check once Bivector.cpp is implemented -----------
    Vector3D x(1.0f, 0.0f, 0.0f);
    Vector3D y(0.0f, 1.0f, 0.0f);
    Bivector3D xy = Wedge(x, y);
    printf("x ^ y = (%.2f, %.2f, %.2f)\n", xy.x, xy.y, xy.z);
    // Compare this against Cross(x, y) from Chapter 1 once both are
    // implemented — §4.1 explains exactly how they're related (and
    // where they differ).

    // --- Exercise 1 ------------------------------------------------------
    // TODO: work the book's first exercise here.

    // --- Exercise 2 ------------------------------------------------------
    // TODO: work the book's second exercise here.

    return 0;
}
