#pragma once
#include <fstream>
#include "include.h"

int Read(std::fstream& f, int* count, List** Cur) {
	if (f.is_open()) {
		int tmp = -9999;
		f >> tmp;
		if (f.eof() && tmp != 9999) {
			(*count)++;
			(*Cur)->num = tmp;
			(*Cur)->pNext = NULL;
		}
		while (!f.eof()) {
			(*count)++;
			(*Cur)->num = tmp;
			(*Cur)->pNext = new List;
			(*Cur) = (*Cur)->pNext;
			(*Cur)->pNext = NULL;
			f >> tmp;
			if (f.eof()) {
				(*count)++;
				(*Cur)->num = tmp;
			}
		}
		return 1;	
	}
	else {
		return 0;
	}
}