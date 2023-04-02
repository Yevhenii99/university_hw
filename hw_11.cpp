#include <iostream>

class Building
{
	unsigned short Height = 0;
	unsigned short Width = 0;
	unsigned short Lenght = 0;

public:

	Building(unsigned short x, unsigned short y, unsigned short z):Height(x), Width(y), Lenght(z) {}
	Building operator+(const Building& cottage)const {
		return Building(this->Height + cottage.Height, this->Width + cottage.Width, this->Lenght + cottage.Lenght);
	}
	Building operator+(int value)const {
		return Building(this->Height + value, this->Width + value, this->Lenght);
	}
	Building operator*(const Building& cottage)const {
		return Building(this->Height * cottage.Height, this->Width * cottage.Width, this->Lenght * cottage.Lenght);
	}

	Building& operator=(const Building& garage) {
		if (this == &garage) return *this;
		Height = garage.Height, Width = garage.Width, Lenght = garage.Lenght;
		return *this;
	}
	Building& operator++() {
		Height++;
		Width++;
		Lenght++;
		return *this;
	}
	Building operator++(int) {
		Building temp(Height, Width, Lenght);
		Height++;
		Width++;
		Lenght++;
		return temp;
	}
	unsigned short GetHeight() {
		return Height;
	}
	unsigned short GetLength() {
		return Lenght;
	}
	unsigned short GetWidth() {
		return Width;
	}
	friend Building operator+(int i, const Building& object);
	void Show() {
		std::cout << "Height: " << Height << " Width: " << Width << " Length: " << Lenght << std::endl;
	}
	Building() = default;
	~Building() {};
};

Building operator+(int i, const Building& object) {
	return Building(i + object.Height, i + object.Width, i + object.Lenght);
}
Building getFindObjectWithMinHeight(Building arrayOfObj[], const int SIZE) {
	Building objWithMinHeight;
	unsigned short k = arrayOfObj[0].GetHeight();
	std::cout << "First height value in first object is equal to: " << k << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (arrayOfObj[i].GetHeight() < k) {
			objWithMinHeight = arrayOfObj[i];
			k = arrayOfObj[i].GetHeight();
		}
	}
	return objWithMinHeight;
}
Building getFindObjectWithMaxLength(Building *arrayOfObj, const int SIZE) {
	Building objWithMaxLength;
	unsigned short seedLengthValue = arrayOfObj[0].GetLength();
	std::cout << "First length value in first object is equal to: " << seedLengthValue << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (arrayOfObj[i].GetLength() > seedLengthValue) {
			objWithMaxLength = arrayOfObj[i];
			seedLengthValue = arrayOfObj[i].GetLength();
		}
	}
	return objWithMaxLength;
}
Building getSum(Building* arrayOfObj, const int SIZE) {
	Building result;
	for (int i = 0; i < SIZE; i++)
	{
		result = result + arrayOfObj[i];
	}
	return result;
}
Building getMeanValue(Building* arrayOfObj, const int SIZE) {
	Building sum = getSum(arrayOfObj, SIZE);
	Building mean(sum.GetHeight() / SIZE, sum.GetWidth() / SIZE, sum.GetLength() / SIZE);
	return mean;
}
Building getFindObjectByInputValue(Building* arrayOfObj, const int SIZE, unsigned short inputLength) {
	Building defaultObject;
	bool flag = false;
	for (int i = 0; i < SIZE; i++)
	{
		if (arrayOfObj[i].GetLength() == inputLength) {
			return arrayOfObj[i];
			flag = true;
		}
	}
	if (flag == false) { 
		std::cout << "Sorry, we can`t find object with this length, try again!\n";
		return defaultObject; 
	}
	
}

int main(void) {
	Building cottage(5, 10, 15);
	Building cottage2(10, 15, 25);
	Building cottage3 = cottage + cottage2;
	//cottage3.Show();
	Building cottage4 = cottage3 * cottage;
	//cottage4.Show();
	Building cottage5 = cottage2 + 10;
	//cottage5.Show();
	Building garage2;
	Building garage(22, 33, 44);
	//garage.Show();
	garage2 = garage;
	//garage2.Show();
	garage2 = garage2;
	//garage2.Show();
	cottage3 = ++cottage;
	//cottage3.Show();
	cottage3 = cottage++;
	//cottage3.Show();
	//cottage.Show();
	cottage = 55 + cottage2;
	//cottage.Show();	
	const int SIZE = 3;
	Building cottages[SIZE] = {
		Building(5, 2, 3),
		Building(3, 15, 44),
		Building(2, 20, 33),
	};
	
	//Func find sum of all element in field in each object
	getSum(cottages, SIZE).Show();
	//Func return mean value from func getSum
	getMeanValue(cottages, SIZE).Show();

	//Find object by one parameters 
	unsigned short inputLength;
	std::cout << "Please enter value for length to find object: ";
	std::cin >> inputLength;
	getFindObjectByInputValue(cottages, SIZE, inputLength).Show();
		
}