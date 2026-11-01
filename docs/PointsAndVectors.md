# Vector & Point (Affine & Homogeneous Spaces)

## 1. Mathematical Definition
In conventional 3D Euclidean space:
* **Direction Vector** $\mathbf{v} = \begin{bmatrix} v_x & v_y & v_z \end{bmatrix}^T$: Represents direction and magnitude without a fixed location in space.
* **Point / Position Vector** $\mathbf{p} = \begin{bmatrix} p_x & p_y & p_z \end{bmatrix}^T$: Represents a specific location relative to a chosen coordinate origin.

In **4D Homogeneous Coordinates** ($\mathbb{R}^4$ projective space $\mathbb{P}^3$):
$$\mathbf{P} = \begin{bmatrix} x \\ y \\ z \\ w \end{bmatrix}$$
* When $w = 1$, $\mathbf{P}$ represents a finite point with Cartesian coordinates $(x, y, z)$.
* When $w = 0$, $\mathbf{P}$ represents a pure direction vector (a point at infinity).
* In general, for $w \neq 0$, the projected Euclidean point is $\left(\frac{x}{w}, \frac{y}{w}, \frac{z}{w}\right)$.

---

## 2. Algebraic Operations
* **Vector Norm / Magnitude**:
  $$\|\mathbf{v}\| = \sqrt{v_x^2 + v_y^2 + v_z^2} = \sqrt{\mathbf{v} \cdot \mathbf{v}}$$
* **Dot Product**:
  $$\mathbf{a} \cdot \mathbf{b} = a_x b_x + a_y b_y + a_z b_z = \|\mathbf{a}\| \|\mathbf{b}\| \cos\theta$$
* **Cross Product** (3D vectors):
  $$\mathbf{a} \times \mathbf{b} = \begin{bmatrix} a_y b_z - a_z b_y \\ a_z b_x - a_x b_z \\ a_x b_y - a_y b_x \end{bmatrix}, \quad \|\mathbf{a} \times \mathbf{b}\| = \|\mathbf{a}\| \|\mathbf{b}\| \sin\theta$$
* **Scalar Triple Product**:
  $$[\mathbf{a}, \mathbf{b}, \mathbf{c}] = (\mathbf{a} \times \mathbf{b}) \cdot \mathbf{c} = \det \begin{bmatrix} \mathbf{a} & \mathbf{b} & \mathbf{c} \end{bmatrix}$$

---

## 3. Transformation Properties
* Given an affine transformation matrix $\mathbf{H} = \begin{bmatrix} \mathbf{M} & \mathbf{t} \\ \mathbf{0}^T & 1 \end{bmatrix}$:
  * **Point Transformation**: $\mathbf{p}' = \mathbf{M}\mathbf{p} + \mathbf{t}$
  * **Direction Transformation**: $\mathbf{v}' = \mathbf{M}\mathbf{v}$ (invariant to translation $\mathbf{t}$)

---

## 4. Exterior / Grassmann Algebra Formulation
* In 4D Grassmann algebra, a point is represented as a **grade-1 element (vector)**:
  $$\mathbf{p} = p_x \mathbf{e}_1 + p_y \mathbf{e}_2 + p_z \mathbf{e}_3 + p_w \mathbf{e}_4$$
* The **Wedge Product (Join)** of two points forms an oriented line:
  $$\mathbf{L} = \mathbf{p}_1 \wedge \mathbf{p}_2$$
* The **Join** of three points forms an oriented plane:
  $$\mathbf{f} = \mathbf{p}_1 \wedge \mathbf{p}_2 \wedge \mathbf{p}_3$$
