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
		std::cout << yearOfCreated << "\n" << employeesAmount << "\n" << budget << "\n" << bookCirculation << "\n" << nameOfEdition << std::endl;
	}
	~PrintedEdition() { delete[] nameOfEdition; }
};

template <typename Value1, typename Value2>

Value2 getMaxValue(Value1 x, Value2 y, Value1 z) {
	if (x > y && x > z) return x;
	else if (y > x && y > z) return y;
	else if (z > x && z > y) return z;
}
