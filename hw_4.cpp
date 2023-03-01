#include <iostream>
#include <cmath>
#include <typeinfo>

//Option 6. Given a two - dimensional array of numbers.Calculate the product of one and the second diagonal of the array of numbers.

int getCalcDiagonalMult(int m[][3], int row, int col);
void getSumOfMatrixElems();
void getMultOfPositiveElems(int* array, const int SIZE);
int getFillThirdMatrixUsingTwo(int** , int**);
int getCreateMatrix();

int main() {
	//Array for first task
	int arr[][3] = {
		{4, 2, 3},
		{4, 2, 6},
		{7, 8, 9}
	};
	//Array for 2 task
	const int SIZE = 11;
	int array2[] = { 3, 2, -12, 2, 4, -1, 1, 2, 3, -4, 1 };

	getCalcDiagonalMult(arr, 3, 3);
	getSumOfMatrixElems();
	getMultOfPositiveElems(array2, SIZE);
	//getFillThirdMatrixUsingTwo();
	/*const int ROW = 3, COL = 3;
	int** pMatrix = new int*[3];
	getCreateMatrix(pMatrix, pMatrix);*/

	return 0;
}

int getCalcDiagonalMult(int m[][3], int row, int col) {
	int mult1 = 1;
	int mult2 = 1;
	int result;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
		{
			mult1 *= m[i][j];
			i++;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = col - 1; j >= 0; j--)
		{
			mult2 *= m[i][j];
			i++;
		}
	}
	result = mult1 - mult2;
	std::cout << "Multiply of elements from main diagonal is: " << mult1 << "\nMultiply of elements from sub-main diagonal is: " << mult2 << std::endl;
	return 0;
}
//Option 15. Given a two - dimensional matrix of real numbers A[1..N, 1..N].Find the sum of the shaded elements
void getSumOfMatrixElems() {
	int matrix[][5] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 15, 16, 17, 18},
		{22, 19, 20, 21, 22}
	};
	const int ROW = 5, COL = 5;
	int k;
	int sum = 0;
	for (int i = 0; i < ROW; i++)
	{
		if (i < ((ROW / 2) + 1)) {
			k = i;
			for (int j = 0; j <= i; j++) {
				sum += matrix[i][j];
			}
		}
		else {
			for (int j = 0; j <= k; j++) {
				sum += matrix[i][j];
				k--;
			}
		}
	}
	std::cout << "result is: " << sum << std::endl;
}

//Task 2. Find the product of positive elements in an array of 11 elements; determine the max modulo the element.


void getMultOfPositiveElems(int* array, const int SIZE) {
	unsigned int calcMult = 1;
	short* pSeedValue = new short;
	std::cout << "Value: " << *array << std::endl;
	*pSeedValue = *array;
	for (int i = 0; i < SIZE; i++) {
		std::cout << "Value in this address: " << *(array + i) << std::endl;
		if (*(array + i) > 0) {
			calcMult *= *(array + i);
		}
		if (abs(*(array + i)) > *pSeedValue) {
			*pSeedValue = abs(*(array + i));
		}
	}
	std::cout << "Result: " << calcMult << std::endl;
	std::cout << "The max absolute number: " << *pSeedValue << std::endl;
}



//TASK 3 Declare three two - dimensional arrays(matrices)
//and calculate the sum of two matrices by writing the result in the third matrix,
//that is, the results should be a matrix, not a number. Print the obtained result.

int getCreateMatrix() {
	const int ROW = 3, COL = 3;
	int** pMatrix = new int* [ROW];
	for (int i = 0; i < ROW; i++)
	{
		pMatrix[i] = new int[ROW];
	}
	std::cout << "Fill matrix: ";
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			std::cin >> pMatrix[i][j];
		}
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++) {
			std::cout << pMatrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	return **pMatrix;
}

int getFillThirdMatrixUsingTwo(int** x, int** y) {
	const int ROW = 3, COL = 3;
	//int** pMatrix = new int* [ROW];
	//int** pMatrix2 = new int* [ROW];
	//for (int i = 0; i < ROW; i++)
	//{
	//	pMatrix[i] = new int[COL];
	//	pMatrix2[i] = new int[COL];
	//}
	//for (int i = 0; i < ROW; i++)
	//{
	//	for (int j = 0; j < COL; j++) {
	//		pMatrix[i][j] = rand() % 15;
	//		pMatrix2[i][j] = rand() % 10;
	//	}
	//}

	int** pMatrix3 = new int* [ROW];
	for (int i = 0; i < ROW; i++)
	{
		pMatrix3[i] = new int[COL];
	};
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++)
		{
			pMatrix3[i][j] = x[i][j] + y[i][j];
		}
	}
	// Displaying the result sum matrix.
	std::cout << std::endl << "Sum of two matrix is: " << std::endl;
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
		{
			std::cout << pMatrix3[i][j] << "  ";
			if (j == COL - 1)
				std::cout << std::endl;
		}
	for (int i = 0; i < ROW; ++i)
	{
		delete x[i];
		delete y[i];
		delete pMatrix3[i];
	}
	delete[] x;
	delete[] y;
	delete[] pMatrix3;
	return 0;
}
