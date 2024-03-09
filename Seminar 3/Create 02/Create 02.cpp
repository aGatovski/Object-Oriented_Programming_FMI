#include <iostream>
#include <fstream>
#include<sstream>

namespace GLOBAL_CONSTANTS {
    constexpr size_t NAME_SIZE = 16;
    constexpr size_t FACULTY_NUMBER_SIZE = 6;
    constexpr size_t HAIR_COULOR_SIZE = 10;
    constexpr size_t CLASS_SIZE = 1024 ;
    constexpr char FILENAME[] = "table.csv";
    constexpr size_t BUFFER_SIZE = 55 ;
    constexpr char ROW_SEPARATOR = ',';
    constexpr size_t NUMBER_ELEMENTS_ROW = 5;
};

struct Student {
    char firstName[GLOBAL_CONSTANTS::NAME_SIZE];
    char lastName[GLOBAL_CONSTANTS::NAME_SIZE];
    char facultyNumber[GLOBAL_CONSTANTS::FACULTY_NUMBER_SIZE];
    char averageGrade[GLOBAL_CONSTANTS::FACULTY_NUMBER_SIZE];
    char hairColour[GLOBAL_CONSTANTS::HAIR_COULOR_SIZE];
};

struct Class {
    Student studentsArr[GLOBAL_CONSTANTS::CLASS_SIZE];
};

Student readStudentFromRow(const char* row) {
    Student studentToReturn;

    std::stringstream ss(row);
    char buffer[GLOBAL_CONSTANTS::BUFFER_SIZE];

    ss.getline(studentToReturn.firstName, GLOBAL_CONSTANTS::NAME_SIZE, GLOBAL_CONSTANTS::ROW_SEPARATOR);
    ss.getline(studentToReturn.lastName, GLOBAL_CONSTANTS::NAME_SIZE, GLOBAL_CONSTANTS::ROW_SEPARATOR);
    ss.getline(studentToReturn.facultyNumber, GLOBAL_CONSTANTS::FACULTY_NUMBER_SIZE, GLOBAL_CONSTANTS::ROW_SEPARATOR);
    ss.getline(studentToReturn.averageGrade, GLOBAL_CONSTANTS::FACULTY_NUMBER_SIZE, GLOBAL_CONSTANTS::ROW_SEPARATOR);
    ss.getline(studentToReturn.hairColour, GLOBAL_CONSTANTS::HAIR_COULOR_SIZE, GLOBAL_CONSTANTS::ROW_SEPARATOR);

    return studentToReturn;
}

Class parseFromFile(std::ifstream& in, size_t& classSize) {
    Class result;
    char buffer[GLOBAL_CONSTANTS::BUFFER_SIZE];

    while (in.getline(buffer, GLOBAL_CONSTANTS::BUFFER_SIZE)) {
        result.studentsArr[classSize] = readStudentFromRow(buffer);
        classSize++;

        // Check for exceeding max students
        if (classSize >= GLOBAL_CONSTANTS::CLASS_SIZE) {
            std::cerr << "Max number of students exceeded." << std::endl;
            break;
        }
    }

    return result;
}


Class parseFromFile(const char* fileName,size_t& classSize) {
    std::ifstream in(fileName);

    if (!in.is_open()) {
        std::cout << "Could not open file to read" << std::endl;

        // Return an empty class
        Class studentsArr;
        return studentsArr;
    }

    return parseFromFile(in, classSize);
}

void printClass(Class& studentsArr,size_t classSize) {

    for (size_t i = 1; i < classSize; i++) {
        
        if (studentsArr.studentsArr[i].firstName[0] != '\0') {
            std::cout << "Student " << i << ":\n";
            std::cout << "First Name: " << studentsArr.studentsArr[i].firstName << std::endl;
            std::cout << "Last Name: " << studentsArr.studentsArr[i].lastName << std::endl;
            std::cout << "Faculty Number: " << studentsArr.studentsArr[i].facultyNumber << std::endl;
            std::cout << "Average Grade: " << studentsArr.studentsArr[i].averageGrade << std::endl;
            std::cout << "Hair Colour: " << studentsArr.studentsArr[i].hairColour << std::endl;
            std::cout << std::endl;
        }
    }
}

int main(){

    size_t classSize = 0;

    Class studentsArr = parseFromFile("table.csv", classSize);
    printClass(studentsArr, classSize);



   /* std::ifstream in(GLOBAL_CONSTANTS::FILENAME);

    if (!in.is_open()){
        std::cout << "Could not open file to read" << std::endl;
        return -1;
    }*/
}
