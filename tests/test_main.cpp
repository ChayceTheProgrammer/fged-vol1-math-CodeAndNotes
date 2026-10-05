#include "test_framework.h"
#include <cstdio>

void RunChapter1Tests();
void RunChapter2Tests();
void RunChapter3Tests();
void RunChapter4Tests();

int main() {
    std::printf("FGED Vol. 1 reading companion -- test suite\n");
    std::printf("Each failure names the book section its function covers.\n");

    RunChapter1Tests();
    RunChapter2Tests();
    RunChapter3Tests();
    RunChapter4Tests();

    std::printf("\n=====================================\n");
    std::printf("%d checks run, %d failed, %d passed\n",
                fged_test::g_run, fged_test::g_failed,
                fged_test::g_run - fged_test::g_failed);

    return fged_test::g_failed == 0 ? 0 : 1;
}
