#pragma once
#include"FunctionFactory.h"
#include <iostream>

void run(const char* filename, unsigned a, unsigned b, bool regime) {
    PartialFunction* ptr = nullptr;

    try {
        ptr = readFromFile(filename); // Ensure to handle possible exceptions here
    }
    catch (const std::exception& e) {
        std::cerr << "Error reading from file: " << e.what() << std::endl;
        return;
    }

    if (!regime) {
        for (size_t i = a; i < b; i++) {
            try {
                std::cout << "F(" << i << ")=" << (*ptr)(i) << std::endl; // Use i instead of 0
            }
            catch (const std::exception& e) {
                std::cerr << "Error for F(" << i << "): " << e.what() << std::endl;
                continue;
            }
        }
    }

	else {
        for (size_t i = a; i < b; ++i) {
            char userInput;
            std::cout << "Generate next result? (y/n)!";
            

            while (true)
            {
                std::cin >> userInput; 
                if (userInput == 'y' || userInput == 'Y') {
                    try {
                        std::cout << "F(" << i << ") = " << (*ptr)(i) << std::endl;
                    }
                    catch (const std::exception& e) {
                        std::cerr << "Error for F(" << i << "): " << e.what() << std::endl;
                    }
                }
                else if(userInput == 'n' || userInput == 'N'){
                    break;
                }
                else {
                    std::cout << "You have given an undefined symbol! Please try again!";
                    continue;
                }
            }

            if (userInput == 'y' || userInput == 'Y') {
                try {
                    std::cout << "F(" << i << ") = " << (*ptr)(i) << std::endl;
                }
                catch (const std::exception& e) {
                    std::cerr << "Error for F(" << i << "): " << e.what() << std::endl;
                }
            }
            else {
                break;
            }
        }
	}

    delete ptr;
}