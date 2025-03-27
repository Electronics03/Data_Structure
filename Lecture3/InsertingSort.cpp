#include <iostream>
#include <cstdlib>

template <typename T>
bool comp(T A, T B)
{
    return (A > B) ? true : false;
}

template <typename T>
void swap(T *A, T *B)
{
    T tmp = *A;
    *A = *B;
    *B = tmp;
    return;
}
template <typename T>
void printArr(T *nums, int N)
{
    for (int i = 0; i < N; i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void insertingSort(T *nums, int N)
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (comp(nums[j], nums[i]) && (j != 0))
                continue;
            else
            {
                if (!comp(nums[j], nums[i]))
                    j++;
                for (int l = i; l > j; l--)
                    swap(&nums[l - 1], &nums[l]);
                break;
            }
        }
    }
    return;
}

int main(void)
{
    double nums[10] = {8.1, 3.3, 5.4, 1.0, 6.2, 2.8, 4.7, 9.1, 0.2, 7.8};
    insertingSort(nums, 10);
    printArr(nums, 10);
}