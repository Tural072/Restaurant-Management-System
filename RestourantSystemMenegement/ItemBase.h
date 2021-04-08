#pragma once
#include "Exception.h"
using namespace Exception;

class ItemBase {
	int count;
public:
	ItemBase() :count(0) {}
	ItemBase(const int count)
	{
		setCount(count);
	}
	int getCount()const {
		return count;
	}
	void setCount(const int count) {
		if (count > 0)
		{
			this->count = count;
		}
		else
		{
			throw InvalidArgumentException("Count < 0", __LINE__, "exception.txt");
		}
	}
};