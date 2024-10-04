#pragma once

class Items {
public:
	Items();
	Items(int number);
	Items(char operand);
	//dopóki nie napotka nawiasu wrzucaj na stos, jak napotka nawias to
	//wyrzuca wszystko
	int GetNum() const;
	void SetNum(int num);

	char GetOp() const;
	void SetOp(char op);

	void SetNext(Items* ptr);
	Items* GetNext() const;
	void out();

	void incr_counter();
	int GetCounter() const;
	~Items();


private:
	int number=0;
	int counter=1;
	char operand='\0';//????
	Items* next=nullptr;

};