#include "Item.h"

Item::Item(string name, int price, string info)
{
	name_ = name;
	price_ = price;
	info_ = info;
}

void Item::PrintInfo() const
{
	cout << "[�̸�: " << name_ << ", ����: " << price_ << "G]" << endl;
	cout << "[���� : " << info_ << "]" << endl;
}

Item& Item::operator=(const Item& other)
{
	this->name_ = other.name_;
	this->price_ = other.price_;
	this->info_ = other.info_;

	return (*this);
}
