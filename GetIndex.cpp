#pragma once
#include "include.h"

void GetIndex(List** Cur, int count) {
		int number;
		int index;
		if (count == 0) {
			count = 1;
		}
		while (true) {
			std::cout << "\n ������� ������, �� �������� ����� ������� �������\n";
			std::cin >> index;
			if ((index < 0) || (index > (count - 1))) {
				if (index < 0) {
					std::cout << "\n ������ ������ ���� �� �������������\n";
				}
				else if (index > (count - 1)) {
					std::cout << "\n ������ �� ������ ���� ���������� ����� ���������� ������� �������� ������\n";
				}
			}
			else {
				break;
			}
		}
		if (index == 0) {
			number = (*Cur)->num;
			std::cout << "\n ������� ����� " << number << "\n";
		}
		else {
			for (int i = index; i > 1; i--) {
				(*Cur) = (*Cur)->pNext;
			}
			number = (*Cur)->pNext->num;
			std::cout << "\n ������� ����� " << number << "\n";
		}
	
}