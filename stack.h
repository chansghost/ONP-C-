#pragma once
#include "items.h"

class Stack {
private:
	Items* top=nullptr;
public:
	Stack();
	void push(Items*item);
	Items* pop();
	Items* kret();
	char peek_op();
	Items* peek();
	void print_stos();
	~Stack();

};