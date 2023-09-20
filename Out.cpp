#pragma once
#include "include.h"

int Out(std::fstream& g, List** Cur, int count) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
		while ((*Cur)->pNext != NULL) {
			g << (*Cur)->num;
			g << "\n";
			(*Cur) = (*Cur)->pNext;
		}
		if (count > 0) {
			g << (*Cur)->num;
		}
		else {
			g << "\n\nСписок пуст\n";
		}
		g.close();
		return 1;
	}
	else {
		return 2;
	}
}