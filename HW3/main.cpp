#include "hashMap.h"
#include <iostream>

int main(void)
{
    HashMap<std::string, int, stringHash> map;

    typedef HashMap<std::string, int, stringHash>::Iterator hashIter;

    map.put("apple", 100);
    map.put("banana", 150);
    map.put("cherry", 200);

    hashIter iter = map.begin();
    while (1)
    {
        if (iter == map.end())
            break;
        std::cout << (*iter).key() << ": " << (*iter).value() << ", ";
        ++iter;
    }
    std::cout << std::endl;

    map.erase("apple");

    iter = map.begin();
    while (1)
    {
        if (iter == map.end())
            break;
        std::cout << (*iter).key() << ": " << (*iter).value() << ", ";
        ++iter;
    }
    std::cout << std::endl;

    map.put("cherry", 300);

    iter = map.begin();
    while (1)
    {
        if (iter == map.end())
            break;
        std::cout << (*iter).key() << ": " << (*iter).value() << ", ";
        ++iter;
    }
    std::cout << std::endl;

    iter = map.find("cherry");
    map.erase(iter);
    iter = map.begin();
    while (1)
    {
        if (iter == map.end())
            break;
        std::cout << (*iter).key() << ": " << (*iter).value() << ", ";
        ++iter;
    }
    std::cout << std::endl;

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