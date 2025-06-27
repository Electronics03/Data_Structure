#include "hashMap.h"
#include <iostream>

int main(void)
{
    HashMap<std::string, int, stringHash> map;
    // key : std::string
    // value : int
    // Create a HashMap with string keys and int values
    typedef HashMap<std::string, int, stringHash>::Iterator hashIter;

    // Insert three key-value pairs into the map
    map.put("apple", 100);
    map.put("banana", 150);
    map.put("cherry", 200);

    // Print all entries in the map
    hashIter iter = map.begin();
    while (1)
    {
        if (iter == map.end())
            break;
        std::cout << (*iter).key() << ": " << (*iter).value() << ", ";
        ++iter;
    }
    std::cout << std::endl;

    // Erase the entry with key "apple"
    map.erase("apple");

    // Print all entries in the map
    iter = map.begin();
    while (1)
    {
        if (iter == map.end())
            break;
        std::cout << (*iter).key() << ": " << (*iter).value() << ", ";
        ++iter;
    }
    std::cout << std::endl;

    // Update the value for key "cherry" to 300
    map.put("cherry", 300);

    // Print all entries in the map
    iter = map.begin();
    while (1)
    {
        if (iter == map.end())
            break;
        std::cout << (*iter).key() << ": " << (*iter).value() << ", ";
        ++iter;
    }
    std::cout << std::endl;

    // Find the iterator for "cherry" and erase it
    iter = map.find("cherry");
    map.erase(iter);
    iter = map.begin();

    // Print all entries in the map
    while (1)
    {
        if (iter == map.end())
            break;
        std::cout << (*iter).key() << ": " << (*iter).value() << ", ";
        ++iter;
    }
    std::cout << std::endl;

    // Erase the remaining entry "banana"
    map.erase("banana");
    if (map.empty())
        std::cout << "map is empty" << std::endl;

    getchar();

    return 0;
}
/*
 * g++                                     -> 컴파일러
 * -o HW3/main.exe   -> exe 파일 이름, 위치
 * HW3/main.cpp      -> 함께 하는 파일 이름, 위치
 * HW3/hashMap.cpp
 *
 * g++ -o HW3/main.exe HW3/main.cpp HW3/hashMap.cpp
 */