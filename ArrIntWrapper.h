#pragma once
#include <iostream>
#include <algorithm>

class ArrIntWrapper
{
private:
	size_t size = 0;
	int* data;
public:
	ArrIntWrapper() {}
	ArrIntWrapper(size_t n_);
	ArrIntWrapper(ArrIntWrapper const& new_array);
	ArrIntWrapper(ArrIntWrapper&& new_array);
	ArrIntWrapper& operator = (ArrIntWrapper const& right);
	ArrIntWrapper& operator= (ArrIntWrapper&& right);
	~ArrIntWrapper();
	friend std::ostream& operator<<(std::ostream& os, const ArrIntWrapper& arr);
};
