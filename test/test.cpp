#include "test.h"
#include "../index.h"
#include "termcolor.hpp"

#include <iostream>
#include <string>

using namespace std;

string boolString(bool value) {
	return value ? "true" : "false";
}

struct Option {
		string toBe;
		int numbers[5];
};

Option options[] = {
		{
				"amount: 15",
				{1, 2, 3, 4, 5}
		},
		{
				"amount: 10",
				{6, 1, 6, 2, -5}
		},
		{
				"amount: 24",
				{5, 6, 3, 9, 1}
		},
		{
				"amount: 20",
				{8, 2, 1, 5, 4}
		},
		{
				"amount: 19",
				{7, 5, 2, 1, 4}
		},
		{
				"amount: 22",
				{6, 3, 5, 1, 7}
		}
};

void printGreen(const string& test, const string& result) {
	cout << termcolor::green << "TEST " << test << " PASSED! RESULT: \"" << result << "\"" << endl;
}

void printRed(const string& test, const string& expected, const string& result) {
	cout << termcolor::red << "TEST " << test << " FAILED! EXPECTED: \"" << expected << "\" INSTEAD OF \"" << result << "\"!" << endl;
}

void test() {
	cout << endl;

	int optionsLength = sizeof(options) / sizeof(options[0]);

	for (int i = 0; i < optionsLength; i++) {
		Option option = options[i];

		std::string result = message(option.numbers);

		string testStr = "{";

		for (int j = 0; j < 5; j++) {
			if (j < 4) {
				testStr += to_string(option.numbers[j]) + ", ";
			} else {
				testStr += to_string(option.numbers[j]) += '}';
			}
		}

		if (result == option.toBe) {
			printGreen(testStr, result);
		} else {
			printRed(testStr, option.toBe, result);
		}

		cout << endl;
	}
}