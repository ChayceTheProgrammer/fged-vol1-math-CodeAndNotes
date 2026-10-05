// Chapter 2 — Transforms
// Scratch space for the end-of-chapter exercises, once src/Transform.cpp
// and src/Quaternion.cpp are filled in.

#include "Vector.h"
#include "Matrix.h"
#include "Transform.h"
#include "Quaternion.h"
#include <cstdio>

using namespace fged;

int main() {
    printf("=== Chapter 2 playground ===\n");

    // --- Quick sanity check once Transform.cpp is implemented ----------
    Vector3D v(1.0f, 0.0f, 0.0f);
    Matrix3D rotZ90 = MakeRotationZ(3.14159265f / 2.0f);
    Vector3D rotated = rotZ90 * v;
    printf("Rotating (1,0,0) by 90deg about Z -> (%.3f, %.3f, %.3f)\n",
           rotated.x, rotated.y, rotated.z);
    // Expect approximately (0, 1, 0).

    // --- Exercise 1 ------------------------------------------------------
    // TODO: work the book's first exercise here.

    // --- Exercise 2 ------------------------------------------------------
    // TODO: work the book's second exercise here.

    return 0;
}
