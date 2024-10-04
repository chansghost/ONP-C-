//#define BUFFOR_SIZE 100
#include "parse.h"
#include <iostream>
#include "functions.h"
#include "items.h"


Parse::Parse() {

}

void Parse::Parser(char input) {
	bool ifnumber = false;
	int number = 0;
	char operand = '0';
	//robienie pustego buforka
	if (buffor_index == 0) {
		for (int i = 0; i < BUFFOR_SIZE; i++) {
			buffor[i] = ' ';
		}
	}


	//if not kropka
		//if not znak bialy
			//dodaj do tablicy buffor
		//przerob na itemek
		// jak liczba do listy
		// jak operand to stos
		// koniec nawiasu dodaj do listy
		//delete buffor
	//else jazda z kurwami
	if (input != '.') {
		if (!znak_bialy(input)) {
			buffor[buffor_index] = input;
			buffor_index++;
		}
		//przerabiamy na itemek
		else if (!znak_bialy(buffor[0])) {

			//LICZBY

			if (if_number(buffor, buffor_index)) {
				ifnumber = true;

			}

			if (ifnumber) {//zrobienie numerka
				int i = 0;
				bool neg = false;
				if (buffor[0] == '-') {
					i = 1;
					neg = true;
				}
				for (i; i < buffor_index; i++) {//zmienic na i

					number = number * 10 + (buffor[i] - '0');

				}

				if (neg) {
					number = 0 - number;
				}

				item = new Items(number);

				lista->add(item);

			}

			//OPERANDY

			else {
				if (buffor[0] == ',') {
					if (currentM != nullptr) {
						currentM->incr_counter();
					}
					while (ops->peek_op() != '(') {
						lista->add(ops->pop());
						
					}
					
				}
				else {
					if (buffor_index == 1) {//to zmienic
						operand = buffor[0];
					}
					else if (buffor[0] == 'M') {//tu sie wypierdala
						if (buffor[1] == 'I') {
							operand = 'm';//dodac define do tego
						}
						else {
							operand = 'M';
						}
					}

					else if (buffor[0] == 'I') {
						operand = 'I';
					}
					
					if (operand == ')') {
						while (ops->peek_op() != '(') {
							lista->add(ops->pop());
						}
						ops->pop();
						if (ops->peek()!=nullptr && (ops->peek_op() == 'm' || ops->peek_op() == 'M' || ops->peek_op()=='I')) {
							lista->add(ops->pop());
							currentM = ops->kret();
						}
					}

					else if (operand != '(') {//dodac dla przecinka
						while (ops->peek() != nullptr && (priority(ops->peek_op()) >= priority(operand))) {
							if (!(ops->peek_op() == 'N' && priority(operand) == 3)) { //sprawdzamy czy operand ma ten sam priorytet co n
								if (operand != 'N') {
									lista->add(ops->pop());
								}
								else if (ops->peek_op() != 'N') {
									lista->add(ops->pop());
								}
							}
							else {
								break;
							}
						}
					}

					if (operand != ')') {
						item = new Items(operand);//czasem mamy wiecej niz 1 spacje
						if (operand == 'm' || operand == 'M' || operand=='I') {
							currentM = item;
						}
						ops->push(item);//pushujemy ) asp
					}
				}
			}
			buffor_index = 0;
		}
	}

	else {
		if (ops->peek() != nullptr) {
			while (ops->peek()->GetNext() != nullptr) {
				lista->add(ops->pop());
			}
			lista->add(ops->pop());
		}
		
		lista->print();
		bool zero_div = false;
		//dopoki lista n jest pusta
		std::cout << std::endl;
		//kalkulator
		int num = 0;
		while (lista->peek() != nullptr) {
			while (lista->peek()->GetOp() == '\0') {
				ops->push(lista->pop());
			}
			

			operand = lista->peek()->GetOp();
			int count = lista->peek()->GetCounter();
			lista->pop()->out();

			if (operand == 'm') {
				num = ops->pop()->GetNum();
				int b=-1;
				std::cout << num << ' ';
				for (int i = 0; i < count-1; i++) {
					if(ops->peek()!=nullptr)
					{
						b = ops->pop()->GetNum();
						if (b < num) {
							num = b;
						}
					}
					std::cout << b << ' ';
				}
				item = new Items(num);
			}
			else if (operand == 'M') {
				num = ops->pop()->GetNum();
				int b=-1;
				std::cout << num << ' ';
				for (int i = 0; i < count-1; i++) {
					if (ops->peek() != nullptr)
					{
						b = ops->pop()->GetNum();
						if (b > num) {
							num = b;
						}
					}
					std::cout << b << ' ';
				}
				item = new Items(num);
			}
			else if (operand == 'N') {
				num = ops->peek()->GetNum();
				ops->pop()->out();
				num = 0 - num;
				item = new Items(num);
			}
			else if (operand == 'I') {
				int c = ops->pop()->GetNum();
				int b = ops->pop()->GetNum();
				int a = ops->pop()->GetNum();
				std::cout << c << ' ' << b << ' ' << a<< ' ';
				if (a > 0) {
					num = b;
				}
				else {
					num = c;
				}
				item = new Items(num);
			}
			else {
				int b = ops->pop()->GetNum();
				int a = ops->pop()->GetNum();
				if (operand == '/') {
					if (b != 0) {
						num = a / b;
					}
					else {
						zero_div = true;
					}
				}
				else if (operand == '*') {
						num = a * b;
					}

				else if (operand == '+') {
					num = a + b;
				}

				else if (operand == '-') {
					num = a - b;

				}
				
				std::cout << b << ' ' << a <<' ';
				item = new Items(num);
			}
			
			
			
			//wywalenie reszty stosu
			ops->print_stos();// tu jest cos zjebane
			std::cout << std::endl;
			if (zero_div) {
				std::cout << "ERROR" << std::endl;
				break;
			}
			ops->push(item);
		}
		if (!zero_div) {
			std::cout << num << ' ' << std::endl;
		}
	}
}

Parse::~Parse() {
	delete item, currentM, lista, ops;

}


