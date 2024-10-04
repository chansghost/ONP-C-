#pragma once
#define BUFFOR_SIZE 100
#include "items.h"
#include "itemslist.h"
#include "stack.h"

class Parse {
public:
	Parse();//we need it for shit's and giggles ig
	void Parser(char input);
	~Parse();

private:
	//do tego wrócimy
	Items* item = nullptr;
	Items* currentM = nullptr;
	ItemsList* lista=new ItemsList();
	Stack* ops = new Stack();
	int buffor_index=0;
	int bracket_counter = 0;
	char buffor[BUFFOR_SIZE];
};
