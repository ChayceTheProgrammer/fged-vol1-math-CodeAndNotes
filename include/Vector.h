#pragma once
// Chapter 1 — Vectors and Matrices
// Data types and operations for Vector3D (the book's primary vector type)
// and a minimal Vector4D used from Chapter 2 onward for homogeneous
// coordinates. Implementations live in src/Vector.cpp.

namespace fged {

// -------------------------------------------------------------------------
// Vector3D  — §1.1 Vector Fundamentals
// -------------------------------------------------------------------------
struct Vector3D {
    //vector components as members
    float x, y, z;
    Vector3D(float a, float b, float c) : x(a), y(b), z(c) {}

    float& operator[](int i) { return (&x)[i]; }
    
    // Access vector components by index. 0 -> x, 1 -> y, 2 -> z.
    const float& operator[](int i) const { return (&x)[i]; }

    // Default constructor and a constructor that takes three floats.
    Vector3D() = default;

    // --- §1.2 Basic Vector Operations --------------------------------
    // Boilerplate arithmetic — provided so the project compiles from the
    // start. Nothing here is the book's subject matter.
    Vector3D& operator+=(const Vector3D& v);
    Vector3D& operator-=(const Vector3D& v);
    Vector3D& operator*=(float s);
    Vector3D& operator/=(float s);
};

Vector3D operator+(const Vector3D& a, const Vector3D& b);
Vector3D operator-(const Vector3D& a, const Vector3D& b);
Vector3D operator-(const Vector3D& v);
Vector3D operator*(const Vector3D& v, float s);
Vector3D operator*(const Vector3D& a, const Vector3D& b); // Component-wise multiplication
Vector3D operator*(float s, const Vector3D& v);
Vector3D operator/(const Vector3D& v, float s);
Vector3D operator/(const Vector3D& a, const Vector3D& b); // Component-wise division    


// --- §1.2.1 Magnitude and Scalar Multiplication -----------------------
// TODO(FGED §1.2.1): implement the vector's magnitude (length).
float Magnitude(const Vector3D& v);

// Returns v scaled to unit length.
// TODO(FGED §1.2.1): implement using Magnitude() above.
Vector3D Normalize(const Vector3D& v);

// --- §1.5 Vector Multiplication ----------------------------------------
// TODO(FGED §1.5.1): implement the dot product.
float Dot(const Vector3D& a, const Vector3D& b);

// TODO(FGED §1.5.2): implement the cross product.
Vector3D Cross(const Vector3D& a, const Vector3D& b);

// TODO(FGED §1.5.3): implement the scalar triple product.
// (Hint: this should be expressible in terms of Dot and Cross above.)
float ScalarTripleProduct(const Vector3D& a, const Vector3D& b, const Vector3D& c);

// --- §1.6 Vector Projection ---------------------------------------------
// Projects `a` onto `b`, returning the parallel component.
// TODO(FGED §1.6): implement vector projection.
Vector3D Project(const Vector3D& a, const Vector3D& b);

// Returns the component of `a` perpendicular to `b`
// (i.e. a - Project(a, b)). Handy for Gram-Schmidt-style problems
// in the chapter exercises.
// TODO(FGED §1.6): implement the rejection.
Vector3D Reject(const Vector3D& a, const Vector3D& b);

// -------------------------------------------------------------------------
// Vector4D — introduced for §2.6 Homogeneous Coordinates, used from
// Chapter 2 onward. w == 1 for points, w == 0 for directions.
// -------------------------------------------------------------------------
struct Vector4D {
    float x, y, z, w;

    Vector4D() = default;
    Vector4D(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
    explicit Vector4D(const Vector3D& v, float w_) : x(v.x), y(v.y), z(v.z), w(w_) {}

    float& operator[](int i) { return (&x)[i]; }
    const float& operator[](int i) const { return (&x)[i]; }
};

} // namespace fged
