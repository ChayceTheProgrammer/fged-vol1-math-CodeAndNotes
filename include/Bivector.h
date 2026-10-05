#pragma once
// Chapter 4 — Advanced Algebra
//
// This chapter is genuinely new material, not just a restatement of
// Chapters 1-3 in fancier notation. Read the corresponding section in
// full — including the worked examples — before attempting each stub;
// guessing at the API from the function signature alone won't work here
// the way it might for, say, the cross product.

#include "Vector.h"

namespace fged {

// --- §4.1.2 Bivectors -----------------------------------------------------
// A bivector represents an oriented area element (as opposed to a
// vector's oriented line element). In 3D it has three components, same
// as a vector, but they transform differently under reflection — that
// distinction is the point of this section.
struct Bivector3D {
    float x, y, z; // conventionally written yz, zx, xy

    Bivector3D() = default;
    Bivector3D(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
};

// --- §4.1.1 Wedge Product --------------------------------------------------
// The wedge product of two vectors produces a bivector — the area
// element they span. Compare your result against Cross() from
// Vector.h once implemented; §4.1 explains exactly how they relate.
// TODO(FGED §4.1.1): implement.
Bivector3D Wedge(const Vector3D& a, const Vector3D& b);

// --- §4.1.3 Trivectors ------------------------------------------------------
// In 3D, the wedge of three vectors is a trivector, which has only one
// independent component (the "pseudoscalar" of the space) — represented
// here as a plain float.
// TODO(FGED §4.1.3): implement.
float Wedge(const Vector3D& a, const Bivector3D& b);

// --- §4.1.5 Complements ------------------------------------------------------
// The complement maps a k-vector to its "dual" (n-k)-vector. In 3D this
// maps vectors <-> bivectors.
// TODO(FGED §4.1.5): implement both directions.
Bivector3D Complement(const Vector3D& v);
Vector3D Complement(const Bivector3D& b);

// --- §4.1.7 Antiwedge Product ------------------------------------------------
// The dual operation to Wedge — combines a vector and a bivector into a
// scalar via complements. Used heavily in §4.2's projective geometry.
// TODO(FGED §4.1.7): implement, likely in terms of Wedge + Complement.
float Antiwedge(const Vector3D& v, const Bivector3D& b);

// --- §4.2 Projective Geometry -------------------------------------------------
// Homogeneous points and lines in the projective plane, using the
// Grassmann machinery above. See §4.2.6 for the full worked summary
// before implementing these.
struct Point2D { float x, y, w; };  // homogeneous 2D point
struct Line2D { float x, y, w; };   // homogeneous 2D line (dual to a point)

// TODO(FGED §4.2.3): the line through two points ("join").
Line2D Join(const Point2D& p, const Point2D& q);

// TODO(FGED §4.2.3): the point where two lines cross ("meet").
Point2D Meet(const Line2D& a, const Line2D& b);

// --- §4.4 Geometric Algebra ---------------------------------------------------
// A rotor is geometric algebra's rotation operator — related to, but
// derived differently from, the quaternion in Quaternion.h. Section 4.4
// builds this up via the geometric product; worth implementing
// Quaternion.h first so you have something to compare against.
struct Rotor3D {
    float scalar;       // grade-0 part
    Bivector3D bivector; // grade-2 part
};

// TODO(FGED §4.4.3): construct a rotor for a rotation of `angle` radians
// in the plane represented by unit bivector `plane`.
Rotor3D MakeRotor(float angle, const Bivector3D& plane);

// TODO(FGED §4.4.3): apply a rotor to a vector.
Vector3D Rotate(const Rotor3D& r, const Vector3D& v);

} // namespace fged
