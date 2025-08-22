#pragma once

#include <iostream>
#include <string>

using namespace std;

class Item
{
protected:
	int price_;
	string name_;
	string info_;

public:
	Item() {}
	Item(string name, int price, string info);
	virtual ~Item() {}

	virtual void PrintInfo() const;

	Item& operator=(const Item& other);

	inline int GetPrice() const { return price_; }

	static bool compareItemsByPrice(const Item* a, const Item* b)
	{
		return a->GetPrice() < b->GetPrice();
	}
};
