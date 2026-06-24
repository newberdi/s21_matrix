#include "s21_matrix.h"

// Вычисляет определитель квадратной матрицы

int s21_determinant(matrix_t *A, double *result) {
  if (!correct_matrix(A) || result == NULL) return INVALID_MATRIX;

  int status = OK;
  if (!is_square(A)) status = CALCULATION_ERROR;

  if (A->rows == 1) {
    *result = A->matrix[0][0];
    return status;
  }

  if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    return status;
  }
  //  для матриц размером 3x3 и больше
  // метод Лапласа (разложение по минорам)
  double det = 0.0;
  for (int j = 0; j < A->columns && !status; j++) {
    matrix_t minor;
    status = s21_create_matrix(A->rows - 1, A->columns - 1, &minor);

    if (!status) status = s21_minor(A, &minor, 0, j);
    double minor_det = 0.0;
    if (!status && !s21_determinant(&minor, &minor_det)) {
      det += pow(-1, j) * A->matrix[0][j] * minor_det;
    }
    s21_remove_matrix(&minor);
  }
  *result = det;

  return status;
}
