#pragma once
// Chapter 2 — Transforms
// Free functions that build transformation matrices. Each one returns a
// Matrix3D (linear part only) except where the section explicitly needs
// the 4x4 homogeneous form (translation).

#include "Vector.h"
#include "Matrix.h"

namespace fged {

// --- §2.2.1 Rotation About a Coordinate Axis ----------------------------
// `angle` is in radians.
// TODO(FGED §2.2.1): implement each axis-aligned rotation matrix.
Matrix3D MakeRotationX(float angle);
Matrix3D MakeRotationY(float angle);
Matrix3D MakeRotationZ(float angle);

// --- §2.2.2 Rotation About an Arbitrary Axis ----------------------------
// `axis` is assumed to already be a unit vector.
// TODO(FGED §2.2.2): implement Rodrigues'-style arbitrary-axis rotation.
Matrix3D MakeRotation(float angle, const Vector3D& axis);

// --- §2.3 Reflections -----------------------------------------------------
// Reflection through the plane whose normal is `normal` (unit vector),
// passing through the origin.
// TODO(FGED §2.3): implement.
Matrix3D MakeReflection(const Vector3D& normal);

// --- §2.4 Scales -----------------------------------------------------------
// Axis-aligned scale.
// TODO(FGED §2.4): implement.
Matrix3D MakeScale(float sx, float sy, float sz);

// Scale by `scale` along an arbitrary unit direction `dir`, leaving the
// perpendicular subspace unchanged.
// TODO(FGED §2.4): implement the general form.
Matrix3D MakeScale(float scale, const Vector3D& dir);

// --- §2.5 Skews --------------------------------------------------------------
// Skews vectors along `dir` by `angle`, proportional to their component
// along `perpDir`. `dir` and `perpDir` must be orthogonal unit vectors.
// TODO(FGED §2.5): implement.
Matrix3D MakeSkew(float angle, const Vector3D& dir, const Vector3D& perpDir);

// --- §2.6 Homogeneous Coordinates -------------------------------------------
// Builds a 4x4 transform combining a 3x3 linear part with a translation.
// TODO(FGED §2.6): implement — this is mostly bookkeeping once you
// understand how translation fits into the homogeneous 4x4 form.
Matrix4D MakeTransform(const Matrix3D& linear, const Vector3D& translation);

// Convenience wrappers so playground code reads naturally: points carry
// translation (w=1), directions/vectors don't (w=0).
// TODO(FGED §2.6): implement both in terms of Matrix4D * Vector4D.
Vector3D TransformPoint(const Matrix4D& m, const Vector3D& point);
Vector3D TransformVector(const Matrix4D& m, const Vector3D& dir);

} // namespace fged
