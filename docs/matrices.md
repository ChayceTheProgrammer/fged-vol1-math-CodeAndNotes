## Matrices ##

Remember we are starting the index at 0 to simulate computer memory

We specify a matrix like so:
$$
\mathbf{M} = \begin{bmatrix}
M_{00} & M_{01} & \cdots & M_{0,(m-1)} \\
M_{10} & M_{11} & \cdots & M_{1,(m-1)} \\
\vdots & \vdots & \ddots & \vdots \\
M_{(n-1),0} & M_{(n-1),1} & \cdots & M_{(n-1),(m-1)}
\end{bmatrix}
$$

with each element on the i-th row and j-th column.
We specify a specific element with the subscript

For Example:
Matrix M is a 2 x 3 matrix:
$$
\mathbf{M} = \begin{bmatrix}
1 & 2 & 3   \\
4 & 5 & 6   \\
\end{bmatrix}
$$
so 2 = $M_{0,2}$ & $M_{0,1}$ = 4

**The Square Matrix**

These matrces have the same number of rows and columns
Form:

M has n rows and n colsmns
$$
\mathbf{M} = \begin{bmatrix}
M_{00} & \cdots & M_{0,(n-1)}  \\
\vdots & M_{11} & \vdots \\
M_{(n-1),0} &  \cdots & M_{(n-1),(n-1)}
\end{bmatrix}
$$

We should recogiize the entries on the diagonal of the matrix:  \\ entries on the $M_(i,j)$ where $i=j$

Other elements are off-duagonal entries

Any Matrix where the only non zero elements are on the diagonal is known as the a **diagonal matrix**
