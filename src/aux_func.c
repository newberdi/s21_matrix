#include "s21_matrix.h"

int correct_matrix(matrix_t *A) {
  if (A == NULL || A->rows <= 0 || A->columns <= 0) return FAILURE;
  return SUCCESS;
}
int same_size(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns) ? SUCCESS : FAILURE;
}

int is_square(matrix_t *A) {
  if (A->rows != A->columns) return FAILURE;
  return SUCCESS;
}

// минор квадратной матрицы — определитель матрицы, полученной из исходной
// вычеркиванием i-ой строки и j-ого столбца
int s21_minor(matrix_t *A, matrix_t *minor, int rows, int columns) {
  int status = OK;
  if (A->columns != A->rows) status = CALCULATION_ERROR;

  int new_row = 0;
  for (int i = 0; i < A->rows && !status; i++) {
    if (i == rows) continue;
    int new_column = 0;
    for (int j = 0; j < A->columns && !status; j++) {
      if (j == columns) continue;
      minor->matrix[new_row][new_column] = A->matrix[i][j];
      new_column++;
    }
    new_row++;
  }
  return status;
}