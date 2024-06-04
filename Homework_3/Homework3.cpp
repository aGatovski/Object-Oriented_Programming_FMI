#include <iostream>
#include"PartialFunction.h"
#include"CriteriaFunction.hpp"
#include "PartialFunctionCollection.h"
#include "FunctionFactory.cpp"

namespace {
    constexpr char fileName[] = "func.dat";
}


int main()
{

    PartialFunctionCollection p;
    readFromFile(fileName,p);

}

/* while (true) {
        try {
            std::cout << "Enter N (0-32) and T (0-4): ";
            std::cin >> N >> T;

            // Check if the input is valid
            if (std::cin.fail()) {
                throw std::invalid_argument("Input is not a number.");
            }

            // Check if N is in the range 0-32 and T is in the range 0-4
            if (N > 32) {
                throw std::out_of_range("N is out of range (0-32).");
            }

            if (T > 4) {
                throw std::out_of_range("T is out of range (0-4).");
            }

            // If everything is fine, break the loop
            break;
        }


        catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << " Please enter valid numbers.\n";
            // Clear error flags
            std::cin.clear();
            // Ignore the invalid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Error: " << e.what() << " Please enter numbers within the specified range.\n";
            // Clear error flags
            std::cin.clear();
            // Ignore the invalid input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    }*/