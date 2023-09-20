
#include "include.h"

int main()
{
	std::setlocale(LC_CTYPE, "rus");
	std::fstream f, g;
	g.open("out.txt", std::ios::out);

	std::cout << " Автор: Гожан Максим Витальевич группа:2302\n АиСД\n Лабораторная работа #1 - Списки\n\n";

	if (g.is_open()) {
		g << "Автор: Гожан Максим Витальевич группа:2302\nАиСД\nЛабораторная работа #1 - Списки\n\n";
		g.close();

		int res, count = 0, count2 = 0, tmp;
		List* Head = new List;
		List* Head2 = new List;
		Head->pNext = NULL;
		Head2->pNext = NULL;
		List* Cur = new List;
		List* Cur2 = new List;
		Cur = Head;
		Cur2 = Head2;

		f.open("in.txt", std::ios::in);
		res = Read(f, &count, &Cur);
		if (res == 1) {
			f.close();
			std::cout << " Функция int Read выполнена\n Список из файла in.txt был считан\n\n";
			Cur = Head;
			if (count != 0) {
				g.open("out.txt", std::ios::app);
				if (g.is_open()) {
					g << "Изначальный список:\n";
					g.close();
				}
				res = Out(g, &Cur, count);
				if (res == 1) {
					std::cout << " Функция int Out выполнена\n Изначальный список выведен в out.txt\n";
				}
				else {
					Error(g, res);
				}
			}
			while (res != 20) {
				res = Ask();

				if (res == 1) {
					Cur = Head;
					res = AddLast(g, &Cur, count);
					if (res != 1) {
						Error(g, res);
						break;
					}
					else {
						Cur = Head;
						count++;
						std::cout << "\n Функция int AddLast выполнена\n Введенное число добавлено в конец списка\n";
						res = Out(g, &Cur, count);
					}
					if (res != 1) {
						Error(g, res);
						break;
					}
					else {
						std::cout << "\n Функция int Out выполнена\n Обновленный список выведен в out.txt\n";
					}
				}

				else if (res == 2) {
					res = AddFirst(g, &Head, count);
					if (res != 1) {
						Error(g, res);
						break;
					}
					else {
						Cur = Head;
						count++;
						std::cout << "\n Функция int AddFirst выполнена\n Введенное число добавлено в начало списка\n";
						res = Out(g, &Cur, count);
						if (res != 1) {
							Error(g, res);
							break;
						}
						std::cout << "\n Функция int Out выполнена\n Обновленный список выведен в out.txt\n";
					}
				}

				else if (res == 3) {
					Cur = Head;
					if (count > 0) {
						res = DelLast(g, &Cur);
						if (res != 1) {
							Error(g, res);
							break;
						}
						else {
							count--;
							if (count == 0) {
								Head = Cur;
							}
							else {
								Cur = Head;
							}
							std::cout << "\n Функция int DelLast выполнена\n Последний элемент удален из списка\n";
							res = Out(g, &Cur, count);
							if (res != 1) {
								Error(g, res);
								break;
							}
							std::cout << "\n Функция int Out выполнена\n Обновленный список выведен в out.txt\n";
						}
					}
					else {
						std::cout << "\n Список пуст, невозможно удалить элемент\n";
					}
				}


				else if (res == 4) {
					Cur = Head;
					if (count > 0) {
						res = DelFirst(g, &Cur);
						if (res != 1) {
							Error(g, res);
							break;
						}
						else {
							count--;
							Head = Cur;
							std::cout << "\n Функция int DelFirst выполнена\n Первый элемент удален из списка\n";
							res = Out(g, &Cur, count);
							if (res != 1) {
								Error(g, res);
								break;
							}
							std::cout << "\n Функция int Out выполнена\n Обновленный список выведен в out.txt\n";
						}
					}
					else {
						std::cout << "\n Список пуст, невозможно удалить элемент\n";
					}
				}



				else if (res == 5) {
					Cur = Head;
					res = PutIndex(g, &Cur, count);
					if (res == 2) {
						Error(g, res);
						break;
					}
					else {
						count++;
						if (res == 1) {
							Cur = Head;
						}
						else {
							Head = Cur;
						}
						std::cout << "\n Функция int PutIndex выполнена\n Элемент добавлен по указанному индексу\n";
						res = Out(g, &Cur, count);
						if (res != 1) {
							Error(g, res);
							break;
						}
						std::cout << "\n Функция int Out выполнена\n Обновленный список выведен в out.txt\n";
					}
				}



				else if (res == 6) {
					Cur = Head;
					GetIndex(&Cur, count);
					Cur = Head;
					std::cout << "\n Функция int GetIndex выполнена\n";
				}



				else if (res == 7) {
					Cur = Head;
					if (count > 0) {
						res = DelIndex(g, &Cur, count);
						if (res == 2) {
							Error(g, res);
							break;
						}
						else {
							count--;
							if (res == 1) {
								Cur = Head;
							}
							else {
								Head = Cur;
							}
							std::cout << "\n Функция int DelIndex выполнена\n Элемент по указанному индексу удален из списка\n";
							res = Out(g, &Cur, count);
							if (res != 1) {
								Error(g, res);
								break;
							}
							std::cout << "\n Функция int Out выполнена\n Обновленный список выведен в out.txt\n";
						}
					}
					else {
						std::cout << "\n Список пуст, невозможно удалить элемент\n";
					}
				}



				else if (res == 8) {
					std::cout << "\n Размер списка равен " << count << "\n";
				}



				else if (res == 9) {
					Cur = Head;
					if (count > 0) {
						DelAll(&Cur);
						count = 0;
						Head = Cur;
						std::cout << "\n Функция int DelAll выполнена\n Все элементы списка удалены\n";
						res = Out(g, &Cur, count);
					}
					else {
						std::cout << "\n Список пуст, невозможно удалить элементы\n";
					}
				}



				else if (res == 10) {
					Cur = Head;
					if (count > 0) {
						res = ChangeIndex(g, &Cur, count);
						if (res != 1) {
							Error(g, res);
							break;
						}
						else {
							Cur = Head;
							std::cout << "\n Функция int ChangeIndex выполнена\n Элемент по указанному индексу изменен на переданный\n";
							res = Out(g, &Cur, count);
							if (res != 1) {
								Error(g, res);
								break;
							}
							std::cout << "\n Функция int Out выполнена\n Обновленный список выведен в out.txt\n";
						}
					}
					else {
						std::cout << "\n Список пуст, элементы отсутствуют\n";
					}
				}




				else if (res == 11) {
					if (count == 0) {
						std::cout << "\n Список пуст\n";
					}
					else {
						std::cout << "\n Список не является пустым\n";
					}
				}




				else if (res == 12) {
					if (count > 0) {
						res = Rotate(g, &Head, count);
						if (res != 1) {
							Error(g, res);
							break;
						}
						else {
							std::cout << "\n Функция int Rotate выполнена\n Порядок элементов в списке изменён на обратный\n";
							Cur = Head;
							res = Out(g, &Cur, count);
							if (res != 1) {
								Error(g, res);
								break;
							}
							std::cout << "\n Функция int Out выполнена\n Обновленный список выведен в out.txt\n";
						}
					}
					else {
						std::cout << "\n Список пуст, элементы отсутствуют\n";
					}
				}




				else if (res >= 13 && res <= 18) {
					tmp = res;
					f.open("in2.txt", std::ios::in);
					Cur2 = Head2;
					count2 = 0;
					res = Read(f, &count2, &Cur2);
					if (res == 1) {
						f.close();
						std::cout << "\n Функция int Read выполнена\n Список из файла in2.txt был считан\n\n";
						Cur2 = Head2;
						if (count2 != 0) {
							g.open("out.txt", std::ios::app);
							if (g.is_open()) {
								g << "\n\nИзначальный список из in2.txt:\n";
								g.close();
							}
							res = Out(g, &Cur2, count2);
							if (res == 1) {
								std::cout << " Функция int Out выполнена\n Изначальный список из in2.txt выведен в out.txt\n";
							}
							else {
								Error(g, res);
								break;
							}
						}
					}
					else {
						Error(g, res);
						break;
					}
					res = tmp;


					if (res == 13) {
						if (count2 != 0) {
							Cur = Head;
							Cur2 = Head2;
							res = PutListIndex(g, &Cur, count, &Cur2);
							if (res == 2) {
								Error(g, res);
								break;
							}
							else {
								std::cout << "\n Функция int PutListIndex выполнена\n Список из in2.txt был вставлен в список из in.txt начиная с выбранного индекса\n";
								if (res == 1) {
									Cur = Head;
								}
								else {
									Head = Cur;
								}
								count = count + count2;
								Cur2 = Head2;
								DelAll(&Cur2);
								count2 = 0;
								Head2 = Cur2;
								res = Out(g, &Cur, count);
								if (res != 1) {
									Error(g, res);
									break;
								}
								std::cout << "\n Функция int Out выполнена\n Обновленный список выведен в out.txt\n";
							}
						}
						else {
							std::cout << "\n Второй список пуст\n";
						}
					}



					else if (res == 14) {
						if (count2 != 0) {
							Cur = Head;
							Cur2 = Head2;
							res = PutListEnd(g, &Cur, &Cur2);
							if (res == 2) {
								Error(g, res);
								break;
							}
							else {
								std::cout << "\n Функция int PutListEnd выполнена\n Список из in2.txt был вставлен в конец списка in.txt\n";
								Cur = Head;						
								count = count + count2;
								Cur2 = Head2;
								DelAll(&Cur2);
								count2 = 0;
								Head2 = Cur2;
								res = Out(g, &Cur, count);
								if (res != 1) {
									Error(g, res);
									break;
								}
								std::cout << "\n Функция int Out выполнена\n Обновленный список выведен в out.txt\n";
							}
						}
						else {
							std::cout << "\n Второй список пуст\n";
						}
					}

					else if (res ==15){
						if (count2 != 0) {
							Cur = Head;
							Cur2 = Head2;
							res = PutListBeg(g, &Cur, &Cur2);
							if (res == 2) {
								Error(g, res);
								break;
							}
							else {
								std::cout << "\n Функция int PutListEnd выполнена\n Список из in2.txt был вставлен в конец списка in.txt\n";
								Head = Cur;
								count = count + count2;
								Cur2 = Head2;
								DelAll(&Cur2);
								count2 = 0;
								Head2 = Cur2;
								res = Out(g, &Cur, count);
								if (res != 1) {
									Error(g, res);
									break;
								}
								std::cout << "\n Функция int Out выполнена\n Обновленный список выведен в out.txt\n";
							}
						}
						else {
							std::cout << "\n Второй список пуст\n";
						}
					}



					else if (res == 16) {
						if (count2 != 0) {
							Cur = Head;
							Cur2 = Head2;
							res = ListFind(&Cur, &Head2);							
							std::cout << "\n Функция int ListFind выполнена\n";
							if (res == 1) {
								std::cout << "\n Список из in2.txt содержится в списке in.txt\n";
							}
							else {
								std::cout << "\n Список из in2.txt не содержится в списке in.txt\n";
							}
							Cur = Head;
							Cur2 = Head2;
							DelAll(&Cur2);
							count2 = 0;
							Head2 = Cur2;						
						}
						else {
							std::cout << "\n Второй список не содержится в первом, так как он пуст\n";
						}
					}

					else if (res == 17) {
						if (count2 != 0) {
							Cur = Head;
							Cur2 = Head2;
							res = ListFindFirst(&Cur, &Head2, &tmp);
							std::cout << "\n Функция int ListFindFirst выполнена\n";
							if (res == 1) {
								std::cout << "\n Список из in2.txt содержится в списке in.txt\n Его первое вхождение по индексу " << tmp << "\n";
							}
							else {
								std::cout << "\n Список из in2.txt не содержится в списке in.txt\n";
							}
							Cur = Head;
							Cur2 = Head2;
							DelAll(&Cur2);
							count2 = 0;
							Head2 = Cur2;
						}
						else {
							std::cout << "\n Второй список не содержится в первом, так как он пуст\n";
						}
					}

					else if (res == 18) {
						if (count2 != 0) {
							Cur = Head;
							Cur2 = Head2;
							res = ListFindLast(&Cur, &Head2, &tmp);
							std::cout << "\n Функция int ListFindLast выполнена\n";
							if (res == 1) {
								std::cout << "\n Список из in2.txt содержится в списке in.txt\n Его последнее вхождение по индексу " << tmp << "\n";
							}
							else {
								std::cout << "\n Список из in2.txt не содержится в списке in.txt\n";
							}
							Cur = Head;
							Cur2 = Head2;
							DelAll(&Cur2);
							count2 = 0;
							Head2 = Cur2;
						}
						else {
							std::cout << "\n Второй список не содержится в первом, так как он пуст\n";
						}
					}

				}



				else if (res == 19) {
					Cur = Head;
					if (count > 1) {
						res = TradeIndex(g, &Head, count);
						if (res != 1) {
							Error(g, res);
							break;
						}
						else {
							Cur = Head;
							std::cout << "\n Функция int TradeIndex выполнена\n Произошел обмен элементов на указанных индексах\n";
							res = Out(g, &Cur, count);
							if (res != 1) {
								Error(g, res);
								break;
							}
							std::cout << "\n Функция int Out выполнена\n Обновленный список выведен в out.txt\n";
						}
					}
					else {
						if (count == 1) {
							std::cout << "\n Список состоит только из одного элемента\n";
						}						
						else if (count == 0) {
							std::cout << "\n Список пуст, элементы отсутствуют\n";
						}
					}
				}




				else if (res == 20) {
					std::cout << "\n Завершение программы\n";
					}

				else {
						std::cout << "\n Неверный номер функции\n";
						}
			}
		}
		else {
			Error(g, res);
		}
	}
	else {
		std::cout << " Файл out.txt не открыт\n Программа Завершает работу\n";
	}			
}


