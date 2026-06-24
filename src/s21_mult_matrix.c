#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!correct_matrix(A) || !correct_matrix(B) || result == NULL)
    return INVALID_MATRIX;

  int status = OK;
  if (A->columns != B->rows) status = CALCULATION_ERROR;

  if (!status) status = s21_create_matrix(A->rows, B->columns, result);

  for (int k = 0; k < A->columns && !status; k++) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return status;
}