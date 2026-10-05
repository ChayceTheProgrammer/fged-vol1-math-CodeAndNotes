#include "test_framework.h"
#include "Vector.h"
#include "Bivector.h"

using namespace fged;

// Chapter 4 introduces genuinely new notation, and the exact component
// ordering/sign convention for a bivector is a choice the book makes
// explicitly (see Sec 4.1.2) -- rather than guess at hard-coded numeric
// answers that might not match the convention you implement, these
// checks verify algebraic *identities* that must hold no matter which
// consistent convention you pick. If one of these fails, the bug is
// real; it isn't a convention mismatch.

void RunChapter4Tests() {
    TEST_SECTION("Chapter 4 -- Sec 4.1.1 Wedge product identities");
    {
        Vector3D a(1, 2, 3), b(4, -1, 2);

        // Antisymmetry: a ^ b == -(b ^ a)
        Bivector3D ab = Wedge(a, b);
        Bivector3D ba = Wedge(b, a);
        CHECK_NEAR(ab.x, -ba.x, 1e-4f);
        CHECK_NEAR(ab.y, -ba.y, 1e-4f);
        CHECK_NEAR(ab.z, -ba.z, 1e-4f);

        // Any vector wedged with itself is the zero bivector.
        Bivector3D aa = Wedge(a, a);
        CHECK_NEAR(aa.x, 0.0f, 1e-4f);
        CHECK_NEAR(aa.y, 0.0f, 1e-4f);
        CHECK_NEAR(aa.z, 0.0f, 1e-4f);
    }

    TEST_SECTION("Chapter 4 -- Sec 4.1.5 Complement is an involution");
    {
        Vector3D v(1, 2, 3);
        Vector3D back = Complement(Complement(v));
        CHECK_VEC3_NEAR(back, v.x, v.y, v.z, 1e-4f);

        Bivector3D bv(1, -2, 0.5f);
        Bivector3D bvBack = Complement(Complement(bv));
        CHECK_NEAR(bvBack.x, bv.x, 1e-4f);
        CHECK_NEAR(bvBack.y, bv.y, 1e-4f);
        CHECK_NEAR(bvBack.z, bv.z, 1e-4f);
    }

    TEST_SECTION("Chapter 4 -- Sec 4.4.3 Rotors");
    {
        Vector3D v(1, 0, 0);
        Bivector3D plane = Wedge(Vector3D(1, 0, 0), Vector3D(0, 1, 0)); // the xy-plane

        // A zero-angle rotor must be the identity.
        Rotor3D identity = MakeRotor(0.0f, plane);
        CHECK_VEC3_NEAR(Rotate(identity, v), v.x, v.y, v.z, 1e-4f);

        // Rotation preserves length, for any angle.
        Rotor3D r = MakeRotor(0.7f, plane);
        Vector3D rotated = Rotate(r, v);
        CHECK_NEAR(Magnitude(rotated), Magnitude(v), 1e-4f);
    }

    // Sec 4.2 (Join/Meet in projective geometry) isn't checked here --
    // work those by hand in playground/ch04_playground.cpp against the
    // book's own worked examples once you've read 4.2.1-4.2.6.
}
