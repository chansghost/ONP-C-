#include <iostream>
#include "parse.h"
#include <iostream>
#include "functions.h"
#include "items.h"

int main() {
	char input;
	int n=0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		Parse* parser = new Parse();
		while (std::cin.get(input)) {
			parser->Parser(input);
			if (input == '.') {
				std::cout << std::endl;
				break;
			}
		}
		delete parser;
	}
}