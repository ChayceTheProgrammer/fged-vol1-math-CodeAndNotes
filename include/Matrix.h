#pragma once
// Chapter 1 — Vectors and Matrices (matrix portion)
// Matrix3D is the workhorse for Chapters 1-3; Matrix4D is added for
// homogeneous transforms starting in Chapter 2.

#include "Vector.h"

namespace fged {

// -------------------------------------------------------------------------
// Matrix3D — §1.3 Matrix Fundamentals
// Stored column-major, matching the book's convention: n[column][row].
// -------------------------------------------------------------------------
struct Matrix3D {
    float n[3][3];

    Matrix3D() = default;

    // Constructs from three explicit rows of entries. Provided so you
    // can write Matrix3D(...) literals in tests/playgrounds without
    // fighting column-major storage order.
    Matrix3D(float n00, float n01, float n02,
             float n10, float n11, float n12,
             float n20, float n21, float n22);

    float& operator()(int row, int col) { return n[col][row]; }
    const float& operator()(int row, int col) const { return n[col][row]; }

    Vector3D& operator[](int col) { return *reinterpret_cast<Vector3D*>(n[col]); }
    const Vector3D& operator[](int col) const { return *reinterpret_cast<const Vector3D*>(n[col]); }
};

// --- §1.4 Basic Matrix Operations ---------------------------------------
// Boilerplate — component-wise, not the chapter's actual subject matter.
Matrix3D operator+(const Matrix3D& a, const Matrix3D& b);
Matrix3D operator-(const Matrix3D& a, const Matrix3D& b);
Matrix3D operator*(const Matrix3D& m, float s);

// TODO(FGED §1.4.2): implement matrix-matrix multiplication.
Matrix3D operator*(const Matrix3D& a, const Matrix3D& b);

// TODO(FGED §1.4.2): implement matrix-vector multiplication.
Vector3D operator*(const Matrix3D& m, const Vector3D& v);

bool isDaiagonal(const Matrix3D& m); // Returns true if the matrix is diagonal.

// --- §1.7 Matrix Inversion ------------------------------------------------
// TODO(FGED §1.7.1): return the 3x3 identity matrix.
Matrix3D Identity3D();

// TODO(FGED §1.7): implement the transpose.
Matrix3D Transpose(const Matrix3D& m);

// TODO(FGED §1.7.2): implement the determinant.
float Determinant(const Matrix3D& m);

// TODO(FGED §1.7.4/§1.7.5): implement matrix inversion.
// A determinant near zero means the matrix is singular — decide how you
// want to handle that case (assert, return identity, etc.) and note why.
Matrix3D Inverse(const Matrix3D& m);

// -------------------------------------------------------------------------
// Matrix4D — needed from §2.6 Homogeneous Coordinates onward.
// -------------------------------------------------------------------------
struct Matrix4D {
    float n[4][4];

    Matrix4D() = default;
    Matrix4D(float n00, float n01, float n02, float n03,
             float n10, float n11, float n12, float n13,
             float n20, float n21, float n22, float n23,
             float n30, float n31, float n32, float n33);

    float& operator()(int row, int col) { return n[col][row]; }
    const float& operator()(int row, int col) const { return n[col][row]; }
};

// TODO(FGED §1.7.1): return the 4x4 identity matrix.
Matrix4D Identity4D();

// TODO(FGED §1.4.2): implement 4x4 matrix multiplication.
Matrix4D operator*(const Matrix4D& a, const Matrix4D& b);

// TODO(FGED §1.4.2 / §2.6): implement matrix * homogeneous vector.
Vector4D operator*(const Matrix4D& m, const Vector4D& v);

// TODO(FGED §1.7.4, applied to the 4x4 case): implement 4x4 inversion.
// The book builds this from the 3x3 case plus the translation column —
// worth revisiting after §2.6.
Matrix4D Inverse(const Matrix4D& m);

} // namespace fged
