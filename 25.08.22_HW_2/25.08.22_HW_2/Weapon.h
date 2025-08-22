#pragma once
#include "Item.h"

class Weapon : public Item
{
private:
	int atk_;

public:
	Weapon() {}
	Weapon(string name, int price, string info, int atk);
	virtual ~Weapon() {}

	void PrintInfo() const override;

	Weapon& operator=(const Weapon& other);
};

