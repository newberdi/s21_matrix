#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!correct_matrix(A)) return INVALID_MATRIX;

  int status = OK;
  if (!is_square(A) || result == NULL) status = CALCULATION_ERROR;

  if (!status && A->rows == 1) {
    if (A->matrix[0][0] != 0 && fabs(A->matrix[0][0]) > 1e-6) {
      status = s21_create_matrix(A->rows, A->rows, result);
      result->matrix[0][0] = 1.0 / A->matrix[0][0];
    }
  } else {
    double det = 0;
    status = s21_determinant(A, &det);
    if (!det && fabs(det) < 1e-7) status = CALCULATION_ERROR;

    matrix_t tmp_calc = {0};
    if (!status) status = s21_calc_complements(A, &tmp_calc);

    matrix_t tmp_tranpose = {0};

    if (!status) status = s21_transpose(&tmp_calc, &tmp_tranpose);
    s21_remove_matrix(&tmp_calc);

    if (!status) status = s21_mult_number(&tmp_tranpose, 1.0 / det, result);
    s21_remove_matrix(&tmp_tranpose);
  }
  return status;
}