#include <iostream>
#include <string>
#include <vector>
#include "header14.h"


void func(std::vector<std::string>);
std::string getToLower(std::string&);

int main(void) {
	Printery edition;
	edition.getAddElem("Summer");
	edition.getAddElem("Winter");
	edition.getAddElem("Adfjsdajf");
	edition.Print();
	edition.getDeleteElem();
	edition.Print();
	//---Finding string in vector by value from keybord
	std::string inputValue;
	std::cout << "Enter search item: " << std::endl;
	std::getline(std::cin, inputValue);
	edition.compareStrings(inputValue);


	
}

