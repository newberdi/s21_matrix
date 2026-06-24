# s21_matrix

Custom implementation of a matrix manipulation library in C.

The project provides fundamental linear algebra operations, including matrix arithmetic, determinant calculation, matrix inversion, transposition, and computation of algebraic complements.

## Overview

Matrices are widely used in scientific computing, computer graphics, simulations, machine learning, and numerical methods.

This library implements a dynamic matrix type and a set of core matrix operations without relying on external mathematical libraries.

## Matrix Representation

Matrices are stored using a dynamically allocated two-dimensional array:

```c
typedef struct matrix_struct {
    double **matrix;
    int rows;
    int columns;
} matrix_t;
```

The library supports matrices of arbitrary dimensions, limited only by available system memory.

## Features

### Matrix Management

Creation and destruction of matrices:

```c
s21_create_matrix()
s21_remove_matrix()
```

### Matrix Comparison

Comparison with floating-point precision tolerance:

```c
s21_eq_matrix()
```

Comparison accuracy is up to 1e-7.

### Arithmetic Operations

Addition and subtraction:

```c
s21_sum_matrix()
s21_sub_matrix()
```

Scalar multiplication:

```c
s21_mult_number()
```

Matrix multiplication:

```c
s21_mult_matrix()
```

### Matrix Transformations

Transpose operation:

```c
s21_transpose()
```

### Advanced Linear Algebra

Determinant calculation:

```c
s21_determinant()
```

Algebraic complements (cofactor matrix):

```c
s21_calc_complements()
```

Inverse matrix calculation:

```c
s21_inverse_matrix()
```

The inverse matrix is computed using:

```text
A⁻¹ = (1 / det(A)) × Cof(A)ᵀ
```

## Algorithms

Several matrix operations are implemented using classical linear algebra algorithms.

### Determinant Calculation

The determinant is computed recursively using Laplace expansion along the first row.

Implementation details:

- Direct formulas for 1×1 and 2×2 matrices.
- Recursive construction of matrix minors for larger matrices.
- Cofactor expansion with alternating signs.
- Dynamic allocation of temporary minor matrices.

Formula:

det(A) = Σ (-1)^j · a₀ⱼ · M₀ⱼ

where M₀ⱼ is the determinant of the corresponding minor matrix.

This approach prioritizes correctness and readability over asymptotic performance and is well suited for educational and moderate-sized matrices.

## Error Handling

All operations validate:

* matrix correctness;
* dimensions compatibility;
* determinant existence;
* inverse matrix availability.

Standardized return codes are used to report calculation and validation errors.

## Technical Details

* Language: C11
* Compiler: GCC
* Build system: Makefile
* Testing framework: Check
* Coverage analysis: gcov
* Style guide: Google C Style

## Build

Build the library:

```bash
make s21_matrix.a
```

Run tests:

```bash
make test
```

Generate coverage report:

```bash
make gcov_report
```

