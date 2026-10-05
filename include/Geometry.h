#pragma once
// Chapter 3 — Geometry

#include "Vector.h"
#include "Matrix.h"
#include <vector>

namespace fged {

// --- §3.1 Triangle Meshes / §3.2 Normal Vectors ---------------------------
// Minimal mesh representation: positions plus index triples. Enough to
// exercise face-normal calculation without pulling in a full mesh format.
struct Triangle {
    int a, b, c; // indices into a Vector3D position array
};

// Computes the (unnormalized, then normalized) face normal for triangle
// `t` given the mesh's vertex positions.
// TODO(FGED §3.2.1): implement using Cross() from Vector.h.
Vector3D ComputeFaceNormal(const std::vector<Vector3D>& positions, const Triangle& t);

// Transforms a normal vector correctly under a (possibly non-uniform)
// linear transform `m` — this is *not* just m * n. Read §3.2.2 before
// implementing; it's a common source of subtly wrong lighting bugs.
// TODO(FGED §3.2.2): implement.
Vector3D TransformNormal(const Matrix3D& m, const Vector3D& n);

// --- §3.3 Lines and Rays ---------------------------------------------------
// A parametric line: point + t * direction.
struct Line {
    Vector3D point;
    Vector3D direction; // not required to be normalized; note in your
                         // implementation whether you assume it is.
};

// TODO(FGED §3.3.2): implement point-to-line distance.
float DistancePointToLine(const Vector3D& q, const Line& line);

// TODO(FGED §3.3.3): implement line-to-line distance (skew lines in 3D
// generally don't intersect — this is the closest-approach distance).
float DistanceLineToLine(const Line& a, const Line& b);

// --- §3.4 Planes ------------------------------------------------------------
// Implicit plane: normal.x*x + normal.y*y + normal.z*z + d == 0
struct Plane {
    Vector3D normal;
    float d;
};

// TODO(FGED §3.4.2): implement signed point-to-plane distance.
float DistancePointToPlane(const Vector3D& q, const Plane& plane);

// TODO(FGED §3.4.3): implement reflection of a point through a plane.
Vector3D ReflectThroughPlane(const Vector3D& q, const Plane& plane);

// Returns true and writes the intersection point to `outPoint` if the
// line and plane intersect at a single point.
// TODO(FGED §3.4.4): implement.
bool IntersectLinePlane(const Line& line, const Plane& plane, Vector3D& outPoint);

// Returns true and writes the intersection point if all three planes
// meet at a single point.
// TODO(FGED §3.4.5): implement.
bool IntersectThreePlanes(const Plane& p1, const Plane& p2, const Plane& p3, Vector3D& outPoint);

// Returns true and writes the intersection line if the two planes meet
// along a line (i.e. aren't parallel).
// TODO(FGED §3.4.6): implement.
bool IntersectTwoPlanes(const Plane& p1, const Plane& p2, Line& outLine);

// Transforms a plane correctly under transform `m` — like normals,
// planes do *not* transform the same way points do.
// TODO(FGED §3.4.7): implement.
Plane TransformPlane(const Matrix3D& m, const Vector3D& translation, const Plane& plane);

// --- §3.5 Plücker Coordinates -----------------------------------------------
// A line represented by its Plücker coordinates (direction + moment).
// This is genuinely new territory even if you're comfortable with the
// rest of the chapter — read §3.5.1–3.5.2 carefully before implementing.
struct PluckerLine {
    Vector3D direction;
    Vector3D moment;
};

// TODO(FGED §3.5.1): build the Plücker representation of the line
// through points p and q.
PluckerLine MakePluckerLine(const Vector3D& p, const Vector3D& q);

// TODO(FGED §3.5.2): implement the homogeneous side-operator test used
// to determine whether two lines intersect / their relative orientation.
float PluckerSideOperator(const PluckerLine& a, const PluckerLine& b);

} // namespace fged
