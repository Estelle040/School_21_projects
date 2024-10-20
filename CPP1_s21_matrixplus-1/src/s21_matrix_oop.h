#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H
#include <math.h>
#include <cstring>
#include <stdexcept>
#include <utility>
using namespace std;
class S21Matrix {
 private:
  int _rows, _cols;
  double** _matrix;

 public:
    //Конструкторы
    S21Matrix(); //+
    S21Matrix(int rows, int cols); //+
    S21Matrix(const S21Matrix& other); //+
    S21Matrix(S21Matrix&& other) noexcept; //+
    ~S21Matrix(); //Деструктор +

    //Гетеры и сетеры
    int GetRows() const;//+
    int GetCols() const;//+
    void SetRows(int rows);//+
    void SetCols(int cols);//+
    
    //Методы
    bool EqMatrix(const S21Matrix& other);//+
    void SumMatrix(const S21Matrix& other);//+
    void SubMatrix(const S21Matrix& other);//+
    void MulNumber(double num);//+
    void MulMatrix(const S21Matrix& other);//+
    S21Matrix Transpose();
    S21Matrix CalcComplements();
    double Determinant();
    S21Matrix InverseMatrix();
    
    //Перегрузка операторов
    S21Matrix operator+(const S21Matrix& other); //Различная размерность матриц.+
    S21Matrix operator-(const S21Matrix& other); //Различная размерность матриц.+
    S21Matrix operator*(double n);//+
    friend S21Matrix operator*(double num, const S21Matrix& other) noexcept;//+
    S21Matrix operator*(const S21Matrix& other); //Число столбцов первой матрицы не равно числу строк второй матрицы.+
    bool operator==(const S21Matrix& other); //Проверка на равенство матриц +
    S21Matrix& operator=(const S21Matrix& other); //Присвоение матрице значений другой матрицы.+
    S21Matrix& operator+=(const S21Matrix& other); //Различная размерность матриц.+
    S21Matrix& operator-=(const S21Matrix& other); //Различная размерность матриц.+
    S21Matrix& operator*=(double n);//+
    S21Matrix& operator*=(const S21Matrix& other); //Число столбцов первой матрицы не равно числу строк второй матрицы.+
    double& operator()(int row, int col); //Индекс за пределами матрицы.+

    //Вспомогательные функции
    bool IsMatrixExist() const; //+
    void ChangeMatrixSize(int newRows, int newCols); //+
    void CopyMatrix(const S21Matrix& other); //+
    double** Create_Matrix(int rows, int cols);//+
    void DeleteMatrix();//+
    void Get_Minor(S21Matrix& temp, int pivRow, int pivCol, int size);
    double Search_determinant(int size);
};

#endif