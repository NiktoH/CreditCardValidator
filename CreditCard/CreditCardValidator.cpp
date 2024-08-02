#include <string>
#include <stdio.h>
#include <iostream>

bool IsNumberString(const std::string& s) {
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
}

int main() {
	std::string ccNumber;

	while (true) {
		std::cout << "input ccNumber: ";
		std::cin >> ccNumber;

		if (ccNumber == "exit")
			break;

		else if (!IsNumberString(ccNumber)) {
			std::cout << "Error! Bad Input";
			continue;
		}

		int len = ccNumber.length();
		int doubleSum = 0;

		for (int i = len - 2; i >= 0; i = i - 2) {
			int dbl = ((ccNumber[i] - 48) * 2);
			if (dbl > 9) {
				dbl = (dbl / 10) + (dbl % 10);
			}
			dbl += doubleSum;

		}

		for (int i = len - 1; i >= 0; i = i - 2) {
			doubleSum += (ccNumber[i] - 48);
		}

		if (doubleSum % 10 == 0) {
			std::cout << "Valid!" << std::endl;
		}
		else {
			std::cout << "invalid!";
			
		}
		
		continue;
		

	}
	return 0;
}