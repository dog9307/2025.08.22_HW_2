#include "Weapon.h"

Weapon::Weapon(string name, int price, string info, int atk) : Item(name, price, info)
{
	atk_ = atk;
}

void Weapon::PrintInfo() const
{
	__super::PrintInfo();

	cout << "[���ݷ� : " << atk_ << "]" << endl;
}

Weapon& Weapon::operator=(const Weapon& other)
{
	__super::operator=((Item&)other);

	this->atk_ = other.atk_;

	return (*this);
}
