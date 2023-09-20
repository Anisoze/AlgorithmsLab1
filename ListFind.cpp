#pragma once
#include "include.h"

int ListFind(List** Cur, List** Head2) {
	List* Cur2 = *Head2;
		while ((*Cur)!= NULL) {
			if ((Cur2)->num == (*Cur)->num) {
				while ((Cur2)!= NULL) {
					if ((Cur2)->num == (*Cur)->num){
						(*Cur) = (*Cur)->pNext;
						(Cur2) = (Cur2)->pNext;
						if ((*Cur) == NULL && (Cur2) != NULL) {
							return 0;
						}
						else if ((Cur2) == NULL) {
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
			}
		}
		return 0;
}