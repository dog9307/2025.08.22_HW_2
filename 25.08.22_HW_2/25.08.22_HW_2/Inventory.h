#pragma once

#include <iostream>
#include <string>
#include <algorithm>

#include "Item.h"

using namespace std;

#define SAFE_DELETE(p)		 if (p) {delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if (p) {delete[] p; p = nullptr;}

template <typename T>
class Inventory
{
private:
	T* pItems_;
	int capacity_;
	int size_;

public:
	Inventory(int capacity = 10);
	Inventory(const Inventory<T>& other);
	~Inventory();

	void AddItem(const T& item);
	void RemoveLastItem();
	void PrintAllItems() const;

	void Assign(const Inventory<T>& other);
	void Resize(int newCapacity);
	void SortItems();


	inline int GetSize() const { return size_; }
	inline int GetCapacity() const { return capacity_; }
};

template<typename T>
inline Inventory<T>::Inventory(int capacity)
{
	SAFE_DELETE_ARRAY(pItems_)

	capacity_ = (capacity <= 0 ? 1 : capacity);
	pItems_ = new T[capacity_];

	size_ = 0;
}

template<typename T>
inline Inventory<T>::Inventory(const Inventory<T>& other)
{
	Assign(other);
	//this->capacity_ = other.capacity_;
	//this->size_ = other.size_;
	//
	//SAFE_DELETE_ARRAY(pItems_);
	//pItems_ = new T[capacity_];
	//for (int i = 0; i < size_; ++i)
	//{
	//	this->pItems_[i] = other.pItems_[i];
	//}
	//
	//cout << "인벤토리 복사 완료" << endl;
}

template<typename T>
inline Inventory<T>::~Inventory()
{
	for (int i = 0; i < size_; ++i)
	{
		SAFE_DELETE(pItems_[i])
	}

	SAFE_DELETE_ARRAY(pItems_)
}

template<typename T>
inline void Inventory<T>::AddItem(const T& item)
{
	if (!pItems_)
		pItems_ = new T[capacity_];

	//if (size_ < capacity_)
	//{
	//	pItems_[size_] = item;
	//	++size_;
	//}
	//else
	//{
	//	cout << "인벤토리가 꽉 찼습니다!" << endl;
	//}

	if (size_ >= capacity_)
		Resize(capacity_ * 2);

	pItems_[size_] = item;
	++size_;
}

template<typename T>
inline void Inventory<T>::RemoveLastItem()
{
	if (size_ > 0)
	{
		SAFE_DELETE(pItems_[size_ - 1])
		--size_;
	}
	else
	{
		cout << "인벤토리가 비어있습니다!" << endl;
	}
}

template<typename T>
inline void Inventory<T>::PrintAllItems() const
{
	for (int i = 0; i < size_; ++i)
	{
		cout << i + 1 << ". " << endl;
		pItems_[i]->PrintInfo();
	}
}

template<typename T>
inline void Inventory<T>::Assign(const Inventory<T>& other)
{
	this->capacity_ = other.capacity_;
	this->size_ = other.size_;

	SAFE_DELETE_ARRAY(pItems_);
	pItems_ = new T[capacity_];
	for (int i = 0; i < size_; ++i)
	{
		this->pItems_[i] = other.pItems_[i];
	}

	cout << "인벤토리 복사 완료" << endl;
}

template<typename T>
inline void Inventory<T>::Resize(int newCapacity)
{
	capacity_ = newCapacity;
	T* temp = pItems_;
	pItems_ = new T[capacity_];

	for (int i = 0; i < size_; ++i)
	{
		pItems_[i] = temp[i];
	}

	SAFE_DELETE_ARRAY(temp);
}

template<typename T>
inline void Inventory<T>::SortItems()
{
	sort(pItems_, pItems_ + size_, Item::compareItemsByPrice);
}
