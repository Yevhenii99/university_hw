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
	unsigned int amountOfBullet;
	unsigned int massOfItem;
	unsigned int shotsPerMin;
	float reloadTimeSec;
	static int counter;

public:

	void SetAmount(unsigned int x) {
		this->amountOfBullet = x;
	}
	unsigned int GetAmount() {
		return amountOfBullet;
	}
	int Show() {
		return counter;
	}
	void SetMass(unsigned int mass) {
		massOfItem = mass;
	}
	unsigned int GetMass() {
		return massOfItem;
	}
	//---default Ctor 
	Weapon() {
		counter++;
	}
	~Weapon() {
		counter--;
	}
};

int Weapon::counter = 0;

int main(void) {

	Weapon svd;
	svd.SetAmount(17);
	svd.SetMass(7);
	std::cout << "Svd amount: " << svd.GetAmount() << " mass(kg): " << svd.GetMass() << std::endl;
	Weapon m_16(svd);
	m_16.SetMass(23);
	m_16.SetAmount(4);
	std::cout << "M 16 amount: " << m_16.GetAmount() << " mass(kg) " << m_16.GetMass() << std::endl;
	Weapon ak_74;
	std::cout << "Counter: " << ak_74.Show() << std::endl;
}