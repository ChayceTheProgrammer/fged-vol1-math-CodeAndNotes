#include "test_framework.h"
#include "Vector.h"
#include "Matrix.h"
#include "Transform.h"
#include "Quaternion.h"
#include <cmath>

using namespace fged;

static const float PI = 3.14159265358979323846f;

void RunChapter2Tests() {
    TEST_SECTION("Chapter 2 -- Sec 2.2.1 Rotation about a coordinate axis");
    {
        CHECK_VEC3_NEAR(MakeRotationZ(PI / 2.0f) * Vector3D(1, 0, 0), 0.0f, 1.0f, 0.0f, 1e-4f);
        CHECK_VEC3_NEAR(MakeRotationX(PI / 2.0f) * Vector3D(0, 1, 0), 0.0f, 0.0f, 1.0f, 1e-4f);
        CHECK_VEC3_NEAR(MakeRotationY(PI / 2.0f) * Vector3D(0, 0, 1), 1.0f, 0.0f, 0.0f, 1e-4f);
    }

    TEST_SECTION("Chapter 2 -- Sec 2.2.2 Rotation about an arbitrary axis");
    {
        // Rotating about the Z axis via the general formula should agree
        // with the axis-specific MakeRotationZ above.
        Vector3D viaGeneral = MakeRotation(PI / 2.0f, Vector3D(0, 0, 1)) * Vector3D(1, 0, 0);
        CHECK_VEC3_NEAR(viaGeneral, 0.0f, 1.0f, 0.0f, 1e-4f);
    }

    TEST_SECTION("Chapter 2 -- Sec 2.3 Reflections");
    {
        // Reflect (2,3,4) through the plane y=0 (normal (0,1,0)).
        Vector3D r = MakeReflection(Vector3D(0, 1, 0)) * Vector3D(2, 3, 4);
        CHECK_VEC3_NEAR(r, 2.0f, -3.0f, 4.0f, 1e-4f);
    }

    TEST_SECTION("Chapter 2 -- Sec 2.4 Scales");
    {
        CHECK_VEC3_NEAR(MakeScale(2, 3, 4) * Vector3D(1, 1, 1), 2.0f, 3.0f, 4.0f, 1e-4f);
        // Scaling along the x direction only should leave y, z untouched.
        CHECK_VEC3_NEAR(MakeScale(2.0f, Vector3D(1, 0, 0)) * Vector3D(1, 1, 1), 2.0f, 1.0f, 1.0f, 1e-4f);
    }

    TEST_SECTION("Chapter 2 -- Sec 2.6 Homogeneous coordinates / transform composition");
    {
        Matrix4D T = MakeTransform(Identity3D(), Vector3D(5, 0, 0));
        CHECK_VEC3_NEAR(TransformPoint(T, Vector3D(1, 2, 3)), 6.0f, 2.0f, 3.0f, 1e-4f);
        // Directions ignore translation entirely.
        CHECK_VEC3_NEAR(TransformVector(T, Vector3D(1, 2, 3)), 1.0f, 2.0f, 3.0f, 1e-4f);
    }

    TEST_SECTION("Chapter 2 -- Sec 2.7 Quaternions");
    {
        CHECK_NEAR(Magnitude(Quaternion(0, 0, 0, 1)), 1.0f, 1e-5f);

        Quaternion c = Conjugate(Quaternion(1, 2, 3, 4));
        CHECK_NEAR(c.x, -1.0f, 1e-5f);
        CHECK_NEAR(c.y, -2.0f, 1e-5f);
        CHECK_NEAR(c.z, -3.0f, 1e-5f);
        CHECK_NEAR(c.w, 4.0f, 1e-5f);

        Quaternion q = MakeRotationQuaternion(PI / 2.0f, Vector3D(0, 0, 1));
        CHECK_VEC3_NEAR(Rotate(q, Vector3D(1, 0, 0)), 0.0f, 1.0f, 0.0f, 1e-4f);

        // ToRotationMatrix should agree with Rotate() for the same quaternion.
        Vector3D viaMatrix = ToRotationMatrix(q) * Vector3D(1, 0, 0);
        CHECK_VEC3_NEAR(viaMatrix, 0.0f, 1.0f, 0.0f, 1e-4f);
    }
}
