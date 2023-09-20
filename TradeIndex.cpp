#pragma once
#include "include.h"

int TradeIndex(std::fstream& g, List** Head, int count) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
		int index2;
		int index1;
		while (true) {
			std::cout << "\n Введите первый индекс элемента для обмена\n";
			std::cin >> index1;
			if ((index1 < 0) || (index1 > (count - 1))) {
				if (index1 < 0) {
					std::cout << "\n Индекс должен быть не отрицательным\n";
				}
				else if (index1 > (count - 1)) {
					std::cout << "\n Индекс не должен быть расположен после последнего индекса текущего списка\n";
				}
			}
			else {
				break;
			}
		}
		while (true) {
			std::cout << "\n Введите второй индекс элемента для обмена\n";
			std::cin >> index2;
			if ((index2 < 0) || (index2 > (count - 1)) || index2 == index1) {
				if (index2 < 0) {
					std::cout << "\n Индекс должен быть не отрицательным\n";
				}
				else if (index2 > (count - 1)) {
					std::cout << "\n Индекс не должен быть расположен после последнего индекса текущего списка\n";
				}
				else if (index2 == index1) {
					std::cout << "\n Индексы должены быть различны\n";
				}
			}
			else {
				break;
			}
		}
		int tmp;
		int number;
		List* Cur = *Head;

		if (index1 > index2) {
			tmp = index2;
			index2 = index1;
			index1 = tmp;
		}

		if (index1 == 0) {
			number = Cur->num;
		}
		else {
			for (int i = index1; i > 1; i--) {
				Cur = Cur->pNext;
			}
			number = Cur->pNext->num;
		}
		Cur = *Head;
		for (int j = index2; j > 1; j--) {
			Cur = Cur->pNext;
		}
		tmp = Cur->pNext->num;
		Cur->pNext->num = number;
		Cur = *Head;

		if (index1 == 0) {
			Cur->num = tmp;
		}
		else {
			for (int i = index1; i > 1; i--) {
				Cur = Cur->pNext;
			}
			Cur->pNext->num = tmp;
		}


		g << "\n\nВыполение функции 19\nОбновлённый список:\n\n";
		g.close();
		return 1;
	
	}
	else {
		return 2;
	}
}