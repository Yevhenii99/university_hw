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
	//---key word FINAL
	virtual void Print() /* -> final <- */ {
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
	//-> Method cannot be override if this method on base class have key word FINAL
	//void Print() override {
	//	std::cout << "Print from class car" << std::endl;
	//}
	void Print() override {
	std::cout << "Print from class car" << std::endl;
	}
	Car(const char* str) {
		color = _strdup(str);
		std::cout << "ctor car\n";
	}
	~Car() override {
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
//---abstract class
class Persone {
	char* name;
public:
	Persone(const char* name) {
		this->name = _strdup(name);
	}
	virtual float weightInLbs(float a) = 0;
	char* GetName() { return name; }
	virtual ~Persone() {
		delete[] name;
	}
};
class Women:public Persone
{
	const float COEF = 2.2f;
	char power;
public:
	Women(const char* name, char power) :Persone(name), power(power) {}
	float weightInLbs(float a) override { return a * COEF; }
	~Women() override {}
};
class Man:public Persone
{
	const float COEF = 2.2f;
	char power;
public:
	Man(const char* name, char power) :Persone(name), power(power) {}
	float weightInLbs(float a) override { return a * COEF; }
	~Man() override {}
};

