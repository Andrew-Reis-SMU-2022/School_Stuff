#include <vector>
#include <string>


int searchIterative(std::vector<std::string> &data, std::string query) {
	for (int i = 0; i < data.size(); i++) {
		if (data[i] == query) {
			return i;
		}
	}
	return -1;
}

int imOnlyDoingThisSoIDontGetFined(std::vector<std::string> &data, std::string query, int index) {
	if (data[index] == query) {
		return index;
	}
	else if (index == data.size() - 1) {
		return -1;
	}
	else {
		return imOnlyDoingThisSoIDontGetFined(data, query, index + 1);
	}
}

int searchRecursive(std::vector<std::string> &data, std::string query) {
	return imOnlyDoingThisSoIDontGetFined(data, query, 0);
}
