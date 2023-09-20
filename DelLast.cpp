#pragma once
#include "include.h"

int DelLast(std::fstream& g, List** Cur) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
		if ((*Cur)->pNext != NULL) {
			List* Tmp = new List;
			Tmp = (*Cur)->pNext;
			while (Tmp->pNext != NULL) {
				Tmp = Tmp->pNext;
				(*Cur) = (*Cur)->pNext;
			}
			(*Cur)->pNext = NULL;
			delete Tmp;
		}
		else {
			(*Cur)->pNext = new List;
			List* Tmp = (*Cur);
			(*Cur) = (*Cur)->pNext;
			(*Cur)->pNext = NULL;
			delete Tmp;
		}
		g << "\n\nВыполение функции 3\nОбновлённый список:\n\n";
		g.close();
		return 1;
	}
	else {
		return 2;
	}
}