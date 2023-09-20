#pragma once
#include "include.h"

void DelAll(List** Cur) {
	while ((*Cur)->pNext != NULL) {
		List* Tmp = (*Cur);
		(*Cur) = (*Cur)->pNext;
		delete Tmp;
	}
	(*Cur)->pNext = new List;
	List* Tmp = (*Cur);
	(*Cur) = (*Cur)->pNext;
	(*Cur)->pNext = NULL;
	delete Tmp;
}