# FGED Vol. 1 — Reading Companion Codebase

A VS Code / CMake project for working through *Foundations of Game Engine
Development, Volume 1: Mathematics* by Eric Lengyel, hands-on.

## How this is organized

The library grows the same way the book does — later chapters build on
data types from earlier ones, so `include/` and `src/` are **not** split
by chapter. Instead, each header maps to the book topic it covers, and
the *implementations you write* are grouped into stub functions tagged
with the exact section they belong to:

| File | Book chapter | Covers |
|---|---|---|
| `include/Vector.h` / `src/Vector.cpp` | Ch. 1 §1.1–1.2, 1.5, 1.6 | Vector2D/3D/4D, dot/cross/scalar-triple product, projection |
| `include/Matrix.h` / `src/Matrix.cpp` | Ch. 1 §1.3, 1.4, 1.7 | Matrix3D/4D, multiplication, determinant, inversion |
| `include/Transform.h` / `src/Transform.cpp` | Ch. 2 | Rotation, reflection, scale, skew, homogeneous coordinates |
| `include/Quaternion.h` / `src/Quaternion.cpp` | Ch. 2 §2.7 | Quaternion fundamentals and rotation |
| `include/Geometry.h` / `src/Geometry.cpp` | Ch. 3 | Normals, lines, planes, Plücker coordinates |
| `include/Bivector.h` / `src/Bivector.cpp` | Ch. 4 | Grassmann algebra, projective geometry, rotors |

Every function you actually need to write is declared already (so the
project builds from the start) but its **body is a stub** — a comment
pointing at the exact book section, and a placeholder return value that
will make the matching test fail until you implement it. That failing
test is your progress bar.

```
fged-vol1-math/
├── include/         headers — data types + declared-but-stubbed operations
├── src/             matching .cpp files — this is where you write code
├── tests/           small hand-checked test cases per chapter (run via `ctest` or the test binary)
├── playground/      one scratch .cpp per chapter for the book's own exercises
└── docs/progress_checklist.md   check off sections as you go
```

## Workflow

1. Read a section in the book (e.g., §1.5.2 Cross Product).
2. Open the matching `.cpp` file (`src/Vector.cpp`) and find the stub
   tagged `// TODO(FGED §1.5.2)`.
3. Implement it.
4. Build and run the tests — the case tied to that section should turn green.
5. Use `playground/ch01_playground.cpp` to work the chapter's end-of-chapter
   exercises, and check the box in `docs/progress_checklist.md`.

No solutions are included on purpose — the book's own worked examples and
your test results are the answer key. If a test result looks wrong,
that's the signal to re-read the section, not to guess at the API.

## Setup

**Prerequisites**: [CMake](https://cmake.org/download/) 3.15+, a C++17
compiler (g++, clang, or MSVC), and VS Code with two extensions:
- **C/C++** (`ms-vscode.cpptools`)
- **CMake Tools** (`ms-vscode.cmake-tools`)

CMake Tools auto-detects the compiler and wires up IntelliSense — you
don't need to hand-edit any `c_cpp_properties.json`.

## Build & run

Open the folder in VS Code, let CMake Tools configure it (bottom status
bar → pick a kit), then:

- **Build everything**: `Ctrl+Shift+P` → `CMake: Build`, or press `F7`.
- **Run the test suite**: `Ctrl+Shift+P` → `CMake: Run Tests`, or use the
  `Build and Run Tests` task in `.vscode/tasks.json` (`Ctrl+Shift+B`).
- **Run a chapter's playground**: pick the `ch0N_playground` target in
  the CMake Tools status bar as the "launch target," then `F5` to debug.

Command line, if you'd rather skip the IDE:

```bash
cmake -B build -S .
cmake --build build
ctest --test-dir build --output-on-failure
```

## A note on scope

This scaffold implements the plumbing (constructors, component access,
basic arithmetic operators) so the project compiles immediately. It
deliberately does **not** implement anything that's actually the book's
subject matter — magnitude, products, matrix inversion, rotation
construction, normal transforms, plane intersections, wedge products,
and so on are all left for you, section by section. That's the point.