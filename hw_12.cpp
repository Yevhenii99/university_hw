#include "header12.h"
#include <iostream>

int main(void) {
	Vehicle* ptrValue[] = { new Vehicle(120, 4, 10), new Vehicle(80, 4, 9), new Car(133, 4, 13) };
	for (int i = 0; i < 3; i++)
	{
		std::cout << ptrValue[i]->getMovedDist(10, 20) << std::endl;
		ptrValue[i]->Print();
		delete ptrValue[i];
	}
	Vehicle bus(20, 4, 12);
	ShowInfo(bus);
	ShowInfo(&bus);
	Car volvo(35, 4, 5);
	ShowInfo(volvo);
	ShowInfo(&volvo);
	Vehicle vehicle;
	Car car;
	car.getMovedDist(25, 10);
	car.Print();

	//--->Abstract class
	//Persone a("Victor"); Error (can`t create object from abstract class Persone)
	Women women("Alla", 60);
	std::cout << women.GetName() << std::endl;
	std::cout << women.weightInLbs(50) << std::endl;
	Man man("Yevhenii", 90);
	std::cout << man.GetName() << std::endl;
	std::cout << man.weightInLbs(75) << std::endl;
	Persone* ptrPersone[] = {new Women("Alisa", 55), new Man("Omar", 100), new Women("Julia", 63), new Man("Vladislav", 96)};
	for (unsigned short i = 0; i < 4; i++) {
		std::cout << ptrPersone[i]->GetName() << std::endl;
		delete ptrPersone[i];
	}
}