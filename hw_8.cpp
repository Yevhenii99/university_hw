#include <iostream>
#include <string>

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
	const short FIRE_RANGE = 330;
	const short DAMAGE = 120;
	constexpr static float CALIBER = 5.56;
	char* nameOfWeapon;
		
public:
	static int count;
	float priceOfWeapon = 12.5;

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
	static void Print() {
		std::cout << "Counter = " << counter << std::endl;
		//std::cout << "Price of weapon = " << priceOfWeapon << std::endl;//Error (static methods can work only with static types of data);
	}
	static int IncreaseCounter() {
		return counter + 5;
	}
	const short GetDamage() {
		return DAMAGE;
	}
	const short GetFireRange() {
		return FIRE_RANGE;
	}
	explicit Weapon(const short value):DAMAGE(value) {
		std::cout << "Ctor working! " << std::endl;
	}
	static void Print2() {
		std::cout << "Constexpr static var CALIBER: " << CALIBER << std::endl;
	}
	//----constant methods
	
	Weapon(const char* text) {
		nameOfWeapon = new char[strlen(text) + 1];
		strcpy(nameOfWeapon, text);
	}
	char* GetNameOfWeapon() {
		return nameOfWeapon;
	}
	//---default Ctor 
	Weapon() {
		counter++;
	}
	~Weapon() {
		delete[] nameOfWeapon;
		counter--;
	}
};

int Weapon::counter = 0;
int Weapon::count = 0;

int main(void) {
	//---Const variables
	short x;
	std::cout << "Enter value for speedOfBullet: ";
	std::cin >> x;
	const short speedOfBullet = x;
	//int array[speedOfBullet];//Error because var speedOfBullet calculate during program work but for array`s size need during compilation
	

	std::cout << "Increase counter value: " << Weapon::IncreaseCounter() << std::endl;//Example #1 call static method
	Weapon::Print();//Example #2 call static method

	std::cout << "Count: " << Weapon::count << std::endl; //I can read value from static var before any class created if it`s public field
	//std::cout << " Price of weapon: " << Weapon::priceOfWeapon << std::endl; //Error i can`t read value from priceOfWeapon if no object created
	Weapon svd(666);
	svd.SetAmount(17);
	svd.SetMass(7);
	std::cout << "Svd amount: " << svd.GetAmount() << " mass(kg): " << svd.GetMass() << std::endl;
	Weapon m_16(svd);
	m_16.SetMass(23);
	m_16.SetAmount(4);
	Weapon::Print2();//Print constexpr static var CALIBER
	std::cout << "M 16 amount: " << m_16.GetAmount() << " mass(kg) " << m_16.GetMass() << std::endl;
	Weapon ak_74;
	std::cout << "Counter: " << ak_74.Show() << std::endl;
	std::cout << "Call static method from object svd: " << svd.IncreaseCounter() << std::endl;//Example #3 call static method

	std::cout << "Enter name of weapon: ";
	const int SIZE = 20;
	char name[SIZE];
	std::cin.ignore();
	std::cin.getline(name, SIZE);

	Weapon browning(name);
	std::cout << "Name of weapon: " << browning.GetNameOfWeapon();

	//Work with const variables
	std::cout << "Value in const DAMAGE: " << svd.GetDamage() << std::endl;
	std::cout << "FireRange: " << svd.GetFireRange() << std::endl;
}