#include "itemslist.h"
#include <iostream>


ItemsList::ItemsList(){}

void ItemsList::add(Items* itemek) {//nasz current itemek
	if (first == nullptr) {
		first = itemek;
		prev = first;
		prev->SetNext(nullptr);
	}
	else {
		prev->SetNext(itemek);
		prev = itemek;
	}
	
	if (itemek->GetNext()!=nullptr && itemek->GetNext()->GetOp() == '(') {
		itemek->SetNext(nullptr);
	}
	
}

Items* ItemsList::pop() {
	Items* tmp = first;
	first = first->GetNext();
	return tmp;
}

void ItemsList::print() {
	Items* tmp = first;
	while (tmp->GetNext() != nullptr) {
		tmp->out();
		tmp = tmp->GetNext();
	}
	tmp->out();
}

Items* ItemsList::peek() {
	return first;
}

ItemsList::~ItemsList() {
	Items* tmp;
	while (first->GetNext() != nullptr) {
		tmp = first;
		first = tmp->GetNext();
		delete tmp;
	}
	delete first;
}