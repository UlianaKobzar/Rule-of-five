#include <iostream>
#include <algorithm>
#include <utility>

class Arr_int_wrapper
{
public:
	size_t n = 0;
	int* data;

	Arr_int_wrapper(){}

	Arr_int_wrapper(size_t n_) : n(n_), data(new int[n]){
		int i = 0;
		std::for_each(data, data + n, [&i](int x) {x = i; i++; });
	}

	Arr_int_wrapper(Arr_int_wrapper const& new_array) : n(new_array.n), data(new int[new_array.n]) {
		std::copy_n(data, n, new_array.data);
		std::cout << "Copy constructor finished work" << std::endl;
	}

	Arr_int_wrapper(Arr_int_wrapper && new_array) : n(new_array.n), data(new_array.data) {
		new_array.data = nullptr;
		new_array.n = 0;
		std::cout << "Move constructor finished work" << std::endl;
	}

	Arr_int_wrapper& operator = (Arr_int_wrapper const& right) {
		if (&right == this) {
			return *this;
		}

		n = right.n;
		data = new int[n];
		std::copy_n(data, n, right.data);

		std::cout << "Copy assigment operator finished work" << std::endl;
		return *this;
	}

	Arr_int_wrapper& operator = (Arr_int_wrapper && right) {
		if (&right == this) {
			return *this;
		}

		n = right.n;
		data = right.data;

		right.data = nullptr;
		right.n = 0;

		std::cout << "Move assigment operator finished work" << std::endl;
		return *this;
	}



	~Arr_int_wrapper() {
//optional		std::cout << __func__ << std::endl;
	}
};

void g(Arr_int_wrapper &arr) {
	std::cout << "Get reference" << std::endl;
}

void g(Arr_int_wrapper &&arr) {
	std::cout << "Get r_value reference" << std::endl;
}

Arr_int_wrapper f(size_t n) {
	Arr_int_wrapper arr(n);
	return arr;
}


int main() {
	Arr_int_wrapper arr1(5);

	//copy constructor
	Arr_int_wrapper arr2(arr1);
	//copy assigment
	Arr_int_wrapper arr3(3);
	arr3 = arr1;

	//get reference
	g(arr3);
	//get r_value reference
	g(f(4));

	//Move assigment operator
	arr3 = f(7);

	//move constructor
	std::cout << "arr1.data = " << arr1.data << std::endl;

	Arr_int_wrapper arr4 = std::move(arr1);

	std::cout << "arr4.data = " << arr4.data << " " << "arr1.data = " << arr1.data << std::endl;

	return 0;
}