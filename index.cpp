#include <iostream>
#include <string>
#include <cmath>

std::string message(int (&numbers)[5]) {
	int sum = 0;

	for (int i = 0; i < 5; ++i) {
		sum += numbers[i];
	}

	std::string sumStr = std::to_string(sum);

	return "amount: " + sumStr;
}
