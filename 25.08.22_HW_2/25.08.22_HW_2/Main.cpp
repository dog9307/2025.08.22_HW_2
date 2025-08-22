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

	Item* item1  = new Item("아이템1" , 10 , "테스트 아이템1" );
	Item* item2  = new Item("아이템2" , 20 , "테스트 아이템2" );
	Item* item3  = new Item("아이템3" , 30 , "테스트 아이템3" );
	Item* item4  = new Item("아이템4" , 40 , "테스트 아이템4" );
	Item* item5  = new Item("아이템5" , 50 , "테스트 아이템5" );
	Item* item6  = new Item("아이템6" , 60 , "테스트 아이템6" );
	Item* item7  = new Item("아이템7" , 70 , "테스트 아이템7" );
	Item* item8  = new Item("아이템8" , 80 , "테스트 아이템8" );
	Item* item9  = new Item("아이템9" , 90 , "테스트 아이템9" );
	Item* item10 = new Item("아이템10", 100, "테스트 아이템10");

	Weapon* weapon1  = new Weapon("무기1" , 1000 , "테스트 무기1" , 10 );
	Weapon* weapon2  = new Weapon("무기2" , 2000 , "테스트 무기2" , 20 );
	Weapon* weapon3  = new Weapon("무기3" , 3000 , "테스트 무기3" , 30 );
	Weapon* weapon4  = new Weapon("무기4" , 4000 , "테스트 무기4" , 40 );
	Weapon* weapon5  = new Weapon("무기5" , 5000 , "테스트 무기5" , 50 );
	Weapon* weapon6  = new Weapon("무기6" , 6000 , "테스트 무기6" , 60 );
	Weapon* weapon7  = new Weapon("무기7" , 7000 , "테스트 무기7" , 70 );
	Weapon* weapon8  = new Weapon("무기8" , 8000 , "테스트 무기8" , 80 );
	Weapon* weapon9  = new Weapon("무기9" , 9000 , "테스트 무기9" , 90 );
	Weapon* weapon10 = new Weapon("무기10", 10000, "테스트 무기10", 100);

	Potion* potion1  = new Potion("포션1" , 100 , "테스트 포션1" , 10 );
	Potion* potion2  = new Potion("포션2" , 200 , "테스트 포션2" , 20 );
	Potion* potion3  = new Potion("포션3" , 300 , "테스트 포션3" , 30 );
	Potion* potion4  = new Potion("포션4" , 400 , "테스트 포션4" , 40 );
	Potion* potion5  = new Potion("포션5" , 500 , "테스트 포션5" , 50 );
	Potion* potion6  = new Potion("포션6" , 600 , "테스트 포션6" , 60 );
	Potion* potion7  = new Potion("포션7" , 700 , "테스트 포션7" , 70 );
	Potion* potion8  = new Potion("포션8" , 800 , "테스트 포션8" , 80 );
	Potion* potion9  = new Potion("포션9" , 900 , "테스트 포션9" , 90 );
	Potion* potion10 = new Potion("포션10", 1000, "테스트 포션10", 100);

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