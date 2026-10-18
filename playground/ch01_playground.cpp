// Chapter 1 — Vectors and Matrices
// Scratch space for working the end-of-chapter exercises and poking at
// the API once you've filled in src/Vector.cpp and src/Matrix.cpp.
//
// This isn't graded by the test suite — tests/ch01_tests.cpp is what
// tells you whether your implementations are correct. Use this file
// freely to explore, print intermediate values, and write out your
// solutions to "Exercises for Chapter 1" from the book.

#include "C:\CodingProjects\GameEngineLearning\fged-vol1-math\include\Vector.h"
#include "C:\CodingProjects\GameEngineLearning\fged-vol1-math\include\Matrix.h"
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
    printf("a x b = (%.2f, %.2f, %.2f)\n", Cross(a, b).x, Cross(a, b).y, Cross(a, b).z);
    printf("Normalize(a) = (%.2f, %.2f, %.2f)\n", Normalize(a).x, Normalize(a).y, Normalize(a).z);
    printf("Project(a, b) = (%.2f, %.2f, %.2f)\n", Project(a, b).x, Project(a, b).y, Project(a, b).z);
    printf("Reject(a, b) = (%.2f, %.2f, %.2f)\n", Reject(a, b).x, Reject(a, b).y, Reject(a, b).z);
    printf("ScalarTripleProduct(a, b, a) = %.4f\n", ScalarTripleProduct(a, b, a));
    printf("ScalarTripleProduct(a, b, b) = %.4f\n", ScalarTripleProduct(a, b, b));
    printf("Aritmetic check: a + b - b = (%.2f, %.2f, %.2f)\n", (a + b - b).x, (a + b - b).y, (a + b - b).z);
    printf("Aritmetic check: a - b + b = (%.2f, %.2f, %.2f)\n", (a - b + b).x, (a - b + b).y, (a - b + b).z);
    printf("Aritmetic check: a * b + b = (%.2f, %.2f, %.2f)\n", (a * b + b).x, (a * b + b).y, (a * b + b).z);
    //scalar multiplication and division
    printf("Aritmetic check: a * 2.0f = (%.2f, %.2f, %.2f)\n", (a * 2.0f).x, (a * 2.0f).y, (a * 2.0f).z);
    printf("Aritmetic check: a / 2.0f = (%.2f, %.2f, %.2f)\n", (a / 2.0f).x, (a / 2.0f).y, (a / 2.0f).z);
    //inline
    Vector3D c = -a;
    printf("Aritmetic check: c = (%.2f, %.2f, %.2f)\n", c.x, c.y, c.z);
    //indexing
    printf("Aritmetic check: a[0] = %.2f, a[1] = %.2f, a[2] = %.2f\n", a[0], a[1], a[2]);
    //const indexing
    const Vector3D d(7.0f, 8.0f, 9.0f);
    printf("Aritmetic check: d[0] = %.2f, d[1] = %.2f, d[2] = %.2f\n", d[0], d[1], d[2]);
    //division edge case:
    Vector3D e = d / c;
    print("e = d / c evaluates to ", e);

    //Matrix:
    


   // --- Exercise 1 ------------------------------------------------------
    // TODO: work the book's first exercise here.

    // --- Exercise 2 ------------------------------------------------------
    // TODO: work the book's second exercise here.

    // Add more `// --- Exercise N ---` blocks as you go.

    return 0;
}
