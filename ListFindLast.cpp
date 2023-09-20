#pragma once
#include "include.h"

int ListFindLast(List** Cur, List** Head2, int* tmp) {
	List* Cur2 = *Head2;
	*tmp = 0;
	int k;
	int b = -90;
	while ((*Cur) != NULL) {
		if ((Cur2)->num == (*Cur)->num) {
			k = *tmp;
			while ((Cur2) != NULL) {
				if ((Cur2)->num == (*Cur)->num) {
					(*Cur) = (*Cur)->pNext;
					(Cur2) = (Cur2)->pNext;
					(*tmp)++;
					if ((*Cur) == NULL && (Cur2) != NULL) {
						break;
					}
					else if ((Cur2) == NULL) {
						b = k;
						Cur2 = *Head2;
						break;
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
	if (b != -90) {
		*tmp = b;
		return 1;
	}
	else {
		return 0;
	}
}