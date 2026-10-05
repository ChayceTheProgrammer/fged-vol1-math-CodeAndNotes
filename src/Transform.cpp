#include "Transform.h"

namespace fged {

// TODO(FGED §2.2.1): implement.
Matrix3D MakeRotationX(float /*angle*/) { return Matrix3D(0,0,0, 0,0,0, 0,0,0); }
Matrix3D MakeRotationY(float /*angle*/) { return Matrix3D(0,0,0, 0,0,0, 0,0,0); }
Matrix3D MakeRotationZ(float /*angle*/) { return Matrix3D(0,0,0, 0,0,0, 0,0,0); }

// TODO(FGED §2.2.2): implement.
Matrix3D MakeRotation(float /*angle*/, const Vector3D& /*axis*/) {
    return Matrix3D(0,0,0, 0,0,0, 0,0,0);
}

// TODO(FGED §2.3): implement.
Matrix3D MakeReflection(const Vector3D& /*normal*/) {
    return Matrix3D(0,0,0, 0,0,0, 0,0,0);
}

// TODO(FGED §2.4): implement.
Matrix3D MakeScale(float /*sx*/, float /*sy*/, float /*sz*/) {
    return Matrix3D(0,0,0, 0,0,0, 0,0,0);
}

Matrix3D MakeScale(float /*scale*/, const Vector3D& /*dir*/) {
    return Matrix3D(0,0,0, 0,0,0, 0,0,0);
}

// TODO(FGED §2.5): implement.
Matrix3D MakeSkew(float /*angle*/, const Vector3D& /*dir*/, const Vector3D& /*perpDir*/) {
    return Matrix3D(0,0,0, 0,0,0, 0,0,0);
}

// TODO(FGED §2.6): implement.
Matrix4D MakeTransform(const Matrix3D& /*linear*/, const Vector3D& /*translation*/) {
    return Matrix4D(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0);
}

Vector3D TransformPoint(const Matrix4D& /*m*/, const Vector3D& /*point*/) {
    return Vector3D(0.0f, 0.0f, 0.0f);
}

Vector3D TransformVector(const Matrix4D& /*m*/, const Vector3D& /*dir*/) {
    return Vector3D(0.0f, 0.0f, 0.0f);
}

} // namespace fged
