#include <iostream>
#include <string>

//Варіант 6:
//Об'єкти – ліки в аптеці. Поля (атрибути):
//Назва лік
//Кількість
//Ціна
//Підрахувати сумарну ціну лік.Організувати пошук в масиві об‘єкту з  вказаною назвою ліків.

class Medicine {
	unsigned short amountOfMed;//by default it is privat field
public:
	char nameOfMed[20];
	float priceOfMed;
	float generalPrice = 0;

	void SetAmount(unsigned short amountOfMed) {
		this->amountOfMed = amountOfMed;
	}
	int GetAmount() {
		return amountOfMed;
	}
	float getGeneralPrice(Medicine medicine[], const int size) {
		for (int i = 0; i < size; i++)
		{
			generalPrice += medicine[i].priceOfMed * medicine[i].GetAmount();
		}
		return generalPrice;
	}
};
int main(void) {

	const int SIZE = 4;
	Medicine medicine[SIZE];
	Medicine price;


	for (int i = 0; i < SIZE; i++)
	{
		unsigned int amount;
		std::cout << "\nEnter the price: ";
		std::cin >> medicine[i].priceOfMed;
		std::cout << "\nEnter the name: ";
		std::cin >> medicine[i].nameOfMed;
		std::cout << "\nEnter amount of med: ";
		std::cin >> amount;
		medicine[i].SetAmount(amount);
		
	}
	//float generalPrice = 0;
	char letter;
	bool haveItem = false;
	std::cout << "\nEnter first letter ";
	std::cin >> letter;
	for (int i = 0; i < SIZE; i++)
	{
		if (toupper(medicine[i].nameOfMed[0]) == toupper(letter)) {
			std::cout << "Name of med on your letter: " << medicine[i].nameOfMed << std::endl;
			haveItem = true;
		} 

		//generalPrice += medicine[i].priceOfMed * medicine[i].GetAmount();
		std::cout << "Name " << medicine[i].nameOfMed << " price " << medicine[i].priceOfMed << " amount " << medicine[i].GetAmount() << std::endl;
	}
	if (haveItem == false)
		std::cout << "We haven`t this medicine`s name!" << std::endl;
	//std::cout << "\nGeneral price: " << generalPrice << std::endl;

	std::cout << "\nFunc general sum: " << price.getGeneralPrice(medicine, SIZE);
}


//float getGeneralPrice(Medicine* arr, const int size) {
//	float generalSum = 0;
//	for (int i = 0; i < size; i++)
//	{
//		generalSum += (arr[i].priceOfMed * arr[i].GetAmount());
//	}
//	return generalSum;
//}

