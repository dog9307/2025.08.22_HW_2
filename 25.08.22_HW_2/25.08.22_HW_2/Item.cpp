#include "Item.h"

Item::Item(string name, int price, string info)
{
	name_ = name;
	price_ = price;
	info_ = info;
}

void Item::PrintInfo() const
{
	cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
	cout << "[설명 : " << info_ << "]" << endl;
}

Item& Item::operator=(const Item& other)
{
	this->name_ = other.name_;
	this->price_ = other.price_;
	this->info_ = other.info_;

	return (*this);
}
