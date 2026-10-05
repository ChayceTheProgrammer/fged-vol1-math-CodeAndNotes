#include "Bivector.h"

namespace fged {

// TODO(FGED §4.1.1): implement.
Bivector3D Wedge(const Vector3D& /*a*/, const Vector3D& /*b*/) {
    return Bivector3D(0.0f, 0.0f, 0.0f);
}

// TODO(FGED §4.1.3): implement.
float Wedge(const Vector3D& /*a*/, const Bivector3D& /*b*/) {
    return 0.0f;
}

// TODO(FGED §4.1.5): implement both directions.
Bivector3D Complement(const Vector3D& /*v*/) {
    return Bivector3D(0.0f, 0.0f, 0.0f);
}

Vector3D Complement(const Bivector3D& /*b*/) {
    return Vector3D(0.0f, 0.0f, 0.0f);
}

// TODO(FGED §4.1.7): implement.
float Antiwedge(const Vector3D& /*v*/, const Bivector3D& /*b*/) {
    return 0.0f;
}

// TODO(FGED §4.2.3): implement.
Line2D Join(const Point2D& /*p*/, const Point2D& /*q*/) {
    return Line2D{0.0f, 0.0f, 0.0f};
}

Point2D Meet(const Line2D& /*a*/, const Line2D& /*b*/) {
    return Point2D{0.0f, 0.0f, 0.0f};
}

// TODO(FGED §4.4.3): implement.
Rotor3D MakeRotor(float /*angle*/, const Bivector3D& /*plane*/) {
    return Rotor3D{1.0f, Bivector3D(0.0f, 0.0f, 0.0f)};
}

Vector3D Rotate(const Rotor3D& /*r*/, const Vector3D& /*v*/) {
    return Vector3D(0.0f, 0.0f, 0.0f);
}

} // namespace fged
