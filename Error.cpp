#pragma once
#include "include.h"

void Error(std::fstream& g, int res) {
	if (res == 2) {
		std::cout << "\n ������ ���� �� ��� ������\n";
	}
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
		if (res == 0) {
			g << "\n������, in.txt �� ��� ������\n";
			std::cout << "\n ������, in.txt �� ��� ������\n";
		}
	}
	
}