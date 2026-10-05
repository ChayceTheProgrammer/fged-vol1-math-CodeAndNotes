#pragma once
// A deliberately tiny test harness — no external dependencies to
// install, just macros. Each chapter's test file registers checks by
// calling these macros inside a `void RunChapterNTests()` function.

#include <cstdio>
#include <cmath>

namespace fged_test {
inline int g_run = 0;
inline int g_failed = 0;
} // namespace fged_test

#define CHECK_NEAR(actual, expected, epsilon)                                \
    do {                                                                     \
        ++fged_test::g_run;                                                  \
        double _fged_a = static_cast<double>(actual);                        \
        double _fged_e = static_cast<double>(expected);                      \
        if (std::fabs(_fged_a - _fged_e) > (epsilon)) {                      \
            ++fged_test::g_failed;                                           \
            std::printf("  FAIL  %s:%d  %s\n         got %.6f, expected %.6f (+/- %g)\n", \
                        __FILE__, __LINE__, #actual, _fged_a, _fged_e, (double)(epsilon)); \
        }                                                                     \
    } while (0)

#define CHECK_VEC3_NEAR(actual, ex, ey, ez, epsilon)                         \
    do {                                                                     \
        auto _fged_v = (actual);                                             \
        CHECK_NEAR(_fged_v.x, (ex), (epsilon));                              \
        CHECK_NEAR(_fged_v.y, (ey), (epsilon));                              \
        CHECK_NEAR(_fged_v.z, (ez), (epsilon));                              \
    } while (0)

#define CHECK_TRUE(cond)                                                     \
    do {                                                                     \
        ++fged_test::g_run;                                                  \
        if (!(cond)) {                                                       \
            ++fged_test::g_failed;                                           \
            std::printf("  FAIL  %s:%d  %s\n", __FILE__, __LINE__, #cond);   \
        }                                                                     \
    } while (0)

#define TEST_SECTION(name) std::printf("\n-- %s --\n", name)
