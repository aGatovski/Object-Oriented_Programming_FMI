#include <iostream>
#include <fstream>
#include <sstream>

namespace GLOBAL_CONSTANTS {

	constexpr char ROW_SEPARATOR = '|';
	constexpr char COL_SEPARATOR = ',';
	constexpr size_t ROW_SIZE = 100;
}


size_t getRowCount(std::ifstream& in) {
	size_t rowsCount = 0;
	char input;

	while (!in.eof()){
		in.get(input);

		if (input == GLOBAL_CONSTANTS::ROW_SEPARATOR){
			rowsCount++;
		}
	}

	in.clear();
	return rowsCount+1;
}

size_t getColCount(std::ifstream& in) {
	size_t colsCount = 0;	
	char input;

	while (!in.eof()) {
		in.get(input);

		if (input == GLOBAL_CONSTANTS::COL_SEPARATOR) {
			colsCount++;
		}
	}

	
	return colsCount;
}


size_t convertCharToDigit(char ch) {
	return ch - '0';
}

int getIntFromChar(const char* str) {

	int number = 0;

	while (*str)
	{
		number = number * 10 + convertCharToDigit(*str);
		str++;
	}
	return number;
}

void getArrayCol(std::stringstream& str , char* row, int** matrix, int indexRow , char sep) {

	int currColIndex = 0;

	while (!str.eof()){

		str.getline((char*)matrix[indexRow][currColIndex++], 1024,',');
		std::cout << matrix[indexRow][currColIndex++];

	}


	matrix[indexRow] = new int[3];
	
}

void printMatrix(int** const matrix, const size_t rows, const size_t cols) {

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << matrix[rows][cols] << " ";
		}

		std::cout << std::endl;
	}
}



int** initialiseMatrix(std::ifstream& in, int** matrix, const char& sep) {

	size_t currRow = 0;

	while (!in.eof()) {

		matrix[currRow] = new int[100];

		char* col = new char[40];

		in.getline(col, 40, sep);


		std::stringstream str(col); //3,3,1

		size_t currColIDx = 0;

		while (!str.eof())
		{

			char row[100];
			str.getline(row, 1024, ',');
			matrix[currRow][currColIDx++] = getIntFromChar(row);
			//std::cout << matrix[currRow][(--currColIDx)];

		}

		currRow++;
		str.clear();

	}

	printMatrix(matrix,2,2);

	return matrix;
}


int main() {

	std::ifstream in1("1.txt", std::ios::in);
	if (!in1.is_open())
	{
		return 0;
	}

	std::ifstream in2("2.txt", std::ios::in);
	if (!in2.is_open())
	{
		in2.close();
		return 0;
	}

	//get number of rows
	const size_t rowsCount1 = getRowCount(in1);
	const size_t rowsCount2 = getRowCount(in2);

	in1.seekg(0, std::ios::beg);
	in2.seekg(0, std::ios::beg);

	//get number of cols
	const size_t colsCount1 = getColCount(in1);
	const size_t colssCount2 = getColCount(in2);

	in1.clear();
	in2.clear();

	in1.seekg(0, std::ios::beg);
	in2.seekg(0, std::ios::beg);


	int** matrix1 = new int*[rowsCount1];
	int** matrix2 = new int* [rowsCount2];

	matrix1[0] = new int[40];


	matrix1 = initialiseMatrix(in1, matrix1, GLOBAL_CONSTANTS::ROW_SEPARATOR);

	//printMatrix(matrix1, 3, 3);


	// Free allocated memory
	for (size_t i = 0; i < 40; i++) {
		delete[] matrix1[i];
		delete[] matrix2[i];
	}
	delete[] matrix1;
	delete[] matrix2;

	in1.close();
	in2.close();

	return 0;
}
