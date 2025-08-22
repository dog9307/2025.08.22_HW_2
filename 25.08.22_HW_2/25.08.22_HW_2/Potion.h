#pragma once
#include "Item.h"
class Potion : public Item
{
private:
	int amount_;

public:
	Potion() {}
	Potion(string name, int price, string info, int amount);
	virtual ~Potion() {}

	void PrintInfo() const override;

	Potion& operator=(const Potion& other);
};

