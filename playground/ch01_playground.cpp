// Chapter 1 — Vectors and Matrices
// Scratch space for working the end-of-chapter exercises and poking at
// the API once you've filled in src/Vector.cpp and src/Matrix.cpp.
//
// This isn't graded by the test suite — tests/ch01_tests.cpp is what
// tells you whether your implementations are correct. Use this file
// freely to explore, print intermediate values, and write out your
// solutions to "Exercises for Chapter 1" from the book.

#include "Vector.h"
#include "Matrix.h"
#include <cstdio>

using namespace fged;

int main() {
    printf("=== Chapter 1 playground ===\n");

    // --- Quick sanity check once Vector.cpp is implemented -------------
    Vector3D a(1.0f, 2.0f, 3.0f);
    Vector3D b(4.0f, 5.0f, 6.0f);
    printf("a + b = (%.2f, %.2f, %.2f)\n", (a + b).x, (a + b).y, (a + b).z);
    printf("|a|   = %.4f\n", Magnitude(a));
    printf("a . b = %.4f\n", Dot(a, b));

    // --- Exercise 1 ------------------------------------------------------
    // TODO: work the book's first exercise here.

    // --- Exercise 2 ------------------------------------------------------
    // TODO: work the book's second exercise here.

    // Add more `// --- Exercise N ---` blocks as you go.

    return 0;
}
