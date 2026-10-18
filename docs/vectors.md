# Vector Fundamentals
Numerical Quantities in geometry, physics, and related fields are described w/ two main catagories:

| Scalars | Vectors |
| ------------ | --------- |
| Quantities can be described by a single number | object carries enough information to determine direction and magnitude |
| Ex's: Distance, Mass, Time | velocity, force, gravity |
| Value is called the magnitude of the scalar | contain a direction and magnitude |

Vectors are built of *components*. Each component refers to a specific spatial dimension.
This for a N-Dimensional Vector, we have n components.

Ex: 2D Vector v = <v_0, v_1>

We start the index at 0 to mirror memory access on a computer.

For traditional math (Linear Algebra), use 1 as initial index for simplicity

Spatially, vectors are *Oriented Magnitude with direction*

Any Vector with the same direction and same length is by definition the same vector. To Specify a vector we must give a reference origin point.

Here is a table of Properties and Description

Given Vectors: **a**, **b**, **c**
and scalars: *s*, *t*

| Property | Description |
|-------------------------|-------------------|
| (**a** + **b**) + **c**  = **a** + (**b** + **c**)| Associative Law for Vector addition |
| **a** + **b** = **b** + **a** | Communative law |
| (st)**a** = s(t**a**) | Associative Law fo scalar-vector multiplication |
| t**a** = **a**t| Communative law for scalar-vector multiplication|
|t(**a**+**b**) = t**a** + t**b** | Distributive Law for vect-scal multiplication |
|(s + t)**a** = s**a** + t**a**| Distributive Law for vector-scalar multiplication |

Visually:
(Insert  Gif Here)

Addition:
    **a** + **b**: \
    Tip of **a** to end of **b**

Subtraction: **a** - **b**: \
    Tip of **a** then negation of **b** so opposite direction same magnitude in the direction of b

