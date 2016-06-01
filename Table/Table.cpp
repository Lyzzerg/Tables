// Table.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "TTable.h"
#include "TScanTable.h"
#include "TSortTable.h"
#include "TTreeTable.h"
#include "TArrayTable.h"
#include "THashTable.h"

#include <fstream>
#include <iostream>
using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");
	string tmp;
	string Line;
	fstream MyFile;
	MyFile.open("example.txt", ios::out | ios::in);
	if (MyFile.is_open()) {
		while (getline(MyFile, tmp)) {
			Line += tmp;
		}
		cout << endl << Line << endl;
		TScanTable ScTable(200);
		TSortTable SrTable(200);
		TTreeTable TreeTable;
		THashTable HashTable;
		SrTable.AnalyseString(Line);
		ScTable.AnalyseString(Line);
		TreeTable.AnalyseString(Line);
		HashTable.AnalyseString(Line);
		int key_button = -1;
		while (key_button != 0) {
			system("cls");
			key_button = -1;
			cout << "1. Выбрать таблицу для демонстрации" << endl;
			cout << "2. Добавить элемент" << endl;
			cout << "3. Удалить элемент" << endl;
			cout << endl << "0. Выход" << endl;
			cin >> key_button;

			switch (key_button)
			{
			//SHOW TABLE
			case 1:
				system("cls");
				while (key_button != 0) {
					system("cls");
					cout << "1. Scan Table" << endl;
					cout << "2. Sort Table" << endl;
					cout << "3. Tree Table" << endl;
					cout << "4. Hash Table" << endl;
					cout << endl << "0. Выход" << endl;

					cin >> key_button;
					int a;
					switch (key_button)
					{
					case 1:
						cout << endl;
						ScTable.Print();
						cin >> a;
						break;
					case 2:
						cout << endl;
						SrTable.Print();
						cin >> a;
						break;
					case 3:
						cout << endl;
						TreeTable.Print();
						cin >> a;
						break;
					case 4:
						cout << endl;
						HashTable.Print();
						cin >> a;
						break;
					case 0:
						break;
					default:
						break;
					}
				}
				break;
			//InsertRecord
			case 2:
				system("cls");
				while (key_button != 0) {
					system("cls");
					cout << "1. Scan Table" << endl;
					cout << "2. Sort Table" << endl;
					cout << "3. Tree Table" << endl;
					cout << "4. Hash Table" << endl;
					cout << endl << "0. Выход" << endl;

					cin >> key_button;
					int a;
					string _key_word;
					TRecord tmpRec;
					switch (key_button)
					{
					case 1:
						cout << endl;
						cout << "Введите ключ:" << endl;
						cin >> _key_word;
						tmpRec.SetKey(_key_word);
						ScTable.InsertRecord(tmpRec);
						ScTable.Print();
						cin >> a;
						break;
					case 2:
						cout << endl;
						cout << "Введите ключ:" << endl;
						cin >> _key_word;
						tmpRec.SetKey(_key_word);
						SrTable.InsertRecord(tmpRec);
						SrTable.Print();
						cin >> a;
						break;
					case 3:
						cout << endl;
						cout << "Введите ключ:" << endl;
						cin >> _key_word;
						tmpRec.SetKey(_key_word);
						TreeTable.InsertRecord(tmpRec);
						TreeTable.Print();
						cin >> a;
						break;
					case 4:
						cout << endl;
						cout << "Введите ключ:" << endl;
						cin >> _key_word;
						tmpRec.SetKey(_key_word);
						HashTable.InsertRecord(tmpRec);
						HashTable.Print();
						cin >> a;
						break;
					case 0:
						break;
					default:
						break;
					}
				}
			//DeleteRecord
			case 3:
				system("cls");
				while (key_button != 0) {
					system("cls");
					cout << "1. Scan Table" << endl;
					cout << "2. Sort Table" << endl;
					cout << "3. Tree Table" << endl;
					cout << "4. Hash Table" << endl;
					cout << endl << "0. Выход" << endl;

					int a;
					string _key_word;
					cin >> key_button;
					switch (key_button)
					{
					case 1:
						cout << endl;
						cout << "Введите ключ:" << endl;
						cin >> _key_word;
						ScTable.DeleteRecord(_key_word);
						ScTable.Print();
						cin >> a;
						break;
					case 2:
						cout << endl;
						cout << "Введите ключ:" << endl;
						cin >> _key_word;
						SrTable.DeleteRecord(_key_word);
						SrTable.Print();
						cin >> a;
						break;
					case 3:
						cout << endl;
						cout << "Введите ключ:" << endl;
						cin >> _key_word;
						TreeTable.DeleteRecord(_key_word);
						TreeTable.Print();
						cin >> a;
						break;
					case 4:
						cout << endl;
						cout << "Введите ключ:" << endl;
						cin >> _key_word;
						HashTable.DeleteRecord(_key_word);
						HashTable.Print();
						cin >> a;
						break;
					case 0:
						break;
					default:
						break;
					}
				}
				key_button = -1;
				break;
			case 0:
				break;
			default:
				break;
			}
		}
	}
	else
		cout << "Unable to open a file" << endl;
	MyFile.close();
    return 0;
}

