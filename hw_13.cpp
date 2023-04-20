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
}