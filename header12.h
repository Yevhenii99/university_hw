#pragma once
#include <iostream>

class Vehicle {
	int speed = 0; 
	unsigned char weelsAmount = 0;
	unsigned short length = 0;
	unsigned short width = 0;
	unsigned short height = 0;
	int movedDistance;
public:
	Vehicle() = default;
	Vehicle(int speed, unsigned char weels, unsigned short length) : speed(speed), weelsAmount(weels), length(length) {}
	virtual void Print() {
		std::cout << "Print from class vehicle\n";
	}
	virtual int getMovedDist(int speed, int time) {
		std::cout << "getMovedDist Vehicle work\n";
		movedDistance = speed * time;
		return movedDistance;
	}
	unsigned short GetWeelsAmount() {
		return weelsAmount;
	}
	virtual ~Vehicle() { std::cout << "Destr vehicle\n"; }
};

class Car : public Vehicle {
	char* color;
	using Vehicle::Vehicle;
	int movedDist;
public:
	Car() = default;
	int getMovedDist(int speed, int time) override {
		std::cout << "getMovedDist car work\n" << std::endl;
		movedDist = speed * time;
		return movedDist;
	}
	void Print() override {
		std::cout << "Print from class car" << std::endl;
		//std::cout << "Moved distance: " << movedDist << std::endl;
	}
	Car(const char* str) {
		color = _strdup(str);
		std::cout << "ctor car\n";
	}
	~Car() {
		std::cout << "Destr car\n";
		delete color;
	}
};

void ShowInfo(Vehicle& obj) {
	return obj.Print();
}
void ShowInfo(Vehicle* obj) {
	return obj->Print();
}
