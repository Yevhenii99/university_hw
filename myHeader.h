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
	Book(const char* bookName, unsigned short pages) :pages(pages) {
		/*this->nameOfBook = new char[strlen(nameOfBook) + 1];*/
		/*strcpy(this->nameOfBook, nameOfBook);*/
		nameOfBook = strdup(bookName);
		std::cout << "Book name value: " << bookName << std::endl;
	}
	void ShowBook() {
		std::cout << "Name: " << nameOfBook << " Pages: " << pages << std::endl;
	}
	void SetAmountOfEd(unsigned short amount) {
		amountOfEddition = amount;
	}
	unsigned short GetAmountOfEd() { return amountOfEddition; }
	Book(char widthOfItem, char lengthOfItem, unsigned short pages):widthOfItem(widthOfItem), lengthOfItem(lengthOfItem), pages(pages) {
		nameOfBook = strdup("default name");
		
	}
	//cctor
	Book(const Book& object) :pages(object.pages), lengthOfItem(lengthOfItem), widthOfItem(widthOfItem) {
		//std::cout << "Cctor class Book!\n";
		//nameOfBook = new char[strlen(object.nameOfBook) + 1];
		nameOfBook = strdup(object.nameOfBook);
		//strcpy(nameOfBook, object.nameOfBook);

	}
	~Book() {
		delete[] nameOfBook;
		//std::cout << "Book destr work!\n";//Will be called second after Magazine destructor
	}
};
class Magazine :public Book
{
	float price = 0;
public:
	Magazine(float price, const char* nameOfBook, unsigned short pages) :Book(nameOfBook, pages), price(price) { std::cout << "Ctor param1 Magazine!\n"; }
	void Show() {
		std::cout << "Price: " << price << std::endl;
		ShowBook();
	}
	using Book::Book;//Inheritance of ctor
	//cctor
	Magazine(Book& object) :Book(object) { std::cout << "Cctor magazine!"; }
	~Magazine() { /*std::cout << "Magazine destr work\n"; */ }//Will be called first before Book destr
};