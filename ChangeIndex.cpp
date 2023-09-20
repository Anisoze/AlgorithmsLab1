#pragma once
#include "include.h"

int ChangeIndex(std::fstream& g, List** Cur, int count) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
		int number;
		int index;
		if (count == 0) {
			count = 1;
		}
		std::cout << "\n ������� ������������ �������\n";
		std::cin >> number;
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
			(*Cur)->num = number;
			g << "\n\n��������� ������� 10\n���������� ������:\n\n";
			g.close();
			return 1;
		}
		else {
			for (int i = index; i > 1; i--) {
				(*Cur) = (*Cur)->pNext;
			}
			(*Cur)->pNext->num = number;
			g << "\n\n��������� ������� 10\n���������� ������:\n\n";
			g.close();
			return 1;
		}
	}
	else {
		return 2;
	}
}