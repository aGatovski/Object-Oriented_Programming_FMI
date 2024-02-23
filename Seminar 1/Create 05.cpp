#include <iostream>
double epsilon = 0.000001;

enum Constants {

	nameConstant = 1024,
	fnConstant = 11,
	studentsInClass=10,
	
};

struct Student {
	char name[nameConstant];
	char fn[fnConstant];
	double grade;
};

struct Class {
	Student classArr[studentsInClass];
	double classAvrGrade;
};

void initializeStudent(Student& s) {
	std::cin >> s.name >> s.fn >> s.grade;
}

void printStudent(const Student& s) {
	std::cout << s.name<<" " << s.fn <<" " << s.grade << std::endl;
}

void initializeClass(Class& group,const unsigned& numberOfStudents) {

	double totalAvr = 0;
	for (size_t i = 0; i < numberOfStudents; i++)
	{
		initializeStudent(group.classArr[i]);
		totalAvr += group.classArr[i].grade;
	}

	group.classAvrGrade=totalAvr / numberOfStudents;

}

void printClass(const Class& group,const unsigned& numberOfStudents) {
	for (size_t i = 0; i < numberOfStudents; i++)
	{
		std::cout << "Student #" << i + 1;
		printStudent(group.classArr[i]);
	}
	std::cout << "Class Average Grade " << group.classAvrGrade;
}

size_t numberOfScholarships(const Class& group,const size_t& numberOfStudents,const double& minimalGradeForScholarship ) {
	size_t numberOfScholars = 0;

	for (size_t i = 0; i < numberOfStudents; i++){

		if (abs(group.classArr[i].grade - minimalGradeForScholarship) < epsilon){
			numberOfScholars++;
		}
	}

	return numberOfScholars;
}

int main() {

	
	unsigned numberOfStudents;
	std::cin >> numberOfStudents;

	Class group;
	initializeClass(group,numberOfStudents);
	printClass(group, numberOfStudents);
	std::cout <<"Min Grade is: "  << std::endl;
	double minGrade;
	std::cin >> minGrade;

	std::cout << "Number of students with scholarships: " <<  numberOfScholarships(group, numberOfStudents, minGrade);

}
