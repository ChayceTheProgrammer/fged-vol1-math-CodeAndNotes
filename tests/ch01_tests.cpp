#include "test_framework.h"
#include "Vector.h"
#include "Matrix.h"

using namespace fged;

void RunChapter1Tests() {
    TEST_SECTION("Chapter 1 -- Sec 1.2.1 Magnitude");
    {
        CHECK_NEAR(Magnitude(Vector3D(3, 4, 0)), 5.0f, 1e-5f);     // 3-4-5 triangle
        CHECK_NEAR(Magnitude(Vector3D(1, 2, 2)), 3.0f, 1e-5f);
    }

    TEST_SECTION("Chapter 1 -- Sec 1.2.1 Normalize");
    {
        Vector3D n = Normalize(Vector3D(3, 4, 0));
        CHECK_VEC3_NEAR(n, 0.6f, 0.8f, 0.0f, 1e-5f);
        CHECK_NEAR(Magnitude(n), 1.0f, 1e-5f);
    }

    TEST_SECTION("Chapter 1 -- Sec 1.5.1 Dot product");
    {
        CHECK_NEAR(Dot(Vector3D(1, 2, 3), Vector3D(4, 5, 6)), 32.0f, 1e-5f);
        CHECK_NEAR(Dot(Vector3D(1, 0, 0), Vector3D(0, 1, 0)), 0.0f, 1e-5f); // perpendicular
    }

    TEST_SECTION("Chapter 1 -- Sec 1.5.2 Cross product");
    {
        CHECK_VEC3_NEAR(Cross(Vector3D(1, 0, 0), Vector3D(0, 1, 0)), 0.0f, 0.0f, 1.0f, 1e-5f);
        CHECK_VEC3_NEAR(Cross(Vector3D(0, 1, 0), Vector3D(0, 0, 1)), 1.0f, 0.0f, 0.0f, 1e-5f);
    }

    TEST_SECTION("Chapter 1 -- Sec 1.5.3 Scalar triple product");
    {
        // Volume of the unit cube spanned by the standard basis == 1.
        CHECK_NEAR(ScalarTripleProduct(Vector3D(1, 0, 0), Vector3D(0, 1, 0), Vector3D(0, 0, 1)), 1.0f, 1e-5f);
    }

    TEST_SECTION("Chapter 1 -- Sec 1.6 Projection / rejection");
    {
        Vector3D a(3, 4, 0), b(1, 0, 0);
        CHECK_VEC3_NEAR(Project(a, b), 3.0f, 0.0f, 0.0f, 1e-5f);
        CHECK_VEC3_NEAR(Reject(a, b), 0.0f, 4.0f, 0.0f, 1e-5f);
    }

    TEST_SECTION("Chapter 1 -- Sec 1.7 Identity / Transpose / Determinant / Inverse");
    {
        Matrix3D I = Identity3D();
        Vector3D v(2, -1, 5);
        CHECK_VEC3_NEAR(I * v, 2.0f, -1.0f, 5.0f, 1e-5f);

        Matrix3D diag(2, 0, 0,
                      0, 3, 0,
                      0, 0, 4);
        CHECK_NEAR(Determinant(diag), 24.0f, 1e-4f);
        CHECK_NEAR(Determinant(I), 1.0f, 1e-5f);

        Matrix3D M(1, 2, 3,
                   4, 5, 6,
                   7, 8, 9);
        Matrix3D Mt = Transpose(M);
        CHECK_NEAR(Mt(0, 1), M(1, 0), 1e-5f); // Mt(row,col) == M(col,row)
        CHECK_NEAR(Mt(1, 0), M(0, 1), 1e-5f);

        Matrix3D diagInv = Inverse(diag);
        CHECK_NEAR(diagInv(0, 0), 0.5f, 1e-4f);
        CHECK_NEAR(diagInv(1, 1), 1.0f / 3.0f, 1e-4f);
        CHECK_NEAR(diagInv(2, 2), 0.25f, 1e-4f);
    }

    TEST_SECTION("Chapter 1 -- Sec 1.4.2 Matrix multiplication");
    {
        Matrix3D A(2, 0, 0,  0, 3, 0,  0, 0, 4);
        Matrix3D B(5, 0, 0,  0, 6, 0,  0, 0, 7);
        Matrix3D AB = A * B;
        CHECK_NEAR(AB(0, 0), 10.0f, 1e-4f);
        CHECK_NEAR(AB(1, 1), 18.0f, 1e-4f);
        CHECK_NEAR(AB(2, 2), 28.0f, 1e-4f);
        CHECK_NEAR(AB(0, 1), 0.0f, 1e-4f);
    }
}
