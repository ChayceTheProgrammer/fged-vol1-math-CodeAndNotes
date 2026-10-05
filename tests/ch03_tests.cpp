#include "test_framework.h"
#include "Vector.h"
#include "Matrix.h"
#include "Transform.h"
#include "Geometry.h"
#include <vector>

using namespace fged;

void RunChapter3Tests() {
    TEST_SECTION("Chapter 3 -- Sec 3.2 Normal vectors");
    {
        std::vector<Vector3D> positions = { Vector3D(0, 0, 0), Vector3D(1, 0, 0), Vector3D(0, 1, 0) };
        Triangle t{0, 1, 2};
        CHECK_VEC3_NEAR(ComputeFaceNormal(positions, t), 0.0f, 0.0f, 1.0f, 1e-4f);

        // Identity transform must leave a normal unchanged.
        CHECK_VEC3_NEAR(TransformNormal(Identity3D(), Vector3D(1, 2, 2)), 1.0f, 2.0f, 2.0f, 1e-4f);

        // For a pure rotation, inverse-transpose == the rotation itself --
        // a classic pitfall this checks for directly.
        Matrix3D rot = MakeRotationZ(3.14159265f / 2.0f);
        CHECK_VEC3_NEAR(TransformNormal(rot, Vector3D(0, 1, 0)), -1.0f, 0.0f, 0.0f, 1e-4f);
    }

    TEST_SECTION("Chapter 3 -- Sec 3.3 Lines and rays");
    {
        Line zAxis{Vector3D(0, 0, 0), Vector3D(0, 0, 1)};
        CHECK_NEAR(DistancePointToLine(Vector3D(3, 4, 0), zAxis), 5.0f, 1e-4f);

        Line a{Vector3D(0, 0, 0), Vector3D(1, 0, 0)};
        Line b{Vector3D(0, 0, 1), Vector3D(0, 1, 0)};
        CHECK_NEAR(DistanceLineToLine(a, b), 1.0f, 1e-4f);
    }

    TEST_SECTION("Chapter 3 -- Sec 3.4 Planes");
    {
        Plane ground{Vector3D(0, 1, 0), 0.0f}; // y == 0

        CHECK_NEAR(DistancePointToPlane(Vector3D(2, 5, -1), ground), 5.0f, 1e-4f);
        CHECK_NEAR(DistancePointToPlane(Vector3D(0, -3, 0), ground), -3.0f, 1e-4f);

        CHECK_VEC3_NEAR(ReflectThroughPlane(Vector3D(2, 5, -1), ground), 2.0f, -5.0f, -1.0f, 1e-4f);

        Line straightDown{Vector3D(1, 5, 2), Vector3D(0, -1, 0)};
        Vector3D hit;
        CHECK_TRUE(IntersectLinePlane(straightDown, ground, hit));
        CHECK_VEC3_NEAR(hit, 1.0f, 0.0f, 2.0f, 1e-4f);

        Plane xZero{Vector3D(1, 0, 0), 0.0f};
        Plane zZero{Vector3D(0, 0, 1), 0.0f};
        Vector3D origin3;
        CHECK_TRUE(IntersectThreePlanes(ground, xZero, zZero, origin3));
        CHECK_VEC3_NEAR(origin3, 0.0f, 0.0f, 0.0f, 1e-4f);
    }

    // Sec 3.4.6 (two-plane intersection) and Sec 3.5 (Plucker coordinates)
    // don't have auto-checked cases here -- their correct output depends
    // on a sign/scale convention that's easiest to verify by hand against
    // the book's own worked examples. Use playground/ch03_playground.cpp
    // for those once you've read the section closely.
}
