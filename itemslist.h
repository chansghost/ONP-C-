#pragma once
#include "items.h"

class ItemsList {
private: 
	Items* first=nullptr;
	Items* prev = nullptr;
public:
	ItemsList();
	//ItemsList(Items* item);
	void add(Items* itemek);
	Items* pop();
	void print();
	Items* peek();
	~ItemsList();
};