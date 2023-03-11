#include <iostream>
#include <iomanip>
#include <string>

//Задача:   Модифікувати код програми із попередньої лабораторної роботи наступним чином :
//1.    Додати  конструктор копіювання.
//2.    Додати  конструктор перетворення з та без використання ключового слова explicit.
//3.    Оголосити глобальну функцію, яка в якості параметра приймає об‘єкт Вашого класу.Продемонструвати різницю передачі в функцію в якості параметра об‘єкту класу за значенням та за посиланням.
//4.    (Сучасний С++).Продемонструвати використання
//4.1.ключових слів : default та delete.
//5.    Використати в функції main всі оголошені в класі конструктори та викликати глобальну функцію.Особливу увагу приділити демонстрації мінімум 3трьох різних варіантів коду, при використанні яких викликається конструктор копіювання.


class Medicine {
	unsigned short amountOfMed;//by default it is privat field
public:
	char* nameOfMed;
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
	//-----Initialization
	Medicine():priceOfMed(33.3), amountOfMed(23) {
		std::cout << "First constructor work." << std::endl;
		//priceOfMed = 25.4; 
		std::cout << priceOfMed << std::setw(10) << GetAmount() << std::endl;
	}
	//just for instance i create constr with one float param
	explicit Medicine(float value):priceOfMed(value), amountOfMed(value) {}


	Medicine(const char* name) {
		std::cout << "Second constr work." << std::endl;
		nameOfMed = new char[strlen(name) + 1];
		strcpy(nameOfMed, name);
		std::cout << nameOfMed << std::endl;
	}
	Medicine(unsigned short& amount, float& price) {
		std::cout << "Third constr work." << std::endl;
		SetAmount(amount);
		priceOfMed = price;
		std::cout << GetAmount() << std::setw(10) << priceOfMed << std::endl;
	}
	//-----Delegation of constructor
	Medicine(unsigned short* amount, const char* name, float* price):Medicine(*amount, *price) {
		//SetAmount(*amount);
		nameOfMed = new char[strlen(name) + 1];
		strcpy(nameOfMed, name);
		std::cout << nameOfMed << std::endl;
		std::cout << "address of object: " << this << std::endl;
		//priceOfMed = *price;
		//std::cout << GetAmount() << std::setw(20) << nameOfMed << std::setw(20) << priceOfMed << std::endl;
	}
	//-----copy constr
	Medicine(const Medicine &other) {
		this->priceOfMed = other.priceOfMed;
		this->amountOfMed = other.amountOfMed;
		this->nameOfMed = new char[strlen(other.nameOfMed) + 1];
		for (int i = 0; i <= strlen(other.nameOfMed); i++) {
			this->nameOfMed[i] = other.nameOfMed[i];
		}
		std::cout << "Working CCtor!" << this << std::endl;
	}
	void Show() {
		std::cout << "PriceOfMed : " << this->priceOfMed << " " << this->amountOfMed << std::endl;
	}

	~Medicine() {
		delete[] nameOfMed;
		std::cout << "Destructor!" << this << std::endl;
	}

};

//----Functions: pass object by value and by reference 

//void FOO(Medicine object) {
//	std::cout << "Working FOO " << &object << std::endl;//If i pass by value it`s just copy the object so constructor and desctructor will be call
//}
//void FOO_2(Medicine& object) {
//	std::cout << "Working FOO_2 " << &object << std::endl;//If i pass by reference constructor and desctuctor won`t be call
//}

int main(void) {
	char name[] = "Strepsils";
	unsigned short amount = 33;
	float price = 14.5;

	//Medicine a;//call constuctor without any parameters or with default parmtrs
	//Medicine b(name);//call constr with one par
	//Medicine c(amount, price);//call constr with two par
	//Medicine d(&amount, name, &price);//cal constr with three par

	//----copy delegation into newObj
	Medicine delegation(&amount, name, &price);
	Medicine newObj(delegation);
	std::cout << "Name in newObj: " << newObj.nameOfMed << std::endl;
	//std::cout << "New object was copy: " << newObj.GetAmount() << std::setw(15) << newObj.priceOfMed << std::setw(15) << newObj.nameOfMed << std::endl;

	//----call obj with one param it`s gonna call the constructor of changing 
	
	//Medicine changingObject = 156.7; //Here will be create an object from this number
	//If i add EXPLICIT before constr it`s will be error
	//changingObject.Show();//show value 156.7 if i don`t add EXPLICIT before constructor
	//When i add EXPLICIT now i can pass the argument like this
	Medicine changingObject(246.7);
	changingObject.Show();

	FOO(delegation);//Pass by value 



	//----Pointer to object
	//Medicine* pDelegation;
	//pDelegation = new Medicine;
	//pDelegation->priceOfMed = 14.6;
	//pDelegation->SetAmount(100);
	//std::cout << "Price: " << delegation.priceOfMed << std::setw(15) << " amount: " << pDelegation->GetAmount() << std::endl;
	//delete pDelegation;
}