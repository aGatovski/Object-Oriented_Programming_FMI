#pragma once
//#include "FunctionFactory.cpp"
#include "FunctionFactory.h"
#include "PartialFunction.h"
namespace {
    constexpr char fileName[] = "try.dat";
    constexpr char fileName1[] = "3.dat";
}


int main()
{
    PartialFunction* ptr = readFromFile(fileName1);
    try
    {
      
        std::cout <<p[0](0);
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
  
}

/* while (true) {
        //try {
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


/*std::ofstream ofs(fileName, std::ios::binary);
    if (!ofs.is_open()) {
        throw std::runtime_error("Error: Unable to open file - func.dat!");
    }

    std::ofstream ofs1(fileName1, std::ios::binary);
    if (!ofs.is_open()) {
        throw std::runtime_error("Error: Unable to open file - func.dat!");
    }
    unsigned int N1 = 7, T1 = 0;
    int32_t arr[14] { 0 ,1 ,2 ,3, 5,  6 ,7,0 ,3 ,3 ,3 ,4 ,4, 0};
    int32_t arr[14]{2,1 };
    ofs1.write((const char*)&N1, sizeof(N1));
    ofs1.write((const char*)&T1, sizeof(T1));

    ofs1.write((const char*)arr, 14 * sizeof(int32_t));

    /*unsigned N = 3, T =3;
    const char* a= "1.dat";
    const char* b = "second.dat";
    const char* c = "third.dat";
    ofs.write((const char*)&N, sizeof(N));
    ofs.write((const char*)&T, sizeof(T));
    ofs.write((const char*)a, strlen(a));*/

