#pragma once
#include <iostream>
#include <string>
#include <algorithm>

class Printery {
	std::vector<std::string> listOfEdition{"SkyBook", "NewMarketEdit", "MasMedia", "WorldWideInternational"};
	
public:
	Printery() = default;
	void getAddElem (const std::string& value) {
		return listOfEdition.emplace_back(value);
	}
	void getDeleteElem() {
		return listOfEdition.pop_back();
	}
	//---compare strings
	void compareStrings(const std::string& userInput) const {
		bool allMatch = true;
		std::string lowerInput = userInput;
		std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

		for (const std::string& str : listOfEdition) {
			std::string lowerStr = str;
			std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);

			if (lowerStr == lowerInput) {
				std::cout << "Finded string: " << userInput << std::endl;
				allMatch = true;
				break;
			}
			if (lowerStr != lowerInput) {
				allMatch = false;
			}
		}
		if (allMatch == false) {
			std::cout << "No string finded" << std::endl;
		}
	};
	std::vector<std::string> GetEdition() const {
		return listOfEdition;
	}
	void Print() const {
		for (const auto& item : listOfEdition) {
			std::cout << item << std::endl;
		}
	}
};


