/*
 * 2 Dimentional Array를 Dynamic Allocate 하는 예제
 * Matrix(int N, int M); -> constructor
 * ~Matrix(); -> destructor
 * 두 개의 함수에 Dynamic Allocate 코드 작성
 */

#include <iostream>
#include <cstdlib>
#include <math.h>

class Matrix
{
private:
    int row;
    int col;
    double tolx = 1e-15;
    double **data;

public:
    Matrix(int N, int M);
    ~Matrix();
    void inputMatrix(void);
    void printMatrix(void);
    double matrixData(int i, int j);
    void interChange(int A, int B);
    void scaling(int A, double scalar);
    void replacement(int A, int B, double scalar);
    bool isPivotColumn(int prow, int pcol);
    int findPivotRow(int pcol);
    void rowReduction(void);
    void printSol(void);
};

/****************************************************************
 * 아래는 2 Dimentional Array를 Dynamic Allocate 하는 함수
 ****************************************************************/
Matrix::Matrix(int N, int M)
{
    row = N;                      // 행의 개수
    col = M;                      // 열의 개수
    data = new double *[row];     // double** data; -> 배열(포인터)를 가리키는 포인터 배열(**)
    for (int i = 0; i < row; i++) // 각 열마다 새로운 배열 주소 할당
        data[i] = new double[col];
}
/****************************************************************
 * 아래는 2 Dimentional Array를 DeAllocate 하는 함수
 ****************************************************************/
Matrix::~Matrix()
{
    for (int i = 0; i < row; i++)
        delete[] data[i]; // 각 열마다 할당된 배열 할당 해제
    delete[] data;        // 포인터 배열 할당 해제
}

void Matrix::inputMatrix(void)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            std::cin >> data[i][j];
}
void Matrix::printMatrix(void)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            std::cout << data[i][j] << " ";
        std::cout << std::endl;
    }
}
double Matrix::matrixData(int i, int j)
{
    return data[i][j];
}
void Matrix::interChange(int A, int B)
{
    double *tmp;
    tmp = data[A];
    data[A] = data[B];
    data[B] = tmp;
}
void Matrix::scaling(int A, double scalar)
{
    for (int j = 0; j < col; j++)
        data[A][j] *= scalar;
}
void Matrix::replacement(int A, int B, double scalar)
{
    for (int j = 0; j < col; j++)
        data[A][j] += data[B][j] * scalar;
}
bool Matrix::isPivotColumn(int prow, int pcol)
{
    for (int i = prow; i < row; i++)
    {
        if (fabs(data[i][pcol]) > tolx)
            return true;
    }
    return false;
}
int Matrix::findPivotRow(int pcol)
{
    double tmp = 0;
    int pp = pcol;
    for (int i = pcol; i < row; i++)
    {
        if (tmp < fabs(data[i][pcol]))
        {
            tmp = fabs(data[i][pcol]);
            pp = i;
        }
    }
    return pp;
}
void Matrix::rowReduction(void)
{
    int crow = 0;
    int *pivots = new int[row];
    for (int j = 0; j < col; j++)
    {
        if (isPivotColumn(crow, j))
        {
            int pivot = findPivotRow(j);
            if (pivot != j)
                interChange(pivot, j);
        }
        else
            continue;
        for (int i = crow + 1; i < row; i++)
        {
            double scalar = -(data[i][j] / data[crow][j]);
            replacement(i, crow, scalar);
        }
        scaling(crow, 1 / data[crow][j]);
        pivots[crow] = j;
        crow++;
    }
    crow--;
    for (int i = crow; i >= 0; i--)
    {
        int pcol = pivots[i];
        for (int j = i - 1; j >= 0; j--)
        {
            double scalar = -data[j][pcol];
            replacement(j, i, scalar);
        }
    }
    delete[] pivots;
}
void Matrix::printSol(void)
{
    rowReduction();
    for (int i = 0; i < row; i++)
    {
        std::cout << std::round(data[i][col - 1]) << " ";
    }
    std::cout << std::endl;
}
int main(void)
{
    int N, M;
    std::cin >> N >> M;
    Matrix A(N, M);
    A.inputMatrix();
    A.rowReduction();
    A.printMatrix();
    return 0;
}