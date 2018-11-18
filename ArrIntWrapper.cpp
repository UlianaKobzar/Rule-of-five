#define NDEBUG
#include "ArrIntWrapper.h"
#include <iostream>
#include <algorithm>
#include <utility>
#include <cassert>
#include <iterator>

ArrIntWrapper::ArrIntWrapper(size_t n_) : size(n_), data(new int[size]) {
	std::fill(data, data + size, 0);
}

ArrIntWrapper::ArrIntWrapper(ArrIntWrapper const& new_array) : size(new_array.size), data(new int[new_array.size]) {
	std::copy_n(new_array.data, size, data);
	std::cout << "Copy constructor finished work" << std::endl;
}

ArrIntWrapper::ArrIntWrapper(ArrIntWrapper&& new_array) : size(new_array.size), data(new_array.data) {
	new_array.data = nullptr;
	new_array.size = 0;
	std::cout << "Move constructor finished work" << std::endl;
}

ArrIntWrapper& ArrIntWrapper::operator = (ArrIntWrapper const& right) {
	if (&right == this) {
		return *this;
	}

	size = right.size;
	data = new int[size];
	std::copy_n(right.data, size, data);

	std::cout << "Copy assigment operator finished work" << std::endl;
	return *this;
}

ArrIntWrapper& ArrIntWrapper::operator= (ArrIntWrapper&& right) {
	assert(&right == this);

	size = right.size;
	data = right.data;

	right.data = nullptr;
	right.size = 0;

	std::cout << "Move assigment operator finished work" << std::endl;
	return *this;
}

ArrIntWrapper::~ArrIntWrapper() {
		//optional		std::cout << __func__ << std::endl;
	}

std::ostream& operator<<(std::ostream& os, const ArrIntWrapper& arr) {
	//std::for_each(arr.data, arr.data + arr.size, [&os](int x) {os << x << " "; });
	//os << std::endl;

	//using ostream operator
	std::ostream_iterator<int> out_it(os, " ");
	std::copy_n(arr.data, arr.size, out_it);

	return os;
}
