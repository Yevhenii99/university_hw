#include <iostream>
#pragma warning(disable : 4996)
#include "myHeader.h"


int main(void) {
	Magazine news(76.3, "VoiceOfAmerika", 132);
	//Magazine news2;//Will be called default ctor in base class and after in derivative class 
	Magazine news3(13, 67, "RealNews");//Will be called ctor from inheritance
	Magazine obj("SOmething", 255);
	//news.Show();
	//news3.Show();
	//news.SetAmountOfEd(1050);
	//Magazine news4(44, 55, 666);
	//Magazine news5(news4);
	//news4.Show();
	//news5.Show();
	//std::cout << "Amount of eddition: " << news.GetAmountOfEd() <<  std::endl;
	//news.ShowBook();//If i define access to class Book like privat or protected i won`t be able to use methods from Book anywhere
}
