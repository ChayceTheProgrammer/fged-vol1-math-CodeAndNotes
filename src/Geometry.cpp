#include "Geometry.h"

namespace fged {

// TODO(FGED §3.2.1): implement.
Vector3D ComputeFaceNormal(const std::vector<Vector3D>& /*positions*/, const Triangle& /*t*/) {
    return Vector3D(0.0f, 0.0f, 0.0f);
}

// TODO(FGED §3.2.2): implement.
Vector3D TransformNormal(const Matrix3D& /*m*/, const Vector3D& /*n*/) {
    return Vector3D(0.0f, 0.0f, 0.0f);
}

// TODO(FGED §3.3.2): implement.
float DistancePointToLine(const Vector3D& /*q*/, const Line& /*line*/) {
    return 0.0f;
}

// TODO(FGED §3.3.3): implement.
float DistanceLineToLine(const Line& /*a*/, const Line& /*b*/) {
    return 0.0f;
}

// TODO(FGED §3.4.2): implement.
float DistancePointToPlane(const Vector3D& /*q*/, const Plane& /*plane*/) {
    return 0.0f;
}

// TODO(FGED §3.4.3): implement.
Vector3D ReflectThroughPlane(const Vector3D& /*q*/, const Plane& /*plane*/) {
    return Vector3D(0.0f, 0.0f, 0.0f);
}

// TODO(FGED §3.4.4): implement.
bool IntersectLinePlane(const Line& /*line*/, const Plane& /*plane*/, Vector3D& outPoint) {
    outPoint = Vector3D(0.0f, 0.0f, 0.0f);
    return false;
}

// TODO(FGED §3.4.5): implement.
bool IntersectThreePlanes(const Plane& /*p1*/, const Plane& /*p2*/, const Plane& /*p3*/, Vector3D& outPoint) {
    outPoint = Vector3D(0.0f, 0.0f, 0.0f);
    return false;
}

// TODO(FGED §3.4.6): implement.
bool IntersectTwoPlanes(const Plane& /*p1*/, const Plane& /*p2*/, Line& outLine) {
    outLine = Line{Vector3D(0,0,0), Vector3D(0,0,0)};
    return false;
}

// TODO(FGED §3.4.7): implement.
Plane TransformPlane(const Matrix3D& /*m*/, const Vector3D& /*translation*/, const Plane& /*plane*/) {
    return Plane{Vector3D(0.0f, 0.0f, 0.0f), 0.0f};
}

// TODO(FGED §3.5.1): implement.
PluckerLine MakePluckerLine(const Vector3D& /*p*/, const Vector3D& /*q*/) {
    return PluckerLine{Vector3D(0,0,0), Vector3D(0,0,0)};
}

// TODO(FGED §3.5.2): implement.
float PluckerSideOperator(const PluckerLine& /*a*/, const PluckerLine& /*b*/) {
    return 0.0f;
}

} // namespace fged
