// Chapter 3 — Geometry
// Scratch space for the end-of-chapter exercises, once src/Geometry.cpp
// is filled in.

#include "Vector.h"
#include "Geometry.h"
#include <cstdio>

using namespace fged;

int main() {
    printf("=== Chapter 3 playground ===\n");

    // --- Quick sanity check once Geometry.cpp is implemented -----------
    Plane groundPlane{Vector3D(0.0f, 1.0f, 0.0f), 0.0f}; // y == 0
    Vector3D pointAbove(2.0f, 5.0f, -1.0f);
    printf("Distance from (2,5,-1) to ground plane: %.3f\n",
           DistancePointToPlane(pointAbove, groundPlane));
    // Expect 5.0 once implemented.

    // --- Exercise 1 ------------------------------------------------------
    // TODO: work the book's first exercise here.

    // --- Exercise 2 ------------------------------------------------------
    // TODO: work the book's second exercise here.

    return 0;
}
