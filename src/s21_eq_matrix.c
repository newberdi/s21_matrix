#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!correct_matrix(A) || !correct_matrix(B)) return FAILURE;

  int status = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns) status = FAILURE;

  for (int i = 0; i < A->rows && status; i++) {
    for (int j = 0; j < A->columns && status; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) status = FAILURE;
    }
  }

  return status;
}