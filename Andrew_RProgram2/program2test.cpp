#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
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
		system("pause");
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

	//searchRecursive
	assert(searchRecursive(names, names[0]) == 0);
	assert(searchRecursive(names, names[1]) == 1);
	assert(searchRecursive(names, names[2]) == 2);
	assert(searchRecursive(phone_numbers, phone_numbers[0]) == 0);
	assert(searchRecursive(phone_numbers, phone_numbers[1]) == 1);
	assert(searchRecursive(phone_numbers, "8670309") == -1);

	//searchIterative
	assert(searchIterative(names, names[3]) == 3);
	assert(searchIterative(names, names[4]) == 4);
	assert(searchIterative(phone_numbers, phone_numbers[2]) == 2);
	assert(searchIterative(phone_numbers, phone_numbers[3]) == 3);
	assert(searchIterative(phone_numbers, phone_numbers[4]) == 4);
	assert(searchIterative(phone_numbers, "8670309") == -1);
	
	std::cout << "Success\n";

	//system("pause");
	return 0;
}