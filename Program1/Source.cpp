#include <iostream>
#include <string>
#include <vector>
#include <cmath>

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

int binaryToDecimal(std::string binaryNum) {
	int decimalNum = 0;
	int power = 0;
	for (int i = binaryNum.length() - 1; i >= 0; i--) {
		if (binaryNum.at(i) == '1') {
			decimalNum += pow(2, power);
		}
		++power;
	}
	return decimalNum;
}

long long int stringToDecimal(std::string input) {
	int power = 0;
	long long int intNum = 0;
	for (int i = input.length() - 1; i >= 0; i--) {
		switch (input.at(i)) {
		case '1':
			intNum += 1 * pow(10, power);
			break;
		case '2':
			intNum += 2 * pow(10, power);
			break;
		case '3':
			intNum += 3 * pow(10, power);
			break;
		case '4':
			intNum += 4 * pow(10, power);
			break;
		case '5':
			intNum += 5 * pow(10, power);
			break;
		case '6':
			intNum += 6 * pow(10, power);
			break;
		case '7':
			intNum += 7 * pow(10, power);
			break;
		case '8':
			intNum += 8 * pow(10, power);
			break;
		case '9':
			intNum += 9 * pow(10, power);
			break;
		}
		power++;
	}
	return intNum;
}

std::string decimalToBinary(int decimalNum) {
	std::string binaryNum = "";
	bool startWriting = false;
	for (int power = 20; power >= 0; power--) {
		if (startWriting == false) {
			if (decimalNum >= static_cast<long long int>(pow(2, power))) {
				startWriting = true;
				binaryNum.append("1");
				decimalNum -= static_cast<long long int>(pow(2, power));
			}
		}
		else {
			if (decimalNum >= static_cast<long long int>(pow(2, power))) {
				binaryNum.append("1");
				decimalNum -= static_cast<long long int>(pow(2, power));
			}
			else {
				binaryNum.append("0");
			}
		}
	}
	return binaryNum;
}

long long int hexToDecimal(std::string hex) {
	long long int decimal = 0;
	int power = 0;
	for (int i = hex.length() - 1; i >= 0; i--) {
		switch (hex.at(i)) {
		case '1':
			decimal += 1 * pow(16, power);
			break;
		case '2':
			decimal += 2 * pow(16, power);
			break;
		case '3':
			decimal += 3 * pow(16, power);
			break;
		case '4':
			decimal += 4 * pow(16, power);
			break;
		case '5':
			decimal += 5 * pow(16, power);
			break;
		case '6':
			decimal += 6 * pow(16, power);
			break;
		case '7':
			decimal += 7 * pow(16, power);
			break;
		case '8':
			decimal += 8 * pow(16, power);
			break;
		case '9':
			decimal += 9 * pow(16, power);
			break;
		case 'A':
			decimal += 10 * pow(16, power);
			break;
		case 'B':
			decimal += 11 * pow(16, power);
			break;
		case 'C':
			decimal += 12 * pow(16, power);
			break;
		case 'D':
			decimal += 13 * pow(16, power);
			break;
		case 'E':
			decimal += 14 * pow(16, power);
			break;
		case 'F':
			decimal += 15 * pow(16, power);
			break;
		}
		power++;
	}
	return decimal;
}

std::string decimalToHex(long long int decimal) {
	std::vector<int> remainders = {};
	std::string hex = {};
	while (decimal % 16 != 0) {
		remainders.push_back(decimal % 16);
		decimal /= 16;
	}
	for (int i = remainders.size() - 1; i >= 0; i--) {
		switch (remainders[i]) {
		case 1:
			hex.append("1");
			break;
		case 2:
			hex.append("2");
			break;
		case 3:
			hex.append("3");
			break;
		case 4:
			hex.append("4");
			break;
		case 5:
			hex.append("5");
			break;
		case 6:
			hex.append("6");
			break;
		case 7:
			hex.append("7");
			break;
		case 8:
			hex.append("8");
			break;
		case 9:
			hex.append("9");
			break;
		case 10:
			hex.append("A");
			break;
		case 11:
			hex.append("B");
			break;
		case 12:
			hex.append("C");
			break;
		case 13:
			hex.append("D");
			break;
		case 14:
			hex.append("E");
			break;
		case 15:
			hex.append("F");
			break;
		}
	}
	return hex;
}

/*
std::string binaryToHex(std::string binary) {
	std::cout << binary;
	while (binary.length() % 4 != 0) {
		binary.insert(0, "0");
	}
	std::vector<std::string> binary_packets = {};
	while (binary.length() >= 4) {
		binary_packets.push_back(binary.substr(binary.length() - 4));
		binary.erase(binary.length() - 4);
	}
	std::string hex = "";
	for (int i = 0; i < binary_packets.size() ; i++) {
		if (binary_packets[i] == "0000") {
			hex.insert(0, "0");
		}
		else if (binary_packets[i] == "0001") {
			hex.insert(0, "1");
		}
		else if (binary_packets[i] == "0010") {
			hex.insert(0, "2");
		}
		else if (binary_packets[i] == "0011") {
			hex.insert(0, "3");
		}
		else if (binary_packets[i] == "0100") {
			hex.insert(0, "4");
		}
		else if (binary_packets[i] == "0101") {
			hex.insert(0, "5");
		}
		else if (binary_packets[i] == "0110") {
			hex.insert(0, "6");
		}
		else if (binary_packets[i] == "0111") {
			hex.insert(0, "7");
		}
		else if (binary_packets[i] == "1000") {
			hex.insert(0, "8");
		}
		else if (binary_packets[i] == "1001") {
			hex.insert(0, "9");
		}
		else if (binary_packets[i] == "1010") {
			hex.insert(0, "A");
		}
		else if (binary_packets[i] == "1011") {
			hex.insert(0, "B");
		}
		else if (binary_packets[i] == "1100") {
			hex.insert(0, "C");
		}
		else if (binary_packets[i] == "1101") {
			hex.insert(0, "D");
		}
		else if (binary_packets[i] == "1110") {
			hex.insert(0, "E");
		}
		else if (binary_packets[i] == "1111") {
			hex.insert(0, "F");
		}
	}
	return hex;
}
*/


int main() {
	std::string input;
	std::getline(std::cin, input);
	bool multiplication = false;
	bool addition = false;
	int num1;
	int num2;
	long long int output;

	if (input.find('+') != std::string::npos) {
		addition = true;
	}
	else {
		multiplication = true;
	}

	if (input.at(0) == 'B') {
		num1 = binaryToDecimal(split_string(input, ' ')[1]);
		num2 = binaryToDecimal(split_string(input, ' ')[3]);

		if (addition) {
			output = num1 + num2;
		}
		else {
			output = num1 * num2;
		}
		std::cout << decimalToBinary(output) << '\n';
	}
	else if (input.at(0) == 'D') {
		num1 = stringToDecimal(split_string(input, ' ')[1]);
		num2 = stringToDecimal(split_string(input, ' ')[3]);

		if (addition) {
			output = num1 + num2;
		}
		else {
			output = num1 * num2;
		}
		std::cout << output << '\n';
	}
	else if (input.at(0) == 'H') {
		num1 = hexToDecimal(split_string(input, ' ')[1]);
		num2 = hexToDecimal(split_string(input, ' ')[3]);
		
		if (addition) {
			output = num1 + num2;
		}
		else {
			output = num1 * num2;
		}
		std::cout << num1 << ' ' << num2 << '\n';
		std::cout << output << '\n';
		std::cout << decimalToHex(output) << '\n';
	}

	system("pause");
}