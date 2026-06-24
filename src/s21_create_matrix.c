#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows < 1 || columns < 1 || result == NULL) {
    return INVALID_MATRIX;
  }

  result->rows = rows;
  result->columns = columns;

  result->matrix = calloc(rows, sizeof(double));
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = calloc(columns, sizeof(double));
  }
  return OK;
}
