#pragma once
#include "include.h"

int AddFirst(std::fstream& g, List** Head, int count) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
		std::cout << "\n Введите число\n";
		int number;
		std::cin >> number;
		if (count != 0) {
			List* Tmp = new List;
			Tmp->num = number;
			Tmp->pNext = *Head;
			*Head = Tmp;
		}
		else {
			(*Head)->num = number;
		}
		g << "\n\nВыполение функции 2\nОбновлённый список:\n\n";
		g.close();
		return 1;
	}
	else {
		return 2;
	}
}