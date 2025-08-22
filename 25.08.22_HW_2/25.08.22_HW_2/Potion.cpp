#include "Potion.h"

Potion::Potion(string name, int price, string info, int amount) : Item(name, price, info)
{
	amount_ = amount;
}

void Potion::PrintInfo() const
{
	__super::PrintInfo();

	cout << "[È¸º¹·® : " << amount_ << "]" << endl;
}

Potion& Potion::operator=(const Potion& other)
{
	__super::operator=((Item&)other);

	this->amount_ = other.amount_;

	return (*this);
}
