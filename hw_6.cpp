﻿#include <iostream>
#include <string>
#include <iomanip>


//Варіант 6:
//Задача:   Модифікувати код програми із попередньої лабораторної роботи наступним чином :
//Створити в класі наступні типи конструкторів :
//без параметра,
//з одним параметром,
//з двома параметрами
//з трьома параметрами(спеціальні конструктори не використовувати).
//Продемонструвати делегування конструкторів.
//Продемонструвати в коді використання списку ініціалізації.
//Додати деструктор.
//Використати в функції main всі оголошені в класі конструктори та продемонструвати роботу деструктора.Створити та використати вказівник на об‘єкт класу(пам‘ять під об‘єкт виділяється в  HEAP).


class Medicine {
	unsigned short amountOfMed;//by default it is privat field
public:
	char* nameOfMed;
	float priceOfMed;
	float generalPrice = 0;

	void SetAmount(unsigned short amountOfMed) {
		this->amountOfMed = amountOfMed;
	}
	int GetAmount() {
		return amountOfMed;
	}
	float getGeneralPrice(Medicine medicine[], const int size) {
		for (int i = 0; i < size; i++)
		{
			generalPrice += medicine[i].priceOfMed * medicine[i].GetAmount();
		}
		return generalPrice;
	}
	//-----Initialization
	Medicine():priceOfMed(33.3), amountOfMed(23) {
		std::cout << "First constructor work." << std::endl;
		//priceOfMed = 25.4; 
		std::cout << priceOfMed << std::setw(10) << GetAmount() << std::endl;
	}
	Medicine(const char* name) {
		std::cout << "Second constr work." << std::endl;
		nameOfMed = new char[strlen(name) + 1];
		strcpy(nameOfMed, name);
		std::cout << nameOfMed << std::endl;
	}
	Medicine(unsigned short& amount, float& price) {
		std::cout << "Third constr work." << std::endl;
		SetAmount(amount);
		priceOfMed = price;
		std::cout << GetAmount() << std::setw(10) << priceOfMed << std::endl;
	}
	//-----Delegation of constructor
	Medicine(unsigned short* amount, const char* name, float* price):Medicine(*amount, *price) {
		//SetAmount(*amount);
		nameOfMed = new char[strlen(name) + 1];
		strcpy(nameOfMed, name);
		std::cout << nameOfMed << std::endl;
		//priceOfMed = *price;
		//std::cout << GetAmount() << std::setw(20) << nameOfMed << std::setw(20) << priceOfMed << std::endl;
	}
	~Medicine() {
		delete [] nameOfMed;

		std::cout << "Destructor!" << std::endl;
	}

};
int main(void) {

	//const int SIZE = 3;
	//Medicine medicine[SIZE];
	//Medicine price;

	//This code needs to fill our objects
	//for (int i = 0; i < SIZE; i++)
	//{
	//	unsigned int amount;
	//	std::cout << "\nEnter the price: ";
	//	std::cin >> medicine[i].priceOfMed;
	//	std::cout << "\nEnter the name: ";
	//	std::cin >> medicine[i].nameOfMed;
	//	std::cout << "\nEnter amount of med: ";
	//	std::cin >> amount;
	//	medicine[i].SetAmount(amount);

	//}
	char name[] = "Strepsils";
	unsigned short amount = 33;
	float price = 14.5;
	//Medicine a;//call constuctor without any parameters or with default parmtrs
	//Medicine b(name);//call constr with one par
	//Medicine c(amount, price);//call constr with two par
	//Medicine d(&amount, name, &price);//cal constr with three
	{
		Medicine delegation(&amount, name, &price);
	}
	

	//float generalPrice = 0;
	//char letter;
	//bool haveItem = false;
	//std::cout << "\nEnter first letter ";
	//std::cin >> letter;
	//for (int i = 0; i < SIZE; i++)
	//{
	//	if (toupper(medicine[i].nameOfMed[0]) == toupper(letter)) {
	//		std::cout << "Name of med on your letter: " << medicine[i].nameOfMed << std::endl;
	//		haveItem = true;
	//	}
	//	std::cout << "Name " << medicine[i].nameOfMed << " price " << medicine[i].priceOfMed << " amount " << medicine[i].GetAmount() << std::endl;
	//}
	//if (haveItem == false)
		//std::cout << "We haven`t this medicine`s name!" << std::endl;

	//std::cout << "\nFunc general sum: " << price.getGeneralPrice(medicine, SIZE);
}

