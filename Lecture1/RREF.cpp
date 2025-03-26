#include <iostream>
#include <cstdlib>
#include <math.h>

class Matrix
{
private:
    int row;             // row 개수
    int col;             // column 개수
    double tolx = 1e-15; // double 연산 정밀도
    double **data;

public:
    Matrix(int N, int M) // Matrix 생성자
    {
        row = N; // N -> Row 개수
        col = M; // M -> Column 개수
        data = new double *[row];
        for (int i = 0; i < row; i++)
            data[i] = new double[col];
        // 2차원 Data 메모리를 동적 할당
    }
    ~Matrix() // Matrix 소멸자
    {
        for (int i = 0; i < row; i++)
            delete[] data[i];
        delete[] data;
    } // Data 할당 해제

    void inputMatrix(void);
    void printMatrix(void);
    // 콘솔 창 Matrix 입출력

    double matrixData(int i, int j);
    // 인덱스 값에 해당하는 Matrix Data 반환

    void interChange(int A, int B);
    void scaling(int A, double scalar);
    void replacement(int A, int B, double scalar);
    // 세 기본 행 연산 함수

    bool isPivotColumn(int prow, int pcol);
    int findPivotRow(int pcol);
    // pivot 검사 함수

    void rowReduction(void)
    {
        int crow = 0;
        int *pivots = new int[row];
        // pivot의 위치를 기억
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
    void printSol(void)
    {
        rowReduction();
        for (int i = 0; i < row; i++)
        {
            std::cout << std::round(data[i][col - 1]) << " ";
        }
        std::cout << std::endl;
    }
};
void Matrix::inputMatrix(void)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            std::cin >> data[i][j];
    // 콘솔 창으로 Data 입력
}
void Matrix::printMatrix(void)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            std::cout << data[i][j] << " ";
        std::cout << std::endl;
    }
    // 콘솔 창으로 Data 출력
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
    // A <=> B
    // Data 위치는 바뀌지 않지만 인덱싱이 바뀌어서 열을 서로 교환한 것과 같음
}
void Matrix::scaling(int A, double scalar)
{
    for (int j = 0; j < col; j++)
        data[A][j] *= scalar;
    // A <- A * scalar
}
void Matrix::replacement(int A, int B, double scalar)
{
    for (int j = 0; j < col; j++)
        data[A][j] += data[B][j] * scalar;
    // A <- A + (B * scalar)
}
bool Matrix::isPivotColumn(int prow, int pcol)
{
    for (int i = prow; i < row; i++)
    {
        if (fabs(data[i][pcol]) > tolx)
            return true;
        // 검사하는 부분의 값이 모두 0이 아니면 pivot col
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
    // 오차를 줄이기 위해 가장 절대값이 큰 열을 사용한다
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