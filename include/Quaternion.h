#pragma once
// Chapter 2, §2.7 — Quaternions

#include "Vector.h"
#include "Matrix.h"

namespace fged {

// -------------------------------------------------------------------------
// Quaternion — §2.7.1 Quaternion Fundamentals
// -------------------------------------------------------------------------
struct Quaternion {
    float x, y, z, w;

    Quaternion() = default;
    Quaternion(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}

    // Vector (imaginary) part, useful when a section treats the
    // quaternion as [v, w].
    Vector3D VectorPart() const { return Vector3D(x, y, z); }
};

// --- §2.7.1 Quaternion Fundamentals ---------------------------------------
// TODO(FGED §2.7.1): implement Hamilton product.
Quaternion operator*(const Quaternion& a, const Quaternion& b);

// TODO(FGED §2.7.1): implement magnitude, matching Vector's Magnitude().
float Magnitude(const Quaternion& q);

// TODO(FGED §2.7.1): implement normalization.
Quaternion Normalize(const Quaternion& q);

// TODO(FGED §2.7.1): implement the conjugate (negate the vector part).
Quaternion Conjugate(const Quaternion& q);

// --- §2.7.2 Rotations With Quaternions -----------------------------------
// Builds a unit quaternion representing a rotation of `angle` radians
// about `axis` (unit vector).
// TODO(FGED §2.7.2): implement.
Quaternion MakeRotationQuaternion(float angle, const Vector3D& axis);

// Rotates `v` by unit quaternion `q`.
// TODO(FGED §2.7.2): implement, either via the sandwich product
// q * (0,v) * conjugate(q), or the expanded matrix form — try both and
// compare, that's a good way to sanity-check ToRotationMatrix below.
Vector3D Rotate(const Quaternion& q, const Vector3D& v);

// Converts a unit quaternion to the equivalent Matrix3D.
// TODO(FGED §2.7.2): implement.
Matrix3D ToRotationMatrix(const Quaternion& q);

} // namespace fged
