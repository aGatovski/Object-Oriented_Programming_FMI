#pragma once
#include"FunctionFactory.h"
#include <iostream>

namespace {
	constexpr char filename[] = "func.dat";
}

void run(unsigned a, unsigned b, bool regime) {
	PartialFunction* ptr;
	ptr = readFromFile(filename);

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

	/*else {

	}*/

    delete ptr;
}