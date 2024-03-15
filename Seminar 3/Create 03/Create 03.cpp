#include <iostream>
#include <fstream>
#include <sstream>
#pragma warning(disable : 4996);

namespace GLOBAL_CONSTANTS {
    constexpr short FIRM_NAME_SIZE = 25;
    constexpr char FILE_NAME[] = "companies.dat";
    constexpr size_t LINE_SIZE = 1024;
    constexpr char FIRM_SEPARATOR = ':';
    constexpr char INFO_SEPARATOR = ',';
};

struct Firm {
    char firmName[GLOBAL_CONSTANTS::FIRM_NAME_SIZE];
    size_t numberOfEmployees;
    size_t daysOff;
    long long salary;
};

size_t getFileSize(std::ifstream& in) {

    size_t current = in.tellg();
    in.seekg(0, std::ios::end);
    size_t size = in.tellg();
    in.seekg(current, std::ios::beg);

    return size;
}

int convertTextToNumber(const char* text) {
    if (!text) {
        return -1;
    }

    int number = 0;

    while (*text)
    {
        number = number * 10 + (*text - '0');
        text++;
    }

    return number;
}

Firm initFirm(const char* input) {
    Firm f;
    
    std::stringstream line(input);

    char buff[100];

    line.getline(buff, GLOBAL_CONSTANTS::FIRM_NAME_SIZE, GLOBAL_CONSTANTS::INFO_SEPARATOR);
    strcpy(f.firmName, buff);
    std::cout << f.firmName<<" ";

    line.getline(buff, 10, GLOBAL_CONSTANTS::INFO_SEPARATOR);
    f.numberOfEmployees = convertTextToNumber(buff);
    std::cout << f.numberOfEmployees<<" ";

    line.getline(buff, 10, GLOBAL_CONSTANTS::INFO_SEPARATOR);
    f.daysOff = convertTextToNumber(buff);
    std::cout << f.daysOff<<" ";
    
    line.getline(buff, 10, GLOBAL_CONSTANTS::INFO_SEPARATOR);
    f.salary = convertTextToNumber(buff);
    std::cout << f.salary << " ";


    return f;
}

Firm* initFirms(Firm* firmsArr, const size_t firmsNumber) {
    char buffer[GLOBAL_CONSTANTS::LINE_SIZE+1];
    
    std::cin.getline(buffer, GLOBAL_CONSTANTS::LINE_SIZE);
    std::stringstream input(buffer);

    for (size_t i = 0; i < firmsNumber; i++) {
        input.getline(buffer, GLOBAL_CONSTANTS::LINE_SIZE, GLOBAL_CONSTANTS::FIRM_SEPARATOR); 
        firmsArr[i] = initFirm(buffer);
    }

    return firmsArr;
}

void writeFirmsToFile(const char* filePath, Firm* firmsArr,const size_t firmsNumber) {

    std::ofstream out(filePath, std::ios::binary | std::ios::out | std::ios::app);

    if (!out.is_open()) {
        return;
    }

    firmsArr = initFirms(firmsArr, firmsNumber);
   
    for (size_t i = 0; i < firmsNumber; i++)
    {
        out.write((const char*)&firmsArr[i], sizeof(Firm));
    }

    out.close();
}

void readFromFile(Firm& f,std::ifstream& in) {
    in.read((char*)&f, sizeof(f));
}

void filterOffers(const char* filePath, long long minSalary) {
    std::ifstream in(filePath, std::ios::binary | std::ios::in);

    if (!in.is_open()) {
        return;
    }

    while (!in.eof())
    {
        Firm f;
        readFromFile(f, in);
        if (in.eof()) {
            return;
        }
       
        if (f.salary >= minSalary) {
            std::cout << f.firmName << " " << f.numberOfEmployees << " " << f.daysOff << " " << f.salary;
        }
    }

    in.close();
}

int main(){
    size_t queries;
    std::cin >> queries;
    std::cin.ignore();

    Firm* firmsArr = new Firm[queries];
    writeFirmsToFile(GLOBAL_CONSTANTS::FILE_NAME, firmsArr,queries);

   size_t minimumSalary;
   std::cin >> minimumSalary;
   filterOffers(GLOBAL_CONSTANTS::FILE_NAME, minimumSalary);
   
}

//*
// Firma 1,10,20,10000:Firma 2,12,22,20000
// */
