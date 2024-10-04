#include "stack.h"
#include "items.h"
#include <iostream>

Stack::Stack(){}

void Stack::push(Items* item) {
	if (top != nullptr) {
		item->SetNext(top);
	}
	else {
		item->SetNext(nullptr);
	}
	top = item;
}

Items* Stack::pop() {
	Items* topik = top;
	top = top->GetNext();
	return topik;
}

Items* Stack::kret() {
	Items* tmp=top;
	if (tmp != nullptr) {//this added
		while (tmp->GetNext() != nullptr) {//nadal wywala blad ze nullptr zwraca
			if (tmp->GetOp() == 'm' || tmp->GetOp() == 'M' || tmp->GetOp() == 'I') {
				return tmp;
			}
			tmp = tmp->GetNext();
		}
		if (tmp->GetOp() == 'm' || tmp->GetOp() == 'M' || tmp->GetOp() == 'I') {
			return tmp;
		}
	}
	return nullptr;
}

char Stack::peek_op() {
	return top->GetOp();
}

Items* Stack::peek() {
	return top;
}
void Stack::print_stos() {
	Items* tmp = top;
	if (tmp != nullptr) {
		while (tmp->GetNext() != nullptr) {
			tmp->out();
			tmp = tmp->GetNext();
		}
		tmp->out();
	}
}

Stack::~Stack() {
	Items* topik;
	while (top->GetNext() != nullptr) {
		topik = top;
		top = top->GetNext();
		delete topik;
	}
	delete top;
}