#pragma once
#include "include.h"

int AddLast(std::fstream& g, List** Cur, int count) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
		while ((*Cur)->pNext != NULL) {
			(*Cur) = (*Cur)->pNext;
		}
		std::cout << "\n ������� �����\n";
		int number;
		std::cin >> number;
		(*Cur)->pNext = new List;
		if (count != 0) {
			(*Cur) = (*Cur)->pNext;
		}
		(*Cur)->pNext = NULL;
		(*Cur)->num = number;
		g << "\n\n��������� ������� 1\n���������� ������:\n\n";
		g.close();
		return 1;
	}
	else {
		return 2;
	}
}