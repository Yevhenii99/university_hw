#include "header_13.h"
#include <iostream>

int main(void) {
	PrintedEdition <short, short, int, short, const char*> printEdition1(1917, 25, 100500, 3300, "NashFormat");
	PrintedEdition <int, short, float, short, const char*> printEdition2(1956, 32, 5000.50f, 4700, "Yakaboo");
	printEdition1.Show();
	printEdition2.Show();
	//Same type of parameters
	std::cout << getMaxValue(10, 14, 8) << std::endl;;
	//Different type of parameters
	std::cout << getMaxValue(23, 4.7f, 16) << std::endl;
	std::cout << getSumOfNums<int>(20, 10) << '\n';
	std::cout << getSumOfNums<float>(20.6f, 10.1f) << '\n';
	//2D array

	int arr[3][2] = {
		{1,2},
		{3,4},
		{5,16}
	};
	float arr3[2][4] = {
	{1, 2.5f, 3.7f, 4},
	{5, 6.5f, 7.5f, 3.9f},
	};
	double arr4[3][4] = {
	{1.5, 2.5, 3.7, 4},
	{5, 6.5, 7.5, 3.9},
	{5.2, 6.5, 7.1, 2.9},
	};
	std::cout << "Int sum: " << getSumOfElements((int*)arr, 3, 2) << '\n';
	std::cout << "Float sum: " << getSumOfElements((float*)arr3, 2, 4) << '\n';
	std::cout << "Double sum: " << getSumOfElements((double*)arr4, 3, 4) << '\n';
	//Task5
	Circle<> circle1(5);
	std::cout << circle1.getLengthOfCircle() << " cm\n";

}