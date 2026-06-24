#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!correct_matrix(A) || result == NULL) return INVALID_MATRIX;

  int status = OK;
  status = s21_create_matrix(A->rows, A->columns, result);

  int rows = A->rows;
  int columns = A->columns;

  for (int i = 0; i < rows && !status; i++) {
    for (int j = 0; j < columns && !status; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return status;
}