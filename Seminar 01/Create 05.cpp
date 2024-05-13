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

void swapGrade(double* xp, double* yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void swapChar(char& ch1, char& ch2) {

	char temp = ch1;
	ch1 = ch2;
	ch2 = temp;
}

size_t getStrLength(const char* text) {
	if (!text) {
		return 0;
	}

	size_t length = 0;

	while (text[length]) {
		length++;
	}

	return length;
}

void swapTextArr(char* s1, char* s2) {
	
	for (size_t i = 0; i < fnConstant; i++){
		swapChar(s1[i], s2[i]);
	}


}

void classSortByGrade(Class& group, size_t numberOfStudents) {

	for (size_t i = 0; i < numberOfStudents-1; i++)
	{
		size_t minIdx = i;

		for (size_t j= i+1; j < numberOfStudents; j++)
		{
			if (group.classArr[j].grade <= group.classArr[minIdx].grade) {
				minIdx = j;

				swapGrade(&group.classArr[minIdx].grade, &group.classArr[i].grade);

				swapTextArr(group.classArr[minIdx].fn, group.classArr[i].fn);
				
				swapTextArr(group.classArr[minIdx].name, group.classArr[i].name);
			}

		}
	}

}

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

		if (group.classArr[i].grade >= minimalGradeForScholarship){
			numberOfScholars++;
		}
	}

	return numberOfScholars;
}

void printScholars(Class& group, const double& minimalGradeForScholarship, const size_t& numberOfStudents) {

	classSortByGrade(group, numberOfStudents);
	printClass(group, numberOfStudents);

	for (size_t i = 0; i < numberOfStudents; i++){
		if (group.classArr[i].grade >= minimalGradeForScholarship) {
			std::cout << "Name: " << group.classArr[i].name << " with a grade: " << group.classArr[i].grade << " get's a scholarship" << std::endl;
		}
	}
}

bool isSameString(const char* str1, const char* str2) {

	size_t length = getStrLength(str1);

	for (size_t i = 0; i < length; i++)
	{
		if (str1[i] != str2[i]) {
			return false;
		}
	}
	return true;
}

bool isStudentInGroup(const Class& group, const size_t& numberOfStudents, const char* FN) {

	for (size_t i = 0; i < numberOfStudents; i++)
	{
		if (isSameString(group.classArr[i].fn, FN)) {
			return true;
		}
		
	}
	return false;
}

int main() {

	
	unsigned numberOfStudents;
	std::cin >> numberOfStudents;

	Class group;
	initializeClass(group,numberOfStudents);
	printClass(group, numberOfStudents);

	//Minimal grade for scholarship;
	std::cout <<"Min Grade is: "  << std::endl;
	double minGrade;
	std::cin >> minGrade;

	std::cout << "Number of students with scholarships: " <<  numberOfScholarships(group, numberOfStudents, minGrade)<<std::endl;

	printScholars(group, minGrade, numberOfStudents);


	//Check student in group
	Student check;

	initializeStudent(check);

	std::cout << isStudentInGroup(group,numberOfStudents, check.fn);

}
