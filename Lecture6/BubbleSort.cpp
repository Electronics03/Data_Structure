#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stddef.h>

void swap(int v[], int k)
{
    int tmp = v[k];
    v[k] = v[k + 1];
    v[k + 1] = tmp;
    return;
}
void sort(int v[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1])
                swap(v, j);
    return;
}
int main(void)
{
    int A[10] = {9, 3, 5, 6, 8, 2, 1, 0, 4, 7};
    sort(A, 10);
    for (int i = 0; i < 10; i++)
        std::cout << A[i] << std::endl;
    return 0;
}