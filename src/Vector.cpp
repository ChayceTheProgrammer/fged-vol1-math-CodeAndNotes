#include "Vector.h"
#include <cmath>

namespace fged {

// --- §1.2 Basic Vector Operations (boilerplate, already implemented) ----

//vector addition, subtraction, scalar multiplication and division
Vector3D& Vector3D::operator+=(const Vector3D& v) { x += v.x; y += v.y; z += v.z; return *this; }

Vector3D& Vector3D::operator-=(const Vector3D& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
Vector3D& Vector3D::operator*=(float s) { x *= s; y *= s; z *= s; return *this; }

//can be made more with reciprocal square root function for performance, but this is fine for now
Vector3D& Vector3D::operator/=(float s) { float inv = 1.0f / s; x *= inv; y *= inv; z *= inv; return *this; }

//vector addition, subtraction, negation, scalar multiplication and division
Vector3D operator+(const Vector3D& a, const Vector3D& b) { return Vector3D(a.x + b.x, a.y + b.y, a.z + b.z); }

Vector3D operator-(const Vector3D& v) { return Vector3D(-v.x, -v.y, -v.z); }
Vector3D operator*(const Vector3D& v, float s) { return Vector3D(v.x * s, v.y * s, v.z * s); }

Vector3D operator*(float s, const Vector3D& v) { return v * s; }
Vector3D operator/(const Vector3D& v, float s) { return v * (1.0f / s); }

// --- §1.2.1 Magnitude and Scalar Multiplication -------------------------
// TODO(FGED §1.2.1): implement. 
// ---Completed
float Magnitude(const Vector3D& v) {
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline Vector3D operator*(const Vector3D& v, float s) {
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

//slow division by scalar, but it works. Can be optimized later if needed.
inline Vector3D operator/(const Vector3D& v, float s) {
/*
1. Check if the scalar is zero to avoid division by zero.
2. If the scalar is zero, return a zero vector or handle the error as appropriate.
3. If the scalar is not zero, perform the division and return the resulting vector.
    s = 1.0f / s; // Calculate the reciprocal of the scalar
    return Vector3D(v.x * s, v.y * s, v.z * s); // Multiply each component of the vector by the reciprocal

*/
    //check if the scalar is zero to avoid division by zero.
    if (s == 0.0f) {
        // Handle the error as appropriate, e.g., return a zero vector or throw an exception
        return Vector3D(0.0f, 0.0f, 0.0f); // Return a zero vector as a placeholder
    }
    //Just in case
    else {
        s = 1.0f / s; // Calculate the reciprocal of the scalar
        return Vector3D(v.x * s, v.y * s, v.z * s); // Multiply each component of the vector by the reciprocal
    }

    //if all else fails just go with it bro
    return Vector3D(v.x / s, v.y / s, v.z / s);
}

//Subracton

//Multiplication
Vector3D *

// TODO(FGED §1.2.1): implement using Magnitude() above.
// ---Completed
Vector3D Normalize(const Vector3D& v) {
    float mag = Magnitude(v);
    /*
    if (mag == 0.0f) {
        return Vector3D(0.0f, 0.0f, 0.0f);
    }
    */
    return v / mag;
}

// --- §1.5 Vector Multiplication ------------------------------------------
// TODO(FGED §1.5.1): implement.
//returns the dot product of two vectors which is a scalar value representing 
//  the cosine of the angle between them multiplied by their magnitudes.
float Dot(const Vector3D& a, const Vector3D& b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

// TODO(FGED §1.5.2): implement.
Vector3D Cross(const Vector3D& /*a*/, const Vector3D& /*b*/) {
    return Vector3D(0.0f, 0.0f, 0.0f); // placeholder
}

// TODO(FGED §1.5.3): implement, ideally in terms of Dot and Cross.
float ScalarTripleProduct(const Vector3D& /*a*/, const Vector3D& /*b*/, const Vector3D& /*c*/) {
    return 0.0f; // placeholder
}

// --- §1.6 Vector Projection ------------------------------------------------
// TODO(FGED §1.6): implement.
Vector3D Project(const Vector3D& /*a*/, const Vector3D& /*b*/) {
    return Vector3D(0.0f, 0.0f, 0.0f); // placeholder
}

// TODO(FGED §1.6): implement as a - Project(a, b).
Vector3D Reject(const Vector3D& a, const Vector3D& b) {
    (void)a; (void)b;
    return Vector3D(0.0f, 0.0f, 0.0f); // placeholder
}

} // namespace fged
