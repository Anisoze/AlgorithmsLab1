#pragma once
#include "include.h"

int ListFindFirst(List** Cur, List** Head2, int* tmp) {
	List* Cur2 = *Head2;
	*tmp = 0;
	int k;
	while ((*Cur) != NULL) {
		if ((Cur2)->num == (*Cur)->num) {
			k = *tmp;
			while ((Cur2) != NULL) {
				if ((Cur2)->num == (*Cur)->num) {
					(*Cur) = (*Cur)->pNext;
					(Cur2) = (Cur2)->pNext;
					(*tmp)++;
					if ((*Cur) == NULL && (Cur2) != NULL) {
						return 0;
					}
					else if ((Cur2) == NULL) {
						*tmp = k;
						return 1;
					}
				}
				else {
					Cur2 = *Head2;
					break;
				}
			}
		}
		else {
			(*Cur) = (*Cur)->pNext;
			(*tmp)++;
		}
	}
	return 0;
}