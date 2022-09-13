#ifndef TASK1_SEQUENCE_HPP
#define TASK1_SEQUENCE_HPP

template<typename T, size_t N>
T count_sequence_no_pow() {
	T sum = 0;
	for(int i = 1; i <= N; i++) {
		T sign = i % 2 == 0 ? 1 : -1;
		sum += sign / static_cast<T>(i);
	}
	return sum;
}

template<typename T, size_t N>
T count_sequence_no_pow_reversed() {
	T sum = 0;
	for(int i = N; i > 0; i--) {
		T sign = i % 2 == 0 ? 1 : -1;
		sum += sign / static_cast<T>(i);
	}
	return sum;
}

template<typename T, size_t N>
T count_sequence_pow() {
	T sum = 0;
	for(int i = 1; i <= N; i++) {
		sum += pow(-1., i) / static_cast<T>(i);
	}
	return sum;
}

template<typename T, size_t N>
T count_sequence_pow_reversed() {
	T sum = 0;
	for(int i = N; i > 0; i--) {
		sum += pow(-1., i) / static_cast<T>(i);
	}
	return sum;
}

template<typename T, size_t N>
T count_sequence_no_pow_separate() {
	T sum_positive = 0;
	T sum_negative = 0;
	for(int i = 1; i <= N; i++) {
		T sign = i % 2 == 0 ? 1 : -1;
		if(sign > 0) {
			sum_positive += sign / static_cast<T>(i);
		} else { sum_negative += sign / static_cast<T>(i); }
	}
	return sum_positive + sum_negative;
}

template<typename T, size_t N>
T count_sequence_no_pow_reversed_separate() {
	T sum_positive = 0;
	T sum_negative = 0;
	for(int i = N; i > 0; i--) {
		T sign = i % 2 == 0 ? 1 : -1;
		if(sign > 0) {
			sum_positive += sign / static_cast<T>(i);
		} else { sum_negative += sign / static_cast<T>(i); }
	}
	return sum_positive + sum_negative;
}

#endif //TASK1_SEQUENCE_HPP
