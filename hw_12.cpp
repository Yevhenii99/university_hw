#include "header12.h"
#include <iostream>

int main(void) {
	Vehicle* ptrValue[] = { new Vehicle(120, 4, 10), new Vehicle(80, 4, 9), new Car(133, 4, 13) };
	for (int i = 0; i < 3; i++)
	{
		ptrValue[i]->getMovedDist(10, 20);
		ptrValue[i]->Print();
	}
	Vehicle bus(20, 4, 12);
	ShowInfo(bus);
	ShowInfo(&bus);
	Car volvo(35, 4, 5);
	ShowInfo(volvo);
	ShowInfo(volvo);
	Vehicle vehicle;
	Car car;
	car.getMovedDist(25, 10);
	car.Print();

}