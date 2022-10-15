#include <iostream>
#include <string>
#include <cmath>

std::string message(int (&numbers)[5]) {
	int sum = 0;

	for (int n: numbers) {
		sum += n;
	}

	return "amount: " + std::to_string(sum);
}
