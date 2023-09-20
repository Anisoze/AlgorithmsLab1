#pragma once
#include "include.h"

int PutListEnd(std::fstream& g, List** Cur, List** Cur2) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()){
			while ((*Cur)->pNext!=NULL) {
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
			g << "\n\nВыполение функции 14\nОбновлённый список:\n\n";
			g.close();
			return 1;
	}
	else {
		return 2;
	}
}