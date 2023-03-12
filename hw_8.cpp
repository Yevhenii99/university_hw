#include <iostream>


//Задача:   Виконати лабораторну роботу наступним чином :
//Оголосити в проекті власний клас(назву класу та поля обрати за власним розсудом);
//Продемонструвати в коді роботу із статичними змінними : їх ініціалізацію та використання
//Продемонструвати обмеження на статичні методи та виклик статичних методів
//Продемонструвати в коді  способи ініціалізації константних змінних
//Продемонструвати обмеження на константні методи та різницю між константами часу виконання та константами часу компіляції.
//Створити константний об‘єкт класу та продемонструвати в коді можливості та обмеження при / на  використанні таких об‘єктів.

class Weapon
{
	unsigned int* pamountOfBullet;
	unsigned int massOfItem;
	unsigned int shotsPerMin;
	float reloadTimeSec;
	static int counter;

public:

	void SetAmount(unsigned int* x) {
		this->pamountOfBullet = x;
		counter++;
	}
	unsigned int* GetAmount() {
		return pamountOfBullet;
	}
	int Show() {
		return counter;
	}
	void SetMass(unsigned int mass) {
		massOfItem = mass;
		counter++;
	}
	unsigned int GetMass() {
		return massOfItem;
	}
};

int Weapon::counter = 0;

int main(void) {
	unsigned int amount;

	Weapon svd;
	std::cout << "Set amount for svd: " << std::endl;
	std::cin >> amount;
	svd.SetAmount(&amount);
	unsigned int amountSVD = *(svd.GetAmount());
	svd.SetMass(7);
	std::cout << "counter of all Get Methods : " << svd.Show() << std::endl;
}