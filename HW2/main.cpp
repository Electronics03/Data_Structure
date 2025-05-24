#include <iostream>
#include <vector>
#include "heap.h"

int main()
{
    HeapPriorityQueue<int, Comparator<int>> heapInt;
    std::vector<int> intVal = {10, 9, 7, 5, 3, 6, 8, 10, 12, 4};

    for (int val : intVal)
    {
        std::cout << val << " ";
        heapInt.insert(val);
    }
    std::cout << std::endl;

    while (!heapInt.empty())
    {
        std::cout << heapInt.min() << " ";
        heapInt.removeMin();
    }
    std::cout << std::endl
              << std::endl;

    HeapPriorityQueue<char, Comparator<char>> heapChar;
    std::vector<char> charVal = {'Z', 'H', 'D', 'a', 'b', 'c', 'A', 'Q', 'd', 'f'};

    for (char val : charVal)
    {
        std::cout << val << " ";
        heapChar.insert(val);
    }
    std::cout << std::endl;

    while (!heapChar.empty())
    {
        std::cout << heapChar.min() << " ";
        heapChar.removeMin();
    }
    std::cout << std::endl;

    getchar();

    return EXIT_SUCCESS;
}
