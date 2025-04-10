#include <iostream>
#include <string>
#include "CDList.hpp"

using namespace std;

bool decode(string &opCode, CDList &playList)
{
	if (opCode == "add")
	{
		string input;
		cin >> input;
		std::cout << "add(" << input << ")" << std::endl;
		playList.add(input);
		std::cout << playList << std::endl;
		return true;
	}
	else if (opCode == "remove")
	{
		std::cout << "remove()" << std::endl;
		playList.remove();
		std::cout << playList << std::endl;
		return true;
	}
	else if (opCode == "forward")
	{
		std::cout << "forward()" << std::endl;
		playList.forward();
		std::cout << playList << std::endl;
		return true;
	}
	else if (opCode == "backward")
	{
		std::cout << "backward()" << std::endl;
		playList.backward();
		std::cout << playList << std::endl;
		return true;
	}
	else if (opCode == "exit")
	{
		return false;
	}
	else
	{
		std::cout << "ERROR: Can not decode." << std::endl;
		return false;
	}
}

int main()
{
	CDList playList;
	bool rp = true;
	while (rp)
	{
		string opCode;
		cin >> opCode;
		rp = decode(opCode, playList);
	}
	return EXIT_SUCCESS;
}
// g++ HW1/additional.cpp HW1/CDList.cpp -o HW1/additional