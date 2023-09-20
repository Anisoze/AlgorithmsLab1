#pragma once
#include "include.h"

void GetIndex(List** Cur, int count) {
		int number;
		int index;
		if (count == 0) {
			count = 1;
		}
		while (true) {
			std::cout << "\n ¬ведите индекс, из которого будет получен элемент\n";
			std::cin >> index;
			if ((index < 0) || (index > (count - 1))) {
				if (index < 0) {
					std::cout << "\n »ндекс должен быть не отрицательным\n";
				}
				else if (index > (count - 1)) {
					std::cout << "\n »ндекс не должен быть расположен после последнего индекса текущего списка\n";
				}
			}
			else {
				break;
			}
		}
		if (index == 0) {
			number = (*Cur)->num;
			std::cout << "\n Ёлемент равен " << number << "\n";
		}
		else {
			for (int i = index; i > 1; i--) {
				(*Cur) = (*Cur)->pNext;
			}
			number = (*Cur)->pNext->num;
			std::cout << "\n Ёлемент равен " << number << "\n";
		}
	
}