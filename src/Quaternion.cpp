#include "Quaternion.h"

namespace fged {

// TODO(FGED §2.7.1): implement the Hamilton product.
Quaternion operator*(const Quaternion& /*a*/, const Quaternion& /*b*/) {
    return Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
}

// TODO(FGED §2.7.1): implement.
float Magnitude(const Quaternion& /*q*/) {
    return 0.0f;
}

// TODO(FGED §2.7.1): implement.
Quaternion Normalize(const Quaternion& /*q*/) {
    return Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
}

// TODO(FGED §2.7.1): implement.
Quaternion Conjugate(const Quaternion& /*q*/) {
    return Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
}

// TODO(FGED §2.7.2): implement.
Quaternion MakeRotationQuaternion(float /*angle*/, const Vector3D& /*axis*/) {
    return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
}

// TODO(FGED §2.7.2): implement.
Vector3D Rotate(const Quaternion& /*q*/, const Vector3D& /*v*/) {
    return Vector3D(0.0f, 0.0f, 0.0f);
}

// TODO(FGED §2.7.2): implement.
Matrix3D ToRotationMatrix(const Quaternion& /*q*/) {
    return Matrix3D(0,0,0, 0,0,0, 0,0,0);
}

} // namespace fged
