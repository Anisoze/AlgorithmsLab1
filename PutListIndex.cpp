#pragma once
#include "include.h"

int PutListIndex(std::fstream& g, List** Cur, int count, List** Cur2) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
		int index;
		if (count == 0) {
			count = 1;
		}
		while (true) {
			std::cout << "\n Введите индекс, с которого будет вставлен второй список\n";
			std::cin >> index;
			if ((index < 0) || (index > count)) {
				if (index < 0) {
					std::cout << "\n Индекс должен быть не отрицательным\n";
				}
				else if (index > count) {
					std::cout << "\n Индекс не должен быть расположен после индекса идущего за концом изначального списка\n";
				}
			}
			else {
				break;
			}
		}

		if (index == 0) {
			List* Tmp = *Cur;
			List* Head2 = new List;
			*Cur = Head2;
			do {
				(*Cur)->num = (*Cur2)->num;
				if ((*Cur2)->pNext!= NULL) {
					(*Cur)->pNext = new List;
					(*Cur) = (*Cur)->pNext;
					(*Cur2) = (*Cur2)->pNext;
				}
			} while ((*Cur2)->pNext != NULL);
			(*Cur)->num = (*Cur2)->num;
			(*Cur)->pNext = Tmp;
			(*Cur) = Head2;
			g << "\n\nВыполение функции 13\nОбновлённый список:\n\n";
			g.close();
			return 3;
		}

		else if (index == count){
			for (int i = index; i > 1; i--) {
				(*Cur) = (*Cur)->pNext;
			}
			(*Cur)->pNext = new List;
			*Cur = (*Cur)->pNext;
			do {
				(*Cur)->num = (*Cur2)->num;
				if ((*Cur2)->pNext != NULL) {
					(*Cur)->pNext = new List;
					(*Cur) = (*Cur)->pNext;
					(*Cur2) = (*Cur2)->pNext;
				}
			} while ((*Cur2)->pNext != NULL);
			(*Cur)->num = (*Cur2)->num;
			(*Cur)->pNext = NULL;
			g << "\n\nВыполение функции 13\nОбновлённый список:\n\n";
			g.close();
			return 1;
		}

		else {
			for (int i = index; i > 1; i--) {
				(*Cur) = (*Cur)->pNext;
			}
			List* Tmp = (*Cur)->pNext;
			List* Head2 = new List;
			(*Cur)->pNext = Head2;
			(*Cur) = (*Cur)->pNext;
			do {
				(*Cur)->num = (*Cur2)->num;
				if ((*Cur2)->pNext != NULL) {
					(*Cur)->pNext = new List;
					(*Cur) = (*Cur)->pNext;
					(*Cur2) = (*Cur2)->pNext;
				}
			} while ((*Cur2)->pNext != NULL);
			(*Cur)->num = (*Cur2)->num;
			(*Cur)->pNext = Tmp;
			g << "\n\nВыполение функции 13\nОбновлённый список:\n\n";
			g.close();
			return 1;
		}
	}
	else {
		return 2;
	}
}