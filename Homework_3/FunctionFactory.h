#pragma once
#pragma once
#include "PartialFunction.h"
#include "PartialFunctionCollection.h"

void readFromFile(PartialFunctionCollection& functionCollection) {

    unsigned N, T;

    while (true) {
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
    }
    /*0 – следват 2N цели 32-битови числа, които определят функцията (<аrg1>... <аrgN> <res1> ... <resN>).
    Функцията е дефинирана само в подадените аргументи.
1 – следват N цели 32-битови числа, определящи частична функция, която не е дефинирана в нито
едно от дадените числа. За всяко друго подадено x функция да връща x.
2 – следват N цели 32-битови числа, определящи частична функция, която връща 1, само ако като аргумент е подадено някое от тези числа, и 0 за всяко друго. Функцията е дефинирана за всяко число.
3 – следват N низа, всеки от тях терминиран с 0 и описващ път към двоичен файл. Подадените двоични файлове също задават частични функции, като техният максимум представя текущата частична функция.
4 – следват N низа, всеки от тях терминиран с 0 и описващ път към двоичен файл. Подадените двоични файлове също задават частични функции, като техният минимум представя текущата частична функция.
*/
    /*
    switch (T)
    {
    case 0:
        for (size_t i = 0; i < (2 * N); i++) {
            functionCollection.addPartialFunction();
        }
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }*/

}