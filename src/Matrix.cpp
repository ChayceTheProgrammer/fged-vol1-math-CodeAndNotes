#include "Matrix.h"

namespace fged {

// --- §1.3 Matrix Fundamentals (boilerplate, already implemented) -------

Matrix3D::Matrix3D(float n00, float n01, float n02,
                    float n10, float n11, float n12,
                    float n20, float n21, float n22) {
    n[0][0] = n00; n[1][0] = n01; n[2][0] = n02;
    n[0][1] = n10; n[1][1] = n11; n[2][1] = n12;
    n[0][2] = n20; n[1][2] = n21; n[2][2] = n22;
}

// --- §1.4 Basic Matrix Operations ----------------------------------------

Matrix3D operator+(const Matrix3D& a, const Matrix3D& b) {
    Matrix3D r;
    for (int c = 0; c < 3; ++c)
        for (int row = 0; row < 3; ++row)
            r.n[c][row] = a.n[c][row] + b.n[c][row];
    return r;
}
bool isDaiagonal(const Matrix3D& m) {
    // Check if all off-diagonal elements are zero
    for (int c = 0; c < 3; ++c) {
        for (int row = 0; row < 3; ++row) {
            if (c != row && m.n[c][row] != 0.0f) {
                return false; // Found a non-zero off-diagonal element
            }
        }
    }
    return true; // All off-diagonal elements are zero
}

Matrix3D operator-(const Matrix3D& a, const Matrix3D& b) {
    Matrix3D r;
    for (int c = 0; c < 3; ++c)
        for (int row = 0; row < 3; ++row)
            r.n[c][row] = a.n[c][row] - b.n[c][row];
    return r;
}

Matrix3D operator*(const Matrix3D& m, float s) {
    Matrix3D r;
    for (int c = 0; c < 3; ++c)
        for (int row = 0; row < 3; ++row)
            r.n[c][row] = m.n[c][row] * s;
    return r;
}

// TODO(FGED §1.4.2): implement matrix-matrix multiplication.
Matrix3D operator*(const Matrix3D& /*a*/, const Matrix3D& /*b*/) {
    return Matrix3D(0,0,0, 0,0,0, 0,0,0); // placeholder
}

// TODO(FGED §1.4.2): implement matrix-vector multiplication.
Vector3D operator*(const Matrix3D& /*m*/, const Vector3D& /*v*/) {
    return Vector3D(0.0f, 0.0f, 0.0f); // placeholder
}

// --- §1.7 Matrix Inversion -------------------------------------------------

// TODO(FGED §1.7.1): return the identity matrix.
Matrix3D Identity3D() {
    return Matrix3D(0,0,0, 0,0,0, 0,0,0); // placeholder — should be the identity
}

// TODO(FGED §1.7): implement the transpose.
Matrix3D Transpose(const Matrix3D& /*m*/) {
    return Matrix3D(0,0,0, 0,0,0, 0,0,0); // placeholder
}

// TODO(FGED §1.7.2): implement the determinant.
float Determinant(const Matrix3D& /*m*/) {
    return 0.0f; // placeholder
}

// TODO(FGED §1.7.4/§1.7.5): implement inversion.
Matrix3D Inverse(const Matrix3D& /*m*/) {
    return Matrix3D(0,0,0, 0,0,0, 0,0,0); // placeholder
}

// -------------------------------------------------------------------------
// Matrix4D (boilerplate constructor already implemented)
// -------------------------------------------------------------------------

Matrix4D::Matrix4D(float n00, float n01, float n02, float n03,
                    float n10, float n11, float n12, float n13,
                    float n20, float n21, float n22, float n23,
                    float n30, float n31, float n32, float n33) {
    n[0][0] = n00; n[1][0] = n01; n[2][0] = n02; n[3][0] = n03;
    n[0][1] = n10; n[1][1] = n11; n[2][1] = n12; n[3][1] = n13;
    n[0][2] = n20; n[1][2] = n21; n[2][2] = n22; n[3][2] = n23;
    n[0][3] = n30; n[1][3] = n31; n[2][3] = n32; n[3][3] = n33;
}

// TODO(FGED §1.7.1): return the 4x4 identity matrix.
Matrix4D Identity4D() {
    return Matrix4D(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0); // placeholder
}

// TODO(FGED §1.4.2): implement 4x4 matrix multiplication.
Matrix4D operator*(const Matrix4D& /*a*/, const Matrix4D& /*b*/) {
    return Matrix4D(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0); // placeholder
}

// TODO(FGED §1.4.2 / §2.6): implement matrix * homogeneous vector.
Vector4D operator*(const Matrix4D& /*m*/, const Vector4D& /*v*/) {
    return Vector4D(0.0f, 0.0f, 0.0f, 0.0f); // placeholder
}

// TODO(FGED §1.7.4, applied to the 4x4 case): implement 4x4 inversion.
Matrix4D Inverse(const Matrix4D& /*m*/) {
    return Matrix4D(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0); // placeholder
}

} // namespace fged
