#include <iostream>
#include <iomanip>
#include "sequence.hpp"

template<typename T>
std::pair<T, int> find_epsilon() {
	T epsilon = 1;
	int mantissa = 0;
	while(!(1 + epsilon / 2 == 1 && 1 + epsilon != 1)) {
		epsilon /= 2;
		mantissa++;
	}
	return {epsilon, mantissa};
}

template<typename T>
void compare(T epsilon) {
	std::cout << "1 < 1 + epsilon/2 is " << std::boolalpha << (1 < 1 + epsilon / 2) << std::endl;
	std::cout << "1 < 1 + epsilon is " << std::boolalpha << (1 < 1 + epsilon) << std::endl;
	std::cout << "1 < 1 + epsilon + epsilon/2 is " << std::boolalpha << (1 < 1 + epsilon / 2 + epsilon) << std::endl;
	std::cout << "1 + epsilon/2 < 1 + epsilon is " << std::boolalpha << (1 + epsilon / 2 < 1 + epsilon) << std::endl;
	std::cout << "1 + epsilon/2 < 1 + epsilon + epsilon/2 is " << std::boolalpha << (1 + epsilon / 2 < 1 + epsilon / 2 + epsilon) << std::endl;
	std::cout << "1 + epsilon < 1 + epsilon + epsilon/2 is " << std::boolalpha << (1 + epsilon < (1 + epsilon) + epsilon / 2) << std::endl;
}

template<typename T>
T min_degree() {
	T a = 1;
	int pow = 0;
	while(a != a/10){
		a /= 10;
		pow--;
	}
	return pow;
}

template<typename T>
T max_degree() {
	T a = 1;
	for(int i = 0;; ++i) {
		a *= 10;
		if(a == a * 10) {
			return i;
		}
	}
}

int main() {
	std::cout << find_epsilon<float>().first << " float epsilon" << std::endl;
	std::cout << find_epsilon<double>().first << " double epsilon" << std::endl;
	std::cout << find_epsilon<float>().second << " float mantissa" << std::endl;
	std::cout << find_epsilon<double>().second << " double mantissa" << std::endl;
	std::cout << "float" << std::endl;
	compare<float>(find_epsilon<float>().first);
	std::cout << "double" << std::endl;
	compare<double>(find_epsilon<double>().first);
	std::cout << "float min: " << min_degree<float>() << std::endl;
	std::cout << "double min: " << min_degree<double>() << std::endl;
	std::cout << "float max: " << max_degree<float>() << std::endl;
	std::cout << "double max: " << max_degree<double>() << std::endl;
	std::cout << "float no pow: " << std::setprecision(23) << count_sequence_no_pow<float, 10000>() << std::endl;
	std::cout << "double no pow: " << std::setprecision(52) << count_sequence_no_pow<double, 10000>() << std::endl;
	std::cout << "float no pow reversed: " << std::setprecision(23) << count_sequence_no_pow_reversed<float, 10000>() << std::endl;
	std::cout << "double no pow reversed: " << std::setprecision(52) << count_sequence_no_pow_reversed<double, 10000>() << std::endl;
	std::cout << "float with pow: " << std::setprecision(23) << count_sequence_pow<float, 10000>() << std::endl;
	std::cout << "double with pow: " << std::setprecision(52) << count_sequence_pow<double, 10000>() << std::endl;
	std::cout << "float with pow reversed: " << std::setprecision(23) << count_sequence_pow_reversed<float, 10000>() << std::endl;
	std::cout << "double with pow reversed: " << std::setprecision(52) << count_sequence_pow_reversed<double, 10000>() << std::endl;
	std::cout << "float no pow separate: " << std::setprecision(23) << count_sequence_no_pow_separate<float, 10000>() << std::endl;
	std::cout << "double no pow separate: " << std::setprecision(52) << count_sequence_no_pow_separate<double, 10000>() << std::endl;
	std::cout << "float no pow reversed separate: " << std::setprecision(23) << count_sequence_no_pow_reversed_separate<float, 10000>() << std::endl;
	std::cout << "double no pow reversed separate: " << std::setprecision(52) << count_sequence_no_pow_reversed_separate<double, 10000>() << std::endl;
}


