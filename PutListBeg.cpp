#pragma once
#include "include.h"

int PutListBeg(std::fstream& g, List** Cur, List** Cur2) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
			List* Tmp = *Cur;
			List* Head2 = new List;
			*Cur = Head2;
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
			(*Cur) = Head2;
			g << "\n\n��������� ������� 15\n���������� ������:\n\n";
			g.close();
			return 1;
	}
	else {
		return 2;
	}
}