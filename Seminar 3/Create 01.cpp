#include <iostream>
#include <fstream>
#include <sstream>

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

//void getArrayCol(std::stringstream& str , char* row, int** matrix, int indexRow , char sep) {
//
//	int currColIndex = 0;
//
//	while (!str.eof()){
//
//		str.getline((char*)matrix[indexRow][currColIndex++], 1024,',');
//		std::cout << matrix[indexRow][currColIndex++];
//
//	}
//
//
//	matrix[indexRow] = new int[3];
//	
//}

int** initialiseMatrix(std::ifstream& in, int** matrix ,const char& sep) {

	size_t currRow = 0;

	while (!in.eof()){

		matrix[currRow] = new int[100];

		char* col = new char[40];

		in.getline(col,40,sep);
		

		std::stringstream str(col); //3,3,1
		
		size_t currColIDx = 0;

		while (!str.eof())
		{

			char row [100];
			str.getline(row,1024,',');
			matrix[currRow][currColIDx++] = getIntFromChar(row);
			std::cout << matrix[currRow][(--currColIDx)];

		}

		currRow++;
		str.clear();

	}
	return matrix;
}

void printMatrix(int** const matrix, const size_t rows, const size_t cols) {

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout<<matrix[rows][cols]<< " ";
		}

		std::cout << std::endl;
	}
}

int main(){
   
	 std::ifstream in1("1.txt", std::ios::in);
	 if (!in1.is_open())
	 {
		 return 0 ;
	 }

	 std::ifstream in2("2.txt" , std::ios::in);
	 if (!in2.is_open())
	 {
		 in2.close();
		 return 0 ;
	 }

	 int** matrix1 = new int*[40];
	 int** matrix2 = new int* [40];

	 matrix1 = initialiseMatrix(in1, matrix1 , '|');

	 printMatrix(matrix1, 3, 3);
	

	 in1.close();
	 in2.close();
}

