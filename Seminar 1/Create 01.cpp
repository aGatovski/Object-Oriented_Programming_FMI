#include <iostream>
struct Person
{
    bool isStudent;
    short averageGrade;
    int age;
   
};

void createPerson(Person& p)
{
    std::cin >> p.isStudent >> p.age >> p.averageGrade;
}

void printStudent(const Person& p)
{
    std::cout << p.isStudent<<  " " << p.age <<" " << p.averageGrade << std::endl;
}

int main()
{
    Person p;

    createPerson(p);
    printStudent(p);

    Person* personRef = &p;
    std::cout << (*personRef).age;
}
