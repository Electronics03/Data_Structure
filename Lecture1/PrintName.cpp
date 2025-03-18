#include <iostream>
#include <string>

int main(void)
{
    std::cout << "What is your name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Your name is " << name << std::endl;
    return 0;
}