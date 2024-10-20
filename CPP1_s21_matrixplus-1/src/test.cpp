#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

static double summandFirst[2][3][3] = {{{1, 2, 3}, {0, 4, 5}, {0, 0, 6}},
                                       {{1, 0, 0}, {2, 0, 0}, {3, 4, 1}}};

static double summandSecond[2][3][3] = {{{1, 0, 0}, {2, 0, 0}, {3, 4, 1}},
                                        {{1, 2, 3}, {0, 4, 5}, {0, 0, 6}}};
static bool compareSumResult[2] = {true, false};
static double sumResult[2][3][3] = {{{2, 2, 3}, {2, 4, 5}, {3, 4, 7}},
                                    {{2, 5, 3}, {2, 4, 5}, {3, 4, 7}}};

static double minuend[2][3][3] = {{{2, 2, 3}, {2, 4, 5}, {3, 4, 7}},
                                  {{2, 5, 3}, {2, 4, 5}, {3, 4, 7}}};

static double subtrahend[2][3][3] = {{{1, 2, 3}, {0, 4, 5}, {0, 0, 6}},
                                     {{1, 0, 0}, {2, 0, 0}, {3, 4, 1}}};
static bool compareSubResult[2] = {true, false};
static double subResult[2][3][3] = {{{1, 0, 0}, {2, 0, 0}, {3, 4, 1}},
                                    {{1, 2, 3}, {0, 4, 5}, {0, 0, 6}}};
static double mulMatrixFirstValue[3][3] = {{3, 4, 55}, {6, 7, 8}, {9, 3, 4}};
static double mulMatrixSecondValue[3][4] = {
    {1, 2, 3, 4}, {4, 5, 6, 5}, {6, 7, 8, 9}};
static double mulMatrixResult[3][4] = {
    {349, 411, 473, 527}, {82, 103, 124, 131}, {45, 61, 77, 87}};
static double transposeResult[3][3] = {{1, 0, 0}, {2, 4, 0}, {3, 5, 6}};
static double determinantResult[] = {24, 0, -6, -40, -1};
static double val1[5][3][3] = {{{1, 2, 3}, {0, 4, 5}, {0, 0, 6}},
                               {{1, 0, 0}, {2, 0, 0}, {3, 4, 1}},
                               {{1, 2, 3}, {0, 4, 2}, {2, 3, 4}},
                               {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}},
                               {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}}};

static double valDeterminant[10][10] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 20},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 20},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 20},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 20},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}};
static double calcComplementsResults[5][3][3] = {
    {{24, -0, 0}, {-12, 6, -0}, {-2, -5, 4}},
    {{0, -2, 8}, {-0, 1, -4}, {0, -0, 0}},
    {{10, 4, -8}, {1, -2, 1}, {-8, -2, 4}},
    {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}},
    {{-1, 38, -27}, {1, -41, 29}, {-1, 34, -24}}};

static double inverseResults[5][3][3] = {
    {{1, -0.5, -0.0833333}, {-0, 0.25, -0.208333}, {0, -0, 0.166667}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{-1.66667, -0.166667, 1.33333},
     {-0.666667, 0.333333, 0.333333},
     {1.33333, -0.166667, -0.666667}},
    {{-0, -0.1, 0.2}, {-0.25, 0.35, 0.05}, {0.5, -0.2, -0.1}},
    {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}}};

void SetMatrix3x3(S21Matrix &matrix, double expected[3][3]) {
  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      matrix(i, j) = expected[i][j];
    }
  }
}

void SetMatrix3x4(S21Matrix &matrix, double expected[3][4]) {
  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      matrix(i, j) = expected[i][j];
    }
  }
}

void SetMatrix10x10(S21Matrix &matrix, double expected[10][10]) {
  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      matrix(i, j) = expected[i][j];
    }
  }
}

void CompareForInverse(S21Matrix matrix, double result[3][3]) {
  for (int i{0}; i < matrix.GetRows(); ++i) {
    for (int j{0}; j < matrix.GetCols(); ++j) {
      EXPECT_NEAR(matrix(i, j), result[i][j], 1E-5);
    }
  }
}

TEST(CreateTest, DefaultConstructor) {
  S21Matrix example;
  EXPECT_EQ(example.GetRows(), 0);
  EXPECT_EQ(example.GetCols(), 0);
}

TEST(CreateTest, ParametrizedConstructorSuccess) {
  S21Matrix example(2, 5);
  EXPECT_EQ(example.GetRows(), 2);
  EXPECT_EQ(example.GetCols(), 5);
}

TEST(CreateTest, CopyConstructor) {
  S21Matrix example(3, 5);
  S21Matrix res(example);
  EXPECT_EQ(res.GetRows(), example.GetRows());
  EXPECT_EQ(res.GetCols(), example.GetCols());
}

TEST(CreateTest, MovedConstructor) {
  S21Matrix example(3, 3);
  S21Matrix res = move(example);
  EXPECT_EQ(res.GetCols(), 3);
  EXPECT_EQ(example.GetCols(), 0);
}

TEST(CreateTest, ParametrizedConstructorFailure) {
  EXPECT_THROW(S21Matrix example(-1, 1), out_of_range);
}

TEST(OverrideOperators, Brackets) {
  S21Matrix example(1, 1);
  EXPECT_EQ(example(0, 0), 0);
}

TEST(OverrideOperators, BracketsOverride) {
  S21Matrix example(1, 1);
  example(0, 0) = 5;
  EXPECT_EQ(example(0, 0), 5);
}

TEST(OverrideOperators, BracketsOutOfRange) {
  S21Matrix example(1, 1);
  EXPECT_THROW(example(-5, 4), out_of_range);
}

TEST(OverrideOperators, BracketsOverrideOutOfRange) {
  S21Matrix example(1, 1);
  EXPECT_THROW(example(5, 0) = 4, out_of_range);
}

TEST(TestPrivateAccess, Accessors) {
  S21Matrix example(1, 2);
  EXPECT_EQ(example.GetRows(), 1);
  EXPECT_EQ(example.GetCols(), 2);
}

TEST(TestPrivateAccess, Mutators) {
  int rows = 3, cols = 3;
  S21Matrix matrix(rows, cols);
  SetMatrix3x3(matrix, val1[0]);
  matrix.SetRows(10);
  matrix.SetCols(2);
  EXPECT_NE(matrix.GetRows(), rows);
  EXPECT_NE(matrix.GetCols(), cols);
  EXPECT_EQ(matrix(1, 1), 4);
  EXPECT_EQ(matrix(5, 1), 0);
}

TEST(TestPrivateAccess, MutatorsInvailid) {
  int rows = 3, cols = 3;
  S21Matrix matrix(rows, cols);
  EXPECT_THROW(matrix.SetCols(-4), out_of_range);
  EXPECT_THROW(matrix.SetRows(-4), out_of_range);
}

TEST(BaseFunctions, EqualOutOfRange) {
  S21Matrix example(3, 3);
  S21Matrix out_of_range_example(3, 4);
  EXPECT_THROW(example.EqMatrix(out_of_range_example), invalid_argument);
}

TEST(BaseFunctions, EqualTrue) {
  S21Matrix example(3, 3);
  S21Matrix equal_example(3, 3);
  EXPECT_TRUE(example.EqMatrix(equal_example));
}

TEST(BaseFunctions, EqualFalse) {
  S21Matrix example(3, 3);
  S21Matrix non_equal_example(3, 3);
  non_equal_example(1, 1) = 3;
  EXPECT_EQ(example.EqMatrix(non_equal_example), 0);
}

TEST(BaseFunctions, SumOutOfRange) {
  S21Matrix example(3, 3);
  S21Matrix non_equal_example(3, 4);
  EXPECT_THROW(example.SumMatrix(non_equal_example), out_of_range);
}

TEST(BaseFunctions, SumDefaultTest) {
  for (int i = 0; i < 5; ++i) {
    S21Matrix example(3, 3);
    S21Matrix summand(3, 3);
    S21Matrix result(3, 3);
    SetMatrix3x3(example, summandFirst[i]);
    SetMatrix3x3(summand, summandSecond[i]);
    SetMatrix3x3(result, sumResult[i]);
    example.SumMatrix(summand);
    EXPECT_EQ(result.EqMatrix(example), compareSumResult[i]);
  }
}

TEST(BaseFunctions, SubOutOfRange) {
  S21Matrix example(3, 3);
  S21Matrix non_equal_example(3, 4);
  EXPECT_THROW(example.SubMatrix(non_equal_example), out_of_range);
}

TEST(BaseFunctions, SubDefaultTest) {
  for (int i = 0; i < 2; ++i) {
    S21Matrix example(3, 3);
    S21Matrix term(3, 3);
    S21Matrix result(3, 3);
    SetMatrix3x3(example, minuend[i]);
    SetMatrix3x3(term, subtrahend[i]);
    SetMatrix3x3(result, subResult[i]);
    example.SubMatrix(term);
    EXPECT_EQ(result.EqMatrix(example), compareSubResult[i]);
  }
}

TEST(BaseFunctions, MulNumberTest) {
  S21Matrix example(1, 1);
  example(0, 0) = 5;
  example.MulNumber(4);
  EXPECT_EQ(example(0, 0), 20);
}

TEST(BaseFunctions, MulMatrixTest) {
  S21Matrix example(3, 3);
  S21Matrix term(3, 4);
  S21Matrix result(3, 4);
  SetMatrix3x3(example, mulMatrixFirstValue);
  SetMatrix3x4(term, mulMatrixSecondValue);
  SetMatrix3x4(result, mulMatrixResult);
  example.MulMatrix(term);
  EXPECT_EQ(result.EqMatrix(example), true);
}

TEST(BaseFunctions, TransposeTest) {
  S21Matrix example(3, 3);
  S21Matrix result(3, 3);
  S21Matrix current;
  SetMatrix3x3(example, summandFirst[0]);
  SetMatrix3x3(result, transposeResult);
  current = example.Transpose();
  EXPECT_EQ(result.EqMatrix(current), true);
}

TEST(BaseFunctions, MulMatrixOutOfRangeTest) {
  S21Matrix example(3, 3);
  S21Matrix term(5, 4);
  EXPECT_THROW(example.MulMatrix(term), out_of_range);
}

TEST(BaseFunctions, Determinant) {
  for (int i = 0; i < 5; i++) {
    S21Matrix matrix(3, 3);
    SetMatrix3x3(matrix, val1[i]);
    EXPECT_NEAR(matrix.Determinant(), determinantResult[i], 1E-11);
  }
}

TEST(BaseFunctions, Determinant_10x10) {
  S21Matrix matrix(10, 10);
  SetMatrix10x10(matrix, valDeterminant);
  EXPECT_NEAR(matrix.Determinant(), 0, 1E-5);
}

TEST(BaseFunctions, DeterminantOutOfRange) {
  S21Matrix matrix(3, 4);
  EXPECT_THROW(matrix.Determinant(), out_of_range);
}

TEST(BaseFunctions, CalcCompl) {
  for (int i = 0; i < 5; ++i) {
    S21Matrix matrix(3, 3), result(3, 3), checkResult(3, 3);
    SetMatrix3x3(matrix, val1[i]);
    SetMatrix3x3(checkResult, calcComplementsResults[i]);
    result = matrix.CalcComplements();
    EXPECT_EQ(checkResult.EqMatrix(result), 1);
  }
}

TEST(BaseFunctions, CalcComplOutOfRange) {
  S21Matrix matrix(3, 4);
  EXPECT_THROW(matrix.CalcComplements(), out_of_range);
}

TEST(BaseFunctions, Inverse) {
  for (int i = 0; i < 5; ++i) {
    S21Matrix matrix(3, 3);
    SetMatrix3x3(matrix, val1[i]);
    if (i == 1) {
      EXPECT_THROW(matrix.InverseMatrix(), out_of_range);
    } else {
      matrix = matrix.InverseMatrix();
      CompareForInverse(matrix, inverseResults[i]);
    }
  }
}

TEST(BaseFunctions, InverseOutOfRange) {
  S21Matrix matrix(3, 4);
  EXPECT_THROW(matrix.InverseMatrix(), out_of_range);
}

TEST(OverrideMethods, PlusUno) {
  S21Matrix example(3, 3);
  S21Matrix summand(3, 3);
  S21Matrix result(3, 3);
  SetMatrix3x3(example, summandFirst[0]);
  SetMatrix3x3(summand, summandSecond[0]);
  SetMatrix3x3(result, sumResult[0]);
  example += summand;
  EXPECT_EQ(example.EqMatrix(result), compareSumResult[0]);
}

TEST(OverrideMethods, MinusUno) {
  S21Matrix example(3, 3);
  S21Matrix summand(3, 3);
  S21Matrix result(3, 3);
  SetMatrix3x3(example, minuend[0]);
  SetMatrix3x3(summand, subtrahend[0]);
  SetMatrix3x3(result, subResult[0]);
  example -= summand;
  EXPECT_EQ(example.EqMatrix(result), compareSubResult[0]);
}

TEST(OverrideMethods, EqualUnoTrue) {
  S21Matrix example(3, 3);
  S21Matrix equal_example(3, 3);
  EXPECT_EQ(example == equal_example, 1);
}

TEST(OverrideMethods, EqualUnoFalse) {
  S21Matrix example(3, 3);
  S21Matrix non_equal_example(3, 3);
  non_equal_example(1, 1) = 3;
  EXPECT_EQ(example == non_equal_example, 0);
}

TEST(OverrideMethods, PlusBiAndEqualToMovedConstructor) {
  S21Matrix example(3, 3);
  S21Matrix summand(3, 3);
  S21Matrix result(3, 3);
  S21Matrix res;
  SetMatrix3x3(example, summandFirst[0]);
  SetMatrix3x3(summand, summandSecond[0]);
  SetMatrix3x3(result, sumResult[0]);
  res = summand + example;
  EXPECT_EQ(res == result, compareSumResult[0]);
}

TEST(OverrideMethods, MinusBiAndEqualToMovedConstructor) {
  S21Matrix example(3, 3);
  S21Matrix summand(3, 3);
  S21Matrix result(3, 3);
  S21Matrix res;
  SetMatrix3x3(example, minuend[0]);
  SetMatrix3x3(summand, subtrahend[0]);
  SetMatrix3x3(result, subResult[0]);
  res = example - summand;
  EXPECT_EQ(res == result, compareSubResult[0]);
}

TEST(OverrideMethods, EqualToCopyConstructor) {
  S21Matrix example(3, 3);
  S21Matrix res;
  SetMatrix3x3(example, minuend[0]);
  res = example;
  EXPECT_EQ(res == example, 1);
}

TEST(OverrideMethods, MulMatrixUno) {
  S21Matrix example(3, 3);
  S21Matrix term(3, 4);
  S21Matrix result(3, 4);
  S21Matrix answer;
  SetMatrix3x3(example, mulMatrixFirstValue);
  SetMatrix3x4(term, mulMatrixSecondValue);
  SetMatrix3x4(result, mulMatrixResult);
  answer = example * term;
  EXPECT_EQ(answer.EqMatrix(result), true);
}

TEST(OverrideMethods, MulMatrixMono) {
  S21Matrix example(3, 3);
  S21Matrix term(3, 4);
  S21Matrix result(3, 4);
  SetMatrix3x3(example, mulMatrixFirstValue);
  SetMatrix3x4(term, mulMatrixSecondValue);
  SetMatrix3x4(result, mulMatrixResult);
  example *= term;
  EXPECT_EQ(example.EqMatrix(result), true);
}

TEST(OverrideMethods, MulNumberUnoLeft) {
  S21Matrix example(1, 1);
  example(0, 0) = 4;
  example = example * 5;
  EXPECT_EQ(example(0, 0), 20);
}

TEST(OverrideMethods, MulNumberUnoRight) {
  S21Matrix example(1, 1);
  example(0, 0) = 4;
  example = 5 * example;
  EXPECT_EQ(example(0, 0), 20);
}

TEST(OverrideMethods, MulNumberMono) {
  S21Matrix example(1, 1);
  example(0, 0) = 4;
  example *= 5;
  EXPECT_EQ(example(0, 0), 20);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}