#include <iostream>
#pragma once
class Book
{
	char widthOfItem;
	char lengthOfItem;
	unsigned short pages;
	char* nameOfBook;
protected:
	unsigned short amountOfEddition;
public:
	Book() { std::cout << "Ctor default Book!\n"; }
	Book(char width, char length, const char* name) :pages(200) {
		this->nameOfBook = new char[strlen(name) + 1];
		strcpy(nameOfBook, name);
	}
	Book(const char* nameOfBook, unsigned short pages) :pages(pages) {
		this->nameOfBook = new char[strlen(nameOfBook) + 1];

		strcpy(this->nameOfBook, nameOfBook);
	}
	void ShowBook() {
		std::cout << "Name: " << nameOfBook << " Pages: " << pages << std::endl;
	}
	void SetAmountOfEd(unsigned short amount) {
		amountOfEddition = amount;
	}
	unsigned short GetAmountOfEd() { return amountOfEddition; }
	Book(const Book& value):pages(value.pages), amountOfEddition(value.amountOfEddition), lengthOfItem(value.lengthOfItem), widthOfItem(value.widthOfItem) {
		nameOfBook = new char[strlen(nameOfBook) + 1];
		this->nameOfBook = nameOfBook;
	}
	~Book() {
		delete[] nameOfBook;
		std::cout << "Book destr work!\n";//Will be called second after Magazine destructor
	}
};
class Magazine :public Book
{
	float price;
public:
	Magazine(float price, const char* nameOfBook, unsigned short pages) :Book(nameOfBook, pages), price(price) { std::cout << "Ctor param1 Magazine!\n"; }
	void Show() {
		std::cout << "Price: " << price << std::endl;
		Book::ShowBook();
	}
	using Book::Book;//Inheritance of ctor
	Magazine() :price(15.6) { std::cout << "Ctor default Magazine!\n"; }
	Magazine(const Magazine& object):price(66.6), Book(object) {}
	~Magazine() { std::cout << "Magazine destr work\n"; }//Will be called first before Book destr
};