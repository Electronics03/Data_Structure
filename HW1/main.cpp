#include <iostream>
#include "CDList.hpp"

int main()
{
	CDList playList;

	std::cout << "add(SA)" << std::endl;
	playList.add("SA");
	std::cout << playList << std::endl;

	std::cout << "add(LF)" << std::endl;
	playList.add("LF");
	std::cout << playList << std::endl;

	std::cout << "add(JT)" << std::endl;
	playList.add("JT");
	std::cout << playList << std::endl;

	std::cout << "forward()" << std::endl;
	playList.forward();
	std::cout << playList << std::endl;

	std::cout << "forward()" << std::endl;
	playList.forward();
	std::cout << playList << std::endl;

	std::cout << "remove()" << std::endl;
	playList.remove();
	std::cout << playList << std::endl;

	std::cout << "add(DI)" << std::endl;
	playList.add("DI");
	std::cout << playList << std::endl;

	std::cout << "backward()" << std::endl;
	playList.backward();
	std::cout << playList << std::endl;

	std::cout << "backward()" << std::endl;
	playList.backward();
	std::cout << playList << std::endl;

	std::cout << "remove()" << std::endl;
	playList.remove();
	std::cout << playList << std::endl;

	std::cout << "remove()" << std::endl;
	playList.remove();
	std::cout << playList << std::endl;

	std::cout << "remove()" << std::endl;
	playList.remove();
	std::cout << playList << std::endl;

	std::cout << "remove()" << std::endl;
	playList.remove();
	std::cout << playList << std::endl;

	return EXIT_SUCCESS;
}
// g++ HW1/main.cpp HW1/CDList.cpp -o HW1/main