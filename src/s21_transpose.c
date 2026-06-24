#include "s21_matrix.h"

// Транспонирование матрицы А заключается в замене строк этой матрицы
// ее столбцами с сохранением их номеров.

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!correct_matrix(A) || result == NULL) return INVALID_MATRIX;

  int status = OK;
  status = s21_create_matrix(A->columns, A->rows, result);

  int rows = A->rows;
  int columns = A->columns;
  for (int i = 0; i < rows && !status; i++) {
    for (int j = 0; j < columns && !status; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }

  return status;
}