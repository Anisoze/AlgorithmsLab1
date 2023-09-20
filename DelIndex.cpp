#pragma once
#include "include.h"

int DelIndex(std::fstream& g, List** Cur, int count) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
		int index;
		while (true) {
			std::cout << "\n Введите индекс, по которому будет удален элемент\n";
			std::cin >> index;
			if ((index < 0) || (index > (count - 1))) {
				if (index < 0) {
					std::cout << "\n Индекс должен быть не отрицательным\n";
				}
				else if (index > (count - 1)) {
					std::cout << "\n Индекс не должен быть расположен после последнего индекса текущего списка\n";
				}
			}
			else {
				break;
			}
		}

		if (index == 0) {
			if ((*Cur)->pNext != NULL) {
				List* Tmp = (*Cur);
				(*Cur) = (*Cur)->pNext;
				delete Tmp;
			}
			else {
				(*Cur)->pNext = new List;
				List* Tmp = (*Cur);
				(*Cur) = (*Cur)->pNext;
				(*Cur)->pNext = NULL;
				delete Tmp;
			}
			g << "\n\nВыполение функции 7\nОбновлённый список:\n\n";
			g.close();
			return 3;
		}


		else if (index == (count - 1)) {
			List* Tmp = new List;
			Tmp = (*Cur)->pNext;
			while (Tmp->pNext != NULL) {
				Tmp = Tmp->pNext;
				(*Cur) = (*Cur)->pNext;
			}
			(*Cur)->pNext = NULL;
			delete Tmp;
			g << "\n\nВыполение функции 7\nОбновлённый список:\n\n";
			g.close();
			return 1;
		}


		else {
			for (int i = index; i > 1; i--) {
				(*Cur) = (*Cur)->pNext;
			}
			List* Tmp = new List;
			Tmp = (*Cur)->pNext;
			(*Cur)->pNext = Tmp->pNext;
			delete Tmp;
			g << "\n\nВыполение функции 7\nОбновлённый список:\n\n";
			g.close();
			return 1;
		}

	}
	else {
		return 2;
	}
}