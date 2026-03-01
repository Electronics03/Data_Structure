/*
 * File: main.cpp
 * Description: Main function to test the implemented priority queue
 * Author: Electronics03
 */

#include <iostream>
#include <vector>
#include "heap.h"

int main()
{
    HeapPriorityQueue<int, Comparator<int>> heapInt;
    std::vector<int> intVal = {10, 9, 7, 5, 3, 6, 8, 10, 12, 4};
    // Created test data to insert into the heap using a vector
    // Integer-type data
    for (int val : intVal)
    {
        std::cout << val << " ";
        // Display what data is inserted into the heap
        heapInt.insert(val);
        // Insert data into the heap
    }
    std::cout << std::endl;

    while (!heapInt.empty())
    {
        std::cout << heapInt.min() << " ";
        // Print the minimum value at the root of the heap
        heapInt.removeMin();
        // Remove the minimum value
    }
    std::cout << std::endl
              << std::endl;

    HeapPriorityQueue<char, Comparator<char>> heapChar;
    std::vector<char> charVal = {'Z', 'H', 'D', 'a', 'b', 'c', 'A', 'Q', 'd', 'f'};
    // Created test data to insert into the heap using a vector
    // Character-type data
    for (char val : charVal)
    {
        std::cout << val << " ";
        // Display what data is inserted into the heap
        heapChar.insert(val);
        // Insert data into the heap
    }
    std::cout << std::endl;

    while (!heapChar.empty())
    {
        std::cout << heapChar.min() << " ";
        // Print the minimum value at the root of the heap
        heapChar.removeMin();
        // Remove the minimum value
    }
    std::cout << std::endl;

    getchar();

    return EXIT_SUCCESS;
}