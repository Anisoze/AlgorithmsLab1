#pragma once
#include "include.h"

int Rotate(std::fstream& g, List** Head, int count) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
		int* A = new int[count];
		int i = 0;
		List* Cur = *Head;
		while (Cur->pNext != NULL) {
			A[i] = Cur->num;
			i++;
			Cur = Cur->pNext;
		}
		A[i] = Cur->num;
		Cur = *Head;
		for (i; i > -1; i--) {
			Cur->num = A[i];
			Cur = Cur->pNext;
		}
		g << "\n\nВыполение функции 12\nОбновлённый список:\n\n";
		g.close();
		delete A;
		return 1;
	}
	else {
		return 2;
	}
}