#include <iostream>

void swap(int& x, int& y) {
	int temp = y;
	y = x;
	x = temp;
}

void printMatrix(int** matrix,const size_t& rows, const  size_t& cols) {

	for (size_t i = 0; i < rows; i++)
	{

		for (size_t j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j]<<" ";
		}
		std::cout << std::endl;
	}

}

void initialiseMatrix(int** matrix, const size_t& rows, const size_t& cols) {

	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];

		for (size_t j = 0; j < cols; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

}

int** transponseMatrix(int** matrix, const size_t& cols, const size_t& rows) {

	int** transMatrix = new int* [rows];

	for (size_t i = 0; i < rows; i++){

		transMatrix[i] = new int[cols];

		for (size_t j = 0; j < cols; j++){

			transMatrix[i][j] = matrix[j][i];
		}

	}
	return transMatrix;
}

void swapRow(int** matrix, const size_t& row1, const size_t& row2, const size_t& cols) {

	for (size_t i = 0; i < cols; i++)
	{
		swap(matrix[row1][i], matrix[row2][i]);
	}

}

int main() {

	//initialise and print matrix
	size_t N, M; //N rows M cols
	std::cin >> N >> M;

	int** matrix = new int*[N];

	initialiseMatrix(matrix, N, M);
	printMatrix(matrix, N, M);
	std::cout << std::endl;

	//transponse matrix
	int** transMatrix = transponseMatrix(matrix, N, M);

	printMatrix(transMatrix,M,N);
	std::cout << std::endl;


	//swap rols
	size_t row1 = 0;
	size_t row2 = 2;

	swapRow(transMatrix, row1, row2, N);
	printMatrix(transMatrix,M,N);

	for (size_t i = 0; i < N; ++i) {
		// delete the cols of the row
		delete[] matrix[i];
		delete[] transMatrix[i];
	}
	// delete the rows
	delete[] matrix;
	delete[]transMatrix;
}
