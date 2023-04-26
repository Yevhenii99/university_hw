#pragma once
#include <iostream>

template <typename T1, typename T2, typename T3, typename T4, typename T5>
class PrintedEdition {
	T1 yearOfCreated;
	T2 employeesAmount;
	T3 budget;
	T4 bookCirculation;
	T5 nameOfEdition;
public:
	PrintedEdition(T1 year, T2 employees, T3 budget, T4 bookCirc, T5 name) : yearOfCreated(year), employeesAmount(employees), budget(budget), bookCirculation(bookCirc) {
		nameOfEdition = _strdup(name);
	}
	void Show() {
		std::cout << yearOfCreated << " " << employeesAmount << " " << budget << " " << bookCirculation << " " << nameOfEdition << std::endl;
	}
	~PrintedEdition() { delete[] nameOfEdition; }
};

//Task2
template <typename Value1, typename Value2 = float>

Value2 getMaxValue(Value1 x, Value2 y, Value1 z) {
	if (x > y && x > z) return x;
	else if (y > x && y > z) return y;
	else if (z > x && z > y) return z;
}
//Task3
template <typename Value1, typename Value2>

Value1 getSumOfNums(Value2 x, Value2 y) {
	return x + y;
}
//Task4
template <typename T1> 

T1 getSumOfElements(T1* arr, int row, int col) {
	T1 sum = 0;
	for (short i = 0; i < row; ++i)
	{
		for (short j = 0; j < col; ++j) {
			sum += *(arr + i*col + j);
		}
	}
	return sum;
}

//Task5

template <typename T1 = int, typename T2 = double>
class Circle {
	T1 r = 0;
	const T2 P = 3.14;
public:
	Circle(T1 radius) :r(radius) {};
	T2 getLengthOfCircle() {
		return 2 * P * r;
	}
};