#pragma once
#include <vector>
#include "Complex.h"

template <class T>
class Statistics {
	std::vector<T> values;
public:
	Statistics() = default;
	Statistics(std::initializer_list<T> values) : values(values) {};
	Statistics(const std::vector<T> & values) : values(values) {};
	T calculate_average();
	T max();
};

template <class T>
T Statistics<T>::calculate_average() {
	if (values.size() == 0) {
		return 0;
	}

	T sum = 0.0;

	for (const auto & value : values) {
		sum += value;
	}

	return sum / values.size();
}

template <>
Complex<double> Statistics<Complex<double>>::calculate_average() {
	if (values.size() == 0) {
		return Complex<double>{};
	}

	auto im_sum = 0.0;
	auto re_sum = 0.0;

	for (auto & value : values) {
		im_sum += value.getIm();
		re_sum += value.getRe();
	}

	const auto average_im = im_sum / values.size();
	const auto average_re = re_sum / values.size();

	return Complex<double>(average_im, average_re);
}

template <class T>
T Statistics<T>::max() {
	if (values.size() == 1) {
		return values.at(0);
	}

	T max = values.at(0);

	for (auto i = 0; i < values.size(); i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}

	return max;
}