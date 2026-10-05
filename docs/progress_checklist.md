# Progress checklist

Check items off as you implement the matching stub and its test goes
green. Section numbers match the book's table of contents.

## Chapter 1 — Vectors and Matrices
- [ ] 1.2.1 Magnitude and Scalar Multiplication — `Magnitude`, `Normalize`
- [ ] 1.5.1 Dot Product — `Dot`
- [ ] 1.5.2 Cross Product — `Cross`
- [ ] 1.5.3 Scalar Triple Product — `ScalarTripleProduct`
- [ ] 1.6 Vector Projection — `Project`, `Reject`
- [ ] 1.4.2 Matrix Multiplication — `operator*(Matrix3D, Matrix3D)`, `operator*(Matrix3D, Vector3D)`
- [ ] 1.7.1 Identity Matrices — `Identity3D`, `Identity4D`
- [ ] 1.7.2 Determinants — `Determinant`
- [ ] 1.7.4/1.7.5 Inverse Calculation — `Inverse` (3x3)
- [ ] Exercises for Chapter 1 worked in `playground/ch01_playground.cpp`

## Chapter 2 — Transforms
- [ ] 2.2.1 Rotation About a Coordinate Axis — `MakeRotationX/Y/Z`
- [ ] 2.2.2 Rotation About an Arbitrary Axis — `MakeRotation`
- [ ] 2.3 Reflections — `MakeReflection`
- [ ] 2.4 Scales — `MakeScale` (both overloads)
- [ ] 2.5 Skews — `MakeSkew`
- [ ] 2.6 Homogeneous Coordinates — `MakeTransform`, `TransformPoint`, `TransformVector`, 4x4 `Inverse`
- [ ] 2.7.1 Quaternion Fundamentals — Hamilton product, `Magnitude`, `Normalize`, `Conjugate`
- [ ] 2.7.2 Rotations With Quaternions — `MakeRotationQuaternion`, `Rotate`, `ToRotationMatrix`
- [ ] Exercises for Chapter 2 worked in `playground/ch02_playground.cpp`

## Chapter 3 — Geometry
- [ ] 3.2.1 Calculating Normal Vectors — `ComputeFaceNormal`
- [ ] 3.2.2 Transforming Normal Vectors — `TransformNormal`
- [ ] 3.3.2 Distance Between a Point and a Line — `DistancePointToLine`
- [ ] 3.3.3 Distance Between Two Lines — `DistanceLineToLine`
- [ ] 3.4.2 Distance Between a Point and a Plane — `DistancePointToPlane`
- [ ] 3.4.3 Reflection Through a Plane — `ReflectThroughPlane`
- [ ] 3.4.4 Intersection of a Line and a Plane — `IntersectLinePlane`
- [ ] 3.4.5 Intersection of Three Planes — `IntersectThreePlanes`
- [ ] 3.4.6 Intersection of Two Planes — `IntersectTwoPlanes`
- [ ] 3.4.7 Transforming Planes — `TransformPlane`
- [ ] 3.5 Plücker Coordinates — `MakePluckerLine`, `PluckerSideOperator`
- [ ] Exercises for Chapter 3 worked in `playground/ch03_playground.cpp`

## Chapter 4 — Advanced Algebra
- [ ] 4.1.1 Wedge Product — `Wedge(Vector3D, Vector3D)`
- [ ] 4.1.3 Trivectors — `Wedge(Vector3D, Bivector3D)`
- [ ] 4.1.5 Complements — `Complement` (both directions)
- [ ] 4.1.7 Antiwedge Product — `Antiwedge`
- [ ] 4.2.3 Join and Meet — `Join`, `Meet`
- [ ] 4.4.3 Rotors — `MakeRotor`, `Rotate(Rotor3D, ...)`
- [ ] Exercises for Chapter 4 worked in `playground/ch04_playground.cpp`

---

Run the full suite any time with `./build/tests/fged_tests` (or the
CMake Tools "Run Tests" command) to see exactly which sections still
need work.
