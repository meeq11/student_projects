#include <iostream>
#include <string>

string fizzBuzz(int num) {
		if (num % 3 == 0 && num % 5 == 0) {
			return "FizzBuzz";
		} else if (num % 3 == 0 ) {
			return "Fizz";
		} else if (num & 5 == 0 ) {
			return "Buzz";
		} else {
			return to_string(num);
		}
	}

	



#TODO: tu umieść swoją funkcję
