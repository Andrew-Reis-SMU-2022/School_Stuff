#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "search_functions.h"


std::vector<std::string> split_string(std::string input, char delimiter) {
	std::vector<std::string> output = {};
	std::size_t pos = 0;
	while (pos != std::string::npos) {
		pos = input.find(delimiter);
		output.push_back(input.substr(0, pos));
		input.erase(0, pos + 1);
	}
	return output;
}



int main() {
	std::ifstream fin("phoneBook.txt");

	if (!fin.is_open()) {
		std::cout << "File could not be opened.\n";
		//system("pause");
		return -1;
	}

	std::vector<std::string> phone_numbers = {};
	std::vector<std::string> names = {};

	while (true) {
		std::string temp;
		std::getline(fin, temp);
		if (fin.eof()) {
			break;
		}
		else {
			phone_numbers.push_back(split_string(temp, ',')[1]);
			names.push_back(split_string(temp, ',')[0]);
		}
	}
	
	//debugging
	for (int i = 0; i < names.size(); i++) {
		std::cout << names[i] << ", " << phone_numbers[i] << '\n';
	}
	std::cout << '\n';
	

	while (true) {
		std::cout << "Welcome to SMU's Phone Book\n\n";
		std::cout << "--------------------------------\n";
		std::cout << "(1) - Find By Name (recursive)\n";
		std::cout << "(2) - Find By Name (iterative)\n";
		std::cout << "(3) - Find By Phone (recersive)\n";
		std::cout << "(4) - Find By Phone (iterative)\n";
		std::cout << "(5) - Quit\n\n";
		std::cout << "Please Select an Option: ";
		int user_in;
		std::cin >> user_in;
		std::cin.ignore();
		std::string user_str;
		if (user_in == 5) {
			break;
		}
		else if (user_in == 1 || user_in == 2) {
			std::cout << "Enter a name: ";
			getline(std::cin, user_str);
		}
		else if (user_in == 3 || user_in == 4) {
			std::cout << "Enter a phone number: ";
			getline(std::cin, user_str);
		}
		else {
			std::cout << "Please make a valid selection...\n";
			continue;
		}

		std::cout << '\n';

		if (user_in == 1) {
			int index = searchRecursive(names, user_str);
			if (index == -1) {
				std::cout << "No results found\n";
			}
			else {
				std::cout << index + 1 << ". " << phone_numbers[index] << '\n';
			}
		}
		else if (user_in == 2) {
			int index = searchIterative(names, user_str);
			if (index == -1) {
				std::cout << "No results found\n";
			}
			else {
				std::cout << index + 1 << ". " << phone_numbers[index] << '\n';
			}
		}
		else if (user_in == 3) {
			int index = searchRecursive(phone_numbers, user_str);
			if (index == -1) {
				std::cout << "No results found\n";
			}
			else {
				std::cout << index + 1 << ". " << names[index] << '\n';
			}
		}
		else if (user_in == 4) {
			int index = searchIterative(phone_numbers, user_str);
			if (index == -1) {
				std::cout << "No results found\n";
			}
			else {
				std::cout << index + 1 << ". " << names[index] << '\n';
			}
		}
		std::cout << '\n';
	}
	//system("pause");
	return 0;
}
