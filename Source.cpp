#define NDEBUG
#include <iostream>
#include <algorithm>
#include <utility>
#include <cassert>
#include "ArrIntWrapper.h"

void g(ArrIntWrapper& arr) {
	std::cout << "Get reference" << std::endl;
}

void g(ArrIntWrapper&& arr) {
	std::cout << "Get r_value reference" << std::endl;
}

ArrIntWrapper f(size_t n) {
	ArrIntWrapper arr(n);
	return arr;
}


int main() {
	ArrIntWrapper arr1(5);
	std::cout << "arr1: " << arr1 << std::endl;

	//copy constructor
	ArrIntWrapper arr2(arr1);
	std::cout << "arr2: " << arr2 << std::endl;
	//copy assigment
	ArrIntWrapper arr3(3);
	std::cout << "arr3: " << arr3 << std::endl;
	arr3 = arr1;
	std::cout << "arr3: " << arr3 << std::endl;

	//get reference
	g(arr3);
	//get r_value reference
	g(f(4));

	std::cout<< std::endl;

	//Move assigment operator
	arr3 = f(7);
	std::cout << "arr3: " << arr3;

	std::cout << std::endl;

	ArrIntWrapper arr5 = f(7);
	std::cout << "arr5: " << arr5 << std::endl;
	ArrIntWrapper arr6(f(10));
	std::cout << "arr6: " << arr6 << std::endl;
	ArrIntWrapper arr7 = ArrIntWrapper(4);
	std::cout << "arr7: " << arr7 << std::endl;

	std::cout << std::endl;

	//move constructor
	std::cout << "arr1.data = " << arr1 << std::endl;

	ArrIntWrapper arr4 = std::move(arr1);

	std::cout << "arr4.data = " << arr4 << " " << "arr1.data = " << arr1 << std::endl;

	return 0;
}
