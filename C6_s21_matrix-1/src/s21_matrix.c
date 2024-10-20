#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int code = 0;

  if (rows < 1 || columns < 1) {
    code = 1;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    code = 1;
    if (result->matrix != NULL) {
      for (int i = 0; i < result->rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
      }
      code = 0;
    }
  }
  return code;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i]) {
        free(A->matrix[i]);
      }
    }
    free(A->matrix);
    A->matrix = NULL;
  }
  if (A->rows) {
    A->rows = 0;
  }
  if (A->columns) {
    A->columns = 0;
  }
}

int matrix_exist(matrix_t *matrix) {
  int res;
  if (matrix != NULL && matrix->matrix != NULL && matrix->rows >= 1 &&
      matrix->columns >= 1) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int code = 0;
  if (matrix_exist(A) && matrix_exist(B)) {
    code = 0;
    if (A->rows == B->rows && A->columns == B->columns) {
      code = 1;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-6) {
            code = 0;
          }
        }
      }
    }
  }
  return code;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = 1;
  if (matrix_exist(A) && matrix_exist(B)) {
    code = 2;
    if (A->rows == B->rows && A->columns == B->columns) {
      code = s21_create_matrix(A->rows, A->columns, result);
      if (code == 0) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          }
        }
      }
    }
  }
  return code;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = 1;
  if (matrix_exist(A) && matrix_exist(B)) {
    code = 2;
    if (A->rows == B->rows && A->columns == B->columns) {
      code = s21_create_matrix(A->rows, A->columns, result);
      if (code == 0) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      }
    }
  }
  return code;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int code = 1;
  if (matrix_exist(A)) {
    code = s21_create_matrix(A->rows, A->columns, result);
    if (code == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return code;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = 1;
  if (matrix_exist(A) && matrix_exist(B)) {
    if (A->columns == B->rows) {
      code = s21_create_matrix(A->rows, B->columns, result);
      if (code == 0) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            for (int k = 0; k < B->rows; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      }
    } else {
      code = 2;
    }
  }
  return code;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int code = 1;
  if (matrix_exist(A)) {
    code = s21_create_matrix(A->rows, A->columns, result);
    if (code == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    }
  }
  return code;
}

int get_minor(int row, int column, matrix_t *A, matrix_t *result) {
  int code = 1;
  if (A->matrix != NULL) {
    code = s21_create_matrix(A->rows - 1, A->columns - 1, result);
    if (code == 0) {
      int m, n;
      for (int i = 0; i < A->rows; i++) {
        m = i;
        if (i > row - 1) {
          m--;
        }
        for (int j = 0; j < A->columns; j++) {
          n = j;
          if (j > column - 1) {
            n--;
          }
          if (i != row - 1 && j != column - 1) {
            result->matrix[m][n] = A->matrix[i][j];
          }
        }
      }
    }
  }
  return code;
}

double search_determinant(matrix_t *A) {
  double result = 0;
  if (A->rows == 2) {
    result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    for (int i = 0; i < A->rows; i++) {
      matrix_t minor;
      get_minor(1, i + 1, A, &minor);
      result += pow((-1), i) * A->matrix[0][i] * search_determinant(&minor);
      s21_remove_matrix(&minor);
    }
  }
  return result;
}

int s21_determinant(matrix_t *A, double *result) {
  int code = 1;
  if (matrix_exist(A)) {
    code = 2;
    if (A->rows == A->columns) {
      code = 0;
      *result = A->matrix[0][0];
      if (A->rows != 1) {
        *result = search_determinant(A);
      }
    }
  }
  return code;
}

int calc(matrix_t *A, matrix_t *result) {
  int code = 0;
  result->matrix[0][0] = 1;
  if (A->rows != 1) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double determinant;
        matrix_t minor;
        code = get_minor(i + 1, j + 1, A, &minor);
        if (code == 0) {
          code = s21_determinant(&minor, &determinant);
          if (code == 0) {
            result->matrix[i][j] = pow((-1), i + j) * determinant;
          }
        }
        s21_remove_matrix(&minor);
      }
    }
  }
  return code;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = 1;
  if (matrix_exist(A)) {
    code = 2;
    if (A->rows == A->columns) {
      code = s21_create_matrix(A->rows, A->columns, result);
      if (code == 0) {
        code = calc(A, result);
      }
    }
  }
  return code;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code = 1;
  if (matrix_exist(A)) {
    code = 2;
    double det;
    s21_determinant(A, &det);
    if (fabs(det - 0) > 1e-6) {
      matrix_t calc;
      code = s21_calc_complements(A, &calc);
      if (code == 0) {
        matrix_t trans;
        code = s21_transpose(&calc, &trans);
        if (code == 0) {
          s21_mult_number(&trans, 1 / det, result);
        }
        s21_remove_matrix(&trans);
      }
      s21_remove_matrix(&calc);
    }
  }
  return code;
}