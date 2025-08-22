#include "Inventory.h"

#include "Weapon.h"
#include "Potion.h"

#pragma region For Test Funcs

template <typename T>
void PrintInventoryInfo(Inventory<T>* inven)
{
	inven->PrintAllItems();
	cout << "Capacity : " << inven->GetCapacity() << endl;
	cout << "Size : " << inven->GetSize() << endl;
	cout << endl;
	cout << endl;
}

Item* CreateItem(string name, int price, string info)
{
	Item* temp = new Item(name, price, info);
	return temp;
}
Item* CreateItem(const Item* recipe)
{
	Item* temp = new Item();
	(*temp) = (*recipe);
	return temp;
}

Weapon* CreateWeapon(string name, int price, string info, int atk)
{
	Weapon* temp = new Weapon(name, price, info, atk);
	return temp;
}

Weapon* CreateWeapon(const Weapon* recipe)
{
	Weapon* temp = new Weapon();
	(*temp) = (*recipe);
	return temp;
}

Potion* CreatePotion(string name, int price, string info, int amount)
{
	Potion* temp = new Potion(name, price, info, amount);
	return temp;
}

Potion* CreatePotion(const Potion* recipe)
{
	Potion* temp = new Potion();
	(*temp) = (*recipe);
	return temp;
}

#pragma endregion

int main()
{
#pragma region For Test Setting

	Item* item1  = new Item("������1" , 10 , "�׽�Ʈ ������1" );
	Item* item2  = new Item("������2" , 20 , "�׽�Ʈ ������2" );
	Item* item3  = new Item("������3" , 30 , "�׽�Ʈ ������3" );
	Item* item4  = new Item("������4" , 40 , "�׽�Ʈ ������4" );
	Item* item5  = new Item("������5" , 50 , "�׽�Ʈ ������5" );
	Item* item6  = new Item("������6" , 60 , "�׽�Ʈ ������6" );
	Item* item7  = new Item("������7" , 70 , "�׽�Ʈ ������7" );
	Item* item8  = new Item("������8" , 80 , "�׽�Ʈ ������8" );
	Item* item9  = new Item("������9" , 90 , "�׽�Ʈ ������9" );
	Item* item10 = new Item("������10", 100, "�׽�Ʈ ������10");

	Weapon* weapon1  = new Weapon("����1" , 1000 , "�׽�Ʈ ����1" , 10 );
	Weapon* weapon2  = new Weapon("����2" , 2000 , "�׽�Ʈ ����2" , 20 );
	Weapon* weapon3  = new Weapon("����3" , 3000 , "�׽�Ʈ ����3" , 30 );
	Weapon* weapon4  = new Weapon("����4" , 4000 , "�׽�Ʈ ����4" , 40 );
	Weapon* weapon5  = new Weapon("����5" , 5000 , "�׽�Ʈ ����5" , 50 );
	Weapon* weapon6  = new Weapon("����6" , 6000 , "�׽�Ʈ ����6" , 60 );
	Weapon* weapon7  = new Weapon("����7" , 7000 , "�׽�Ʈ ����7" , 70 );
	Weapon* weapon8  = new Weapon("����8" , 8000 , "�׽�Ʈ ����8" , 80 );
	Weapon* weapon9  = new Weapon("����9" , 9000 , "�׽�Ʈ ����9" , 90 );
	Weapon* weapon10 = new Weapon("����10", 10000, "�׽�Ʈ ����10", 100);

	Potion* potion1  = new Potion("����1" , 100 , "�׽�Ʈ ����1" , 10 );
	Potion* potion2  = new Potion("����2" , 200 , "�׽�Ʈ ����2" , 20 );
	Potion* potion3  = new Potion("����3" , 300 , "�׽�Ʈ ����3" , 30 );
	Potion* potion4  = new Potion("����4" , 400 , "�׽�Ʈ ����4" , 40 );
	Potion* potion5  = new Potion("����5" , 500 , "�׽�Ʈ ����5" , 50 );
	Potion* potion6  = new Potion("����6" , 600 , "�׽�Ʈ ����6" , 60 );
	Potion* potion7  = new Potion("����7" , 700 , "�׽�Ʈ ����7" , 70 );
	Potion* potion8  = new Potion("����8" , 800 , "�׽�Ʈ ����8" , 80 );
	Potion* potion9  = new Potion("����9" , 900 , "�׽�Ʈ ����9" , 90 );
	Potion* potion10 = new Potion("����10", 1000, "�׽�Ʈ ����10", 100);

	Item* tempItem = nullptr;
	Weapon* tempWeapon = nullptr;
	Potion* tempPotion = nullptr;

#pragma endregion

	Inventory<Item*>* inven = new Inventory<Item*>();

	PrintInventoryInfo<Item*>(inven);

	inven->AddItem(item1);
	inven->AddItem(item2);
	inven->AddItem(item3);
	inven->AddItem(weapon4);
	inven->AddItem(item5);
	inven->AddItem(weapon6);
	inven->AddItem(item7);
	inven->AddItem(item8);
	inven->AddItem(potion9);
	inven->AddItem(potion10);

	PrintInventoryInfo<Item*>(inven);

	inven->AddItem(weapon10);
	inven->AddItem(CreatePotion(potion9));

	PrintInventoryInfo<Item*>(inven);

	inven->RemoveLastItem();

	PrintInventoryInfo<Item*>(inven);

	cout << "Sort Test" << endl;
	inven->AddItem(CreateItem(item4));
	PrintInventoryInfo<Item*>(inven);
	cout << "Do Sort" << endl;
	inven->SortItems();
	PrintInventoryInfo<Item*>(inven);

	while (inven->GetSize() != 0)
	{
		inven->RemoveLastItem();
	}
	inven->RemoveLastItem();

	PrintInventoryInfo<Item*>(inven);

	delete inven;

#pragma region For Test Deletes

	SAFE_DELETE(item1 )
	SAFE_DELETE(item2 )
	SAFE_DELETE(item3 )
	SAFE_DELETE(item4 )
	SAFE_DELETE(item5 )
	SAFE_DELETE(item6 )
	SAFE_DELETE(item7 )
	SAFE_DELETE(item8 )
	SAFE_DELETE(item9 )
	SAFE_DELETE(item10)
		
	SAFE_DELETE(weapon1 )
	SAFE_DELETE(weapon2 )
	SAFE_DELETE(weapon3 )
	SAFE_DELETE(weapon4 )
	SAFE_DELETE(weapon5 )
	SAFE_DELETE(weapon6 )
	SAFE_DELETE(weapon7 )
	SAFE_DELETE(weapon8 )
	SAFE_DELETE(weapon9 )
	SAFE_DELETE(weapon10)
		
	SAFE_DELETE(potion1 )
	SAFE_DELETE(potion2 )
	SAFE_DELETE(potion3 )
	SAFE_DELETE(potion4 )
	SAFE_DELETE(potion5 )
	SAFE_DELETE(potion6 )
	SAFE_DELETE(potion7 )
	SAFE_DELETE(potion8 )
	SAFE_DELETE(potion9 )
	SAFE_DELETE(potion10)

	SAFE_DELETE(tempItem)
	SAFE_DELETE(tempWeapon)
	SAFE_DELETE(tempPotion)

#pragma endregion

	return 0;
}