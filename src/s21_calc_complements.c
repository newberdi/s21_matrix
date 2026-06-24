#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!correct_matrix(A) || result == NULL) return INVALID_MATRIX;

  int status = OK;
  if (!is_square(A)) status = CALCULATION_ERROR;
  if (!status) status = s21_create_matrix(A->rows, A->columns, result);

  if (A->rows == 1) {
    result->matrix[0][0] = A->matrix[0][0];
    return status;
  }

  for (int j = 0; j < A->rows && !status; j++) {
    for (int i = 0; i < A->columns && !status; i++) {
      matrix_t tmp;
      status = s21_create_matrix(A->columns - 1, A->rows - 1, &tmp);

      if (!status) status = s21_minor(A, &tmp, j, i);
      double minor_det = 0;
      if (!status && !s21_determinant(&tmp, &minor_det)) {
        result->matrix[j][i] = ((j + i) % 2 == 0) ? minor_det : -minor_det;
      }
      s21_remove_matrix(&tmp);
    }
  }

  return status;
}