#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!correct_matrix(A) || !correct_matrix(B) || result == NULL)
    return INVALID_MATRIX;

  int status = OK;
  if (!same_size(A, B)) status = CALCULATION_ERROR;
  if (!status) status = s21_create_matrix(B->rows, B->columns, result);

  for (int i = 0; i < A->rows && !status; i++) {
    for (int j = 0; j < A->columns && !status; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }

  return status;
}