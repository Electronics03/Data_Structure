#include <iostream>
#include <cstdlib>
#include <math.h>

class Matrix
{
public:
    int row;
    int col;
    double **data;

    Matrix(int N, int M)
    {
        row = N;
        col = M;

        data = new double *[row];
        for (int i = 0; i < row; i++)
            data[i] = new double[col];
    }
    void inputMatrix(void)
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                std::cin >> data[i][j];
    }
    void printMatrix(void)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                std::cout << data[i][j] << " ";
            std::cout << std::endl;
        }
    }
    void interChangeRow(int A, int B)
    {
        double *tmp;
        tmp = data[A];
        data[A] = data[B];
        data[B] = tmp;
    }
    void scalingRow(int A, double scalar)
    {
        for (int j = 0; j < col; j++)
            data[A][j] *= scalar;
    }
    void replacementRow(int A, int B, double scalar)
    {
        for (int j = 0; j < col; j++)
            data[A][j] += data[B][j] * scalar;
    }
    bool isPivotColumn(int A, int pivotCol)
    {
        if (data[A][pivotCol] != 0)
            return true;
        else
            return false;
    }
    int findPivotRow(int pivotCol)
    {
        double tmp = 0;
        int pivotPosition;
        for (int i = pivotCol; i < row; i++)
        {
            if (tmp < fabs(data[i][pivotCol]))
            {
                tmp = fabs(data[i][pivotCol]);
                pivotPosition = i;
            }
        }
        return pivotPosition;
    }
    ~Matrix()
    {
        for (int i = 0; i < row; i++)
            delete[] data[i];
        delete data;
    }
};

void rowReduction(Matrix *A)
{
    for (int i = 0; i < A->row; i++)
    {
        int pivot = A->findPivotRow(i);
        if (pivot != i)
            A->interChangeRow(pivot, i);
        for (int j = i + 1; j < A->row; j++)
        {
            double scalar = -(A->data[j][i] / A->data[i][i]);
            A->replacementRow(j, i, scalar);
        }
        A->scalingRow(i, 1 / A->data[i][i]);
    }
    for (int i = A->row - 2; i >= 0; i++)
    {
        ;
    }
}

int main(void)
{
    int N;
    std::cin >> N;
    Matrix A(N, N + 1);
    A.inputMatrix();
    rowReduction(&A);
    A.printMatrix();
    return 0;
}