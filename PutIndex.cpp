#pragma once
#include "include.h"

int PutIndex(std::fstream& g, List** Cur, int count) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
		int number;
		int index;
		if (count == 0) {
			count = 1;
		}
		std::cout << "\n Введите добавляемый элемент\n";
		std::cin >> number;
		while (true) {
			std::cout << "\n Введите индекс, по которому будет расположен элемент\n";
			std::cin >> index;
			if ((index < 0) || (index > (count - 1))) {
				if (index < 0) {
					std::cout << "\n Индекс должен быть не отрицательным\n";
				}
				else if (index > (count - 1)){
					std::cout << "\n Индекс не должен быть расположен после последнего индекса текущего списка\n";
				}
			}
			else {
				break;
			}
		}
		if (index == 0) {
			List* Tmp = new List;
			Tmp->num = number;
			Tmp->pNext = (*Cur);
			*Cur = Tmp;
			g << "\n\nВыполение функции 5\nОбновлённый список:\n\n";
			g.close();
			return 3;
		}
		else {
			List* Tmp = new List;
			Tmp->num = number;
			for (int i = index; i > 1; i--) {
				(*Cur) = (*Cur)->pNext;
			}
			Tmp->pNext = (*Cur)->pNext;
			(*Cur)->pNext = Tmp;
			g << "\n\nВыполение функции 5\nОбновлённый список:\n\n";
			g.close();
			return 1;
		}
	}
	else {
		return 2;
	}
}