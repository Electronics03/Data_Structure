/*
 * File: additional.cpp
 * Description: The program receives user input in the form of either "Opcode Operand" or "Opcode"
 * 				Decoder decodes the opcode to modify the list according to the user's operation.
 * Provide 5 Opcode
 * 		1. add data
 * 		2. remove
 * 		3. forward
 * 		4. backward
 * 		5. exit
 * Author: Electronics03
 */
#include <iostream>
#include <string>
#include "CDList.h"

// Function to decode and execute user's command
bool decode(string &opCode, CDList &playList)
{
    if (opCode == "add") // If user entered "add"
    {
        string input;
        std::cin >> input;
        std::cout << "add(" << input << ")" << std::endl; // Print the command and data
        playList.add(input);                              // Add the input element to the list
        std::cout << playList << std::endl;               // Print elements of list
        return true;                                      // return continue flag -> continue the loop
    }
    else if (opCode == "remove") // If user entered "remove"
    {
        std::cout << "remove()" << std::endl; // Print the command
        playList.remove();                    // Remove the node after the cursor
        std::cout << playList << std::endl;   // Print elements of list
        return true;                          // return continue flag -> continue the loop
    }
    else if (opCode == "forward") // If user entered "forward"
    {
        std::cout << "forward()" << std::endl; // Print the command
        playList.forward();                    // Move the cursor to the next node
        std::cout << playList << std::endl;    // Print elements of list
        return true;                           // return continue flag -> continue the loop
    }
    else if (opCode == "backward") // If user entered "exit"
    {
        std::cout << "backward()" << std::endl; // Print the command
        playList.backward();                    // Move the cursor to the prev node
        std::cout << playList << std::endl;     // Print elements of list
        return true;                            // return continue flag -> continue the loop
    }
    else if (opCode == "exit")
    {
        return false; // return exit flag -> Exit the loop
    }
    else // Invalid command
    {
        // print Error message
        std::cout << "ERROR: Can not decode." << std::endl;
        return false; // return exit flag -> Exit the loop
    }
}

int main()
{
    CDList playList; // Create circular doubly linked list
    bool rp = true;  // Control flag for main loop
    while (rp)       // Loop until the user enters "exit" or invalid command
    {
        string opCode;
        std::cin >> opCode;            // Read user command
        rp = decode(opCode, playList); // Execute command and update loop flag
    }
    return EXIT_SUCCESS;
}