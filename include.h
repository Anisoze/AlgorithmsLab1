#pragma once

#include <fstream>
#include <iostream>
#include "List.h"

int Read(std::fstream& f, int* count, List** Cur);
void Error(std::fstream& g, int res);
int Out(std::fstream& g, List** Cur, int count);
int Ask();
int AddLast(std::fstream& g, List** Cur, int count);
int AddFirst(std::fstream& g, List** Head, int count);
int DelLast(std::fstream& g, List** Cur);
int DelFirst(std::fstream& g, List** Cur);
int PutIndex(std::fstream& g, List** Cur, int count);
void GetIndex(List** Cur, int count);
int DelIndex(std::fstream& g, List** Cur, int count);
void DelAll(List** Cur);
int ChangeIndex(std::fstream& g, List** Cur, int count);
int Rotate(std::fstream& g, List** Head, int count);
int PutListIndex(std::fstream& g, List** Cur, int count, List** Cur2);
int PutListEnd(std::fstream& g, List** Cur, List** Cur2);
int PutListBeg(std::fstream& g, List** Cur, List** Cur2);
int ListFind(List** Cur, List** Head2);
int ListFindFirst(List** Cur, List** Head2, int* tmp);
int ListFindLast(List** Cur, List** Head2, int* tmp);
int TradeIndex(std::fstream& g, List** Head, int count);