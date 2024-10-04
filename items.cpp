#include "items.h"
#include <iostream>

Items::Items(){}
Items::Items(int number):number(number) {
}

Items::Items(char operand): operand(operand){}

int Items::GetNum() const {
	return number;
}

void Items::SetNum(int num) {
	this->number = num;
}

char Items::GetOp() const {
	return operand;
}

void Items::SetOp(char op) {
	this->operand = op;
}

void Items::SetNext(Items* ptr) {
	next = ptr;
}

Items* Items::GetNext() const {
	return next;
}

void Items::out() {
	if (operand == '\0') {
		std::cout << number << " ";
	}
	else {
		if (operand == 'M')
		{
			std::cout << "MAX" <<counter<< ' ';
		}
		else if (operand == 'm') {
			std::cout << "MIN" << counter << ' ';
		}
		else if (operand == 'I') {
			std::cout << "IF" << ' ';
		}
		else {
			std::cout << operand << " ";//DO MINIMUM DODAC NUMER RZECZY
		}
	}
}

void Items::incr_counter() {
	counter++;
}

int Items::GetCounter() const{
	return counter;
}

Items::~Items() {

}