#include "s21_matrix_oop.h"


double** S21Matrix::Create_Matrix(int rows, int cols){
    double** matrix = (double **)malloc(rows * sizeof(double *));
    for(int i = 0; i < rows; i++){
        matrix[i] = (double *)malloc(cols * sizeof(double));
        if(!matrix[i]) throw out_of_range("Memory isn't allocated");
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0.0;
        }
    }
    return matrix;
}


void S21Matrix::DeleteMatrix(){
    if (_matrix != nullptr) {
        for (int i = 0; i < _rows; ++i) {
            free(_matrix[i]);
        }
        free(_matrix);
        _matrix = nullptr;
    }
}

void S21Matrix::CopyMatrix(const S21Matrix& other){
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            _matrix[i][j] = other._matrix[i][j];
        }
    }
}

S21Matrix::S21Matrix(){
    _rows = _cols = 0;
    _matrix = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols){
    if(rows <= 0 || cols <=0){
        throw out_of_range("Incorrect matrix size");
    }
    else{
        _rows = rows;
        _cols = cols;
        _matrix = Create_Matrix(_rows, _cols);
    }
}
S21Matrix::S21Matrix(const S21Matrix& other) : S21Matrix::S21Matrix(other._rows, other._cols){
    CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
: _rows(exchange(other._rows, 0)),
    _cols(exchange(other._cols, 0)),
    _matrix(exchange(other._matrix, nullptr)) {}

S21Matrix::~S21Matrix(){
    DeleteMatrix();
}

int S21Matrix::GetRows() const {return _rows;}
int S21Matrix::GetCols() const {return _cols;}
void S21Matrix::SetRows(int rows){ChangeMatrixSize(rows, _cols);}
void S21Matrix::SetCols(int cols){ChangeMatrixSize(_rows, cols);}

void S21Matrix::ChangeMatrixSize(int newRows, int newCols){
    S21Matrix forChangeMatrix(newRows, newCols);
    int maxRows = newRows, maxCols = newCols;

    if (newRows > _rows) maxRows = _rows;
    if (newCols > _cols) maxCols = _cols;

    for (int i = 0; i < maxRows; ++i) {
    for (int j = 0; j < maxCols; ++j) {
        forChangeMatrix._matrix[i][j] = _matrix[i][j];
    }
    }
    DeleteMatrix();
    (*this) = forChangeMatrix;
}

bool S21Matrix::IsMatrixExist() const {
  return (_matrix != nullptr && _rows > 0 && _cols > 0);
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
    bool code = true;
    if (_matrix == nullptr && other._matrix == nullptr) code = true;
    if ((_matrix == nullptr) || (other._matrix == nullptr) || (_rows != other.GetRows()) || (_cols != other.GetCols())) {
        throw invalid_argument("The matrices have different sizes. Operation cannot be performed.");
    }

    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            if (abs(_matrix[i][j] - other._matrix[i][j]) >= 1E-11) {
                code = false;
                break;
            }
        }
    }
    return code;
}

void S21Matrix::SumMatrix(const S21Matrix& other){
    if(!IsMatrixExist() || !other.IsMatrixExist()){
        throw invalid_argument("Incorrect matrices input");
    }
    else if(_rows != other._rows || _cols != other._cols){
        throw out_of_range("The matrices have different sizes. Operation cannot be performed.");
    }
    else{
        for(int i = 0; i < _rows; i++){
            for(int j = 0; j < _cols; j++){
                _matrix[i][j] += other._matrix[i][j];
            }
        }
    }
}
void S21Matrix::SubMatrix(const S21Matrix& other){
    if(!IsMatrixExist() || !other.IsMatrixExist()){
        throw invalid_argument("Incorrect matrices input");
    }
    else if(_rows != other._rows || _cols != other._cols){
        throw out_of_range("The matrices have different sizes. Operation cannot be performed.");
    }
    else{
        for(int i = 0; i < _rows; i++){
            for(int j = 0; j < _cols; j++){
                _matrix[i][j] -= other._matrix[i][j];
            }
        }
    }
}

void S21Matrix::MulNumber(double num){
    if(IsMatrixExist()){
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                _matrix[i][j] *= num;
            }
        }
    }
}

void S21Matrix::MulMatrix(const S21Matrix& other){
    if(!IsMatrixExist() || !other.IsMatrixExist()){
        throw invalid_argument("Incorrect matrices input");
    }
    else if(_cols != other._rows){
        throw out_of_range("The number of columns of the first matrix is not equal to the number of rows of the second matrix.");
    }
    else{
        S21Matrix result(_rows, other._cols);
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < other._cols; ++j) {
            result._matrix[i][j] = 0.0;
            for (int k = 0; k < other._rows; ++k) {
                result._matrix[i][j] += _matrix[i][k] * other._matrix[k][j];
            }
            }
        }
        DeleteMatrix();
        *this = result;
    }
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}//Различная размерность матриц.

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}//Различная размерность матриц.

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}//Число столбцов первой матрицы не равно числу строк второй матрицы.

S21Matrix operator*(double num, const S21Matrix& other) noexcept {
  S21Matrix result(other);
  result.MulNumber(num);
  return result;
}

S21Matrix S21Matrix::operator*(double num) {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    DeleteMatrix();
    _rows = other._rows;
    _cols = other._cols;
    _matrix = Create_Matrix(_rows, _cols);
    CopyMatrix(other);
  }
  return *this;
} //Присвоение матрице значений другой матрицы.

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }//Проверка на равенство матриц

double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || j < 0 || i >= _rows || j >= _cols)
    throw out_of_range("Index outside the matrix.");
  return _matrix[i][j];
} //Индекс за пределами матрицы.

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return (*this);
}//Различная размерность матриц.

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return (*this);
}//Различная размерность матриц.

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return (*this);
}//Число столбцов первой матрицы не равно числу строк второй матрицы.

S21Matrix& S21Matrix::operator*=(double num) {
  MulNumber(num);
  return (*this);
} 

S21Matrix S21Matrix::Transpose() {
  if (!IsMatrixExist()) {
    throw invalid_argument("Memory isn't allocated");
  }
  S21Matrix result(_cols, _rows);
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      result._matrix[j][i] = _matrix[i][j];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (!IsMatrixExist()) {
    throw invalid_argument("Memory isn't allocated");
  }
  if (_rows != _cols) {
    throw out_of_range("Count of rows are not equal counts of cols");
  }
  S21Matrix result(_rows, _cols);
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      S21Matrix minor(_rows - 1, _cols - 1);
      Get_Minor(minor, i, j, _rows);
      double Det = minor.Determinant();
      int sign = (i + j) % 2 == 0 ? 1 : -1;
      result(i, j) = sign * Det;
      minor.DeleteMatrix();
    }
  }
  return result;
}

void S21Matrix::Get_Minor(S21Matrix& temp, int pivRow, int pivCol, int size) {
  if (!IsMatrixExist()) {
    throw invalid_argument("Memory isn't allocated");
  }
  int di = 0;
  for (int row = 0; row < size - 1; row++) {
    if (row == pivRow) di = 1;
    int dj = 0;
    for (int col = 0; col < size - 1; col++) {
      if (col == pivCol) dj = 1;
      temp(row, col) = _matrix[row + di][col + dj];
    }
  }
}

// Вычисляет определитель матрицы и возвращает его
double S21Matrix::Determinant() {
  if (!IsMatrixExist()) {
    throw invalid_argument("Memory isn't allocated");
  }
  if (_rows != _cols) {
    throw out_of_range("Size of rows and cols must be equal");
  }
  return Search_determinant(_rows);
}

double S21Matrix::Search_determinant(int size) {
  if (!IsMatrixExist()) {
    throw invalid_argument("Memory isn't allocated");
  }
  if (size == 1) return _matrix[0][0];
  if (size == 2)
    return _matrix[0][0] * _matrix[1][1] - (_matrix[1][0] * _matrix[0][1]);

  double result = 0;

  S21Matrix minor(size - 1, size - 1);
  for (int i = 0; i < size; i++) {
    Get_Minor(minor, i, 0, size);
    result += pow((-1), i) * _matrix[i][0] * minor.Search_determinant(size - 1);
  }
  minor.DeleteMatrix();
  return result;
}

// Вычисляет и возвращает обратную матрицу
S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (det == 0) {
    throw out_of_range("Determinant is equal zero, inverse matrix doesnt exist");
  }
  S21Matrix result(_rows, _cols);
  if (_rows == 1) {
    result._matrix[0][0] = 1 / _matrix[0][0];
  } else {
    S21Matrix complements = CalcComplements();
    result = complements.Transpose();
    result.MulNumber(1 / det);
  }
  return result;
}