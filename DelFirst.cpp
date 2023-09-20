#pragma once
#include "include.h"

int DelFirst(std::fstream& g, List** Cur) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
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
		g << "\n\nВыполение функции 4\nОбновлённый список:\n\n";
		g.close();
		return 1;
	}
	else {
		return 2;
	}
}