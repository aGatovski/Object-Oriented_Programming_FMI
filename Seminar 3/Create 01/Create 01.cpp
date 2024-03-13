

#include <iostream>
#include <fstream>
#include <sstream>

namespace GLOBAL_CONSTANTS {
	constexpr char firstFileName[] = "1.txt";
	constexpr char secondFileName[] = "2.txt";
	constexpr char outputFileName[] = "output.txt";
	constexpr char ROW_SEPARATOR = '|';
	constexpr char COL_SEPARATOR = ',';
	constexpr size_t INPUT_TEXT_SIZE = 100;
}

void getMatrixDimensions(std::ifstream& in, size_t& rows, size_t& cols) {
	char input;

	while (!in.eof())
	{
		in.get(input);
		if (input == GLOBAL_CONSTANTS::ROW_SEPARATOR) {
			rows++;
		}
		if (input == GLOBAL_CONSTANTS::COL_SEPARATOR) {
			cols++;
		}
	}

	cols = cols / rows;
	rows++;

	in.clear();
	in.seekg(0, std::ios::beg);
}

size_t convertCharToDigit(char ch) {
	return ch - '0';
}

int getIntFromChar(const char* str) {

	if (!str) {
		return 0;
	}

	int number = 0;

	if (*str == '-') {
		str++;
		while (*str) {
			number = number * 10 + convertCharToDigit(*str);
			str++;
		}

		return -number;
	}

	else {
		while (*str) {
			number = number * 10 + convertCharToDigit(*str);
			str++;
		}

		return number;
	}
}

void initialiseMatrix(std::ifstream& in, int** matrix, const char& sep) {
	size_t currRow = 0;

	while (!in.eof()) {
		//Initialise the current row array;
		matrix[currRow] = new int[GLOBAL_CONSTANTS::INPUT_TEXT_SIZE];

		//Get the current column content
		char* columnBuff = new char[GLOBAL_CONSTANTS::INPUT_TEXT_SIZE];
		in.getline(columnBuff, GLOBAL_CONSTANTS::INPUT_TEXT_SIZE, sep);

		//StringStream the column to be able to easily split it;
		std::stringstream str(columnBuff); //3,3,1

		size_t currColIDx = 0;
		while (!str.eof())
		{
			char rowBuff[GLOBAL_CONSTANTS::INPUT_TEXT_SIZE];
			str.getline(rowBuff, GLOBAL_CONSTANTS::INPUT_TEXT_SIZE, ',');
			matrix[currRow][currColIDx++] = getIntFromChar(rowBuff);

		}

		currRow++;
	}
}

void printMatrix(int** const matrix, const size_t rows, const size_t cols) {

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

int** matrixMultiplication(int** const matrixOne, const size_t& rows1, const size_t& cols1, int** const matrixTwo, const size_t& rows2, const size_t& cols2, size_t& rowsResult, size_t& colsResult) {

	if (cols1 == rows2) {
		rowsResult = rows1;
		colsResult = cols2;

		int** matrixResult = new int* [rows1];

		for (size_t i = 0; i < rows1; i++) {
			matrixResult[i] = new int[cols2];

			for (size_t j = 0; j < cols2; j++) {
				matrixResult[i][j] = 0;

				for (size_t k = 0; k < cols1; k++) {
					matrixResult[i][j] += matrixOne[i][k] * matrixTwo[k][j];
				}
			}
		}

		printMatrix(matrixResult, rows1, cols2);

		return matrixResult;
	}
	
	else if (cols2 == rows1) {
		rowsResult = rows2;
		colsResult = cols1;

		int** matrixResult = new int* [rows2];

		for (size_t i = 0; i < rows2; i++) {
			matrixResult[i] = new int[cols1];

			for (size_t j = 0; j < cols1; j++) {
				matrixResult[i][j] = 0;

				for (size_t k = 0; k < cols2; k++) {
					matrixResult[i][j] += matrixOne[i][k] * matrixTwo[k][j];
				}
			}
		}
		return matrixResult;
	}

	else {
	std::cout << "Impossible to multiply the matrixes";
	return nullptr;
	}

}

void printContentsInFile(std::ofstream& output, int** const matrix, const size_t rows, const size_t cols) {

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {

			if (j == cols - 1) {
				output << matrix[i][j] << GLOBAL_CONSTANTS::ROW_SEPARATOR;
			}
			else {
				output << matrix[i][j] << GLOBAL_CONSTANTS::COL_SEPARATOR;
			}
		}
	}
}

int main() {

	//Check if both files are correctly open
	std::ifstream in1(GLOBAL_CONSTANTS::firstFileName, std::ios::in);
	if (!in1.is_open())
	{
		return 0;
	}

	std::ifstream in2(GLOBAL_CONSTANTS::secondFileName, std::ios::in);
	if (!in2.is_open())
	{
		in2.close();
		return 0;
	}

	size_t rowsCount1 = 0, rowsCount2 = 0, colsCount1 = 0, colsCount2 = 0;
	getMatrixDimensions(in1, rowsCount1, colsCount1);
	getMatrixDimensions(in2, rowsCount2, colsCount2);

	//Initialise matrixes
	int** matrix1 = new int* [rowsCount1];
	int** matrix2 = new int* [rowsCount2];

	initialiseMatrix(in1, matrix1, GLOBAL_CONSTANTS::ROW_SEPARATOR);
	initialiseMatrix(in2, matrix2, GLOBAL_CONSTANTS::ROW_SEPARATOR);

	//Close the inputFiles
	in1.close();
	in2.close();

	std::ofstream output(GLOBAL_CONSTANTS::outputFileName, std::ios::out | std::ios::trunc);

	if (!output.is_open()) {
		return -1;
	}

	int** matrixResult;
	size_t rowsResult = 0;
	size_t colsResult = 0;

	matrixResult = matrixMultiplication(matrix1, rowsCount1, colsCount1, matrix2, rowsCount2, colsCount2, rowsResult, colsResult);

	printContentsInFile(output, matrixResult, rowsResult, colsResult);



	output.close();

	// Free allocated memory
	for (size_t i = 0; i < rowsCount1; i++) {
		delete[] matrix1[i];
	}

	for (size_t i = 0; i < rowsCount2; i++) {
		delete[] matrix2[i];
	}


	delete[] matrix1;
	delete[] matrix2;

	return 0;
}
