#include <iostream>

class Building
{
	unsigned short Height;
	unsigned short Width;
	unsigned short Lenght;

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
	friend Building operator+(int i, const Building& object);
	void Show() {
		std::cout << "Height: " << Height << " Width: " << Width << " Length: " << Lenght << std::endl;
	}

	Building() {};
	~Building() {};
};

Building operator+(int i, const Building& object) {
	return Building(i + object.Height, i + object.Width, i + object.Lenght);
}

int main(void) {
	Building cottage(5, 10, 15);
	Building cottage2(10, 15, 25);
	Building cottage3 = cottage + cottage2;
	cottage3.Show();
	Building cottage4 = cottage3 * cottage;
	cottage4.Show();
	Building cottage5 = cottage2 + 10;
	cottage5.Show();
	Building garage2;
	Building garage(22, 33, 44);
	garage.Show();
	garage2 = garage;
	garage2.Show();
	garage2 = garage2;
	garage2.Show();
	//cottage3 = cottage++;
	cottage3 = ++cottage;
	cottage3.Show();
	cottage3 = cottage++;
	cottage3.Show();
	cottage.Show();
	cottage = 55 + cottage2;
	cottage.Show();
}