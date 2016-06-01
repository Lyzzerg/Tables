#include "ScanTable.h"
#include "SortTable.h"
#include "Hashtable.h"
#include "TreeTable.h"

void main(){
	int command;
	for (;;){
		cout <<"SELECT TABLE:"<<endl<<endl;
		cout <<"1 - Scan"<<endl;
		cout << "2 - Sort" << endl;
		cout << "3 - Hash" << endl;
		cout << "4 - Tree" << endl<<endl;
		cout <<"Enter the command: ";
		cin>> command;
		switch (command){
		case 0:
				system("cls");
				break;
		case 1:{
				   system("cls");
				   TScanTable table(200);
				   bool flag = true;
				   while (flag){
					   cout << "0 - clrscr" << endl;
					   cout << "1 - Find record" << endl;
					   cout << "2 - Delete record" << endl;
					   cout << "3 - Insert record" << endl;
					   cout << "4 - Print table" << endl;
					   cout << "5 - Print Efficiency" << endl;
					   cout << "6 - Come back" << endl;
					   cout << "7 - Complete the table" << endl;
					   cout << "Enter the command: ";
					   cin >> command;
					   switch (command){
					   case 0:
						   system("cls");
						   break;
					   case 1:{
								  table.ResetEff();
								  cout << "Enter the key: ";
								  TKey key;
								  cin >> key;
								  if (table.Find(key))
								  {
									  cout << endl << endl << "DONE!" << endl << endl;
									  cout << table.GetCurr();
									  cout << endl << "Efficiency:" << endl;
									  cout << table.GetEff() << endl;
									  cout << endl << endl;
								  }
								  else
									  cout << endl << endl << "Not found" << endl << endl;
								  break;
					   }
					   case 2:{
								  cout << "Enter the key: ";
								  TKey key;
								  cin >> key;
								  if (table.Find(key))
								  {
									  table.ResetEff();
									  table.Delete(key);
									  cout << "Record deleted" << endl;
									  cout << endl << "Efficiency:" << endl;
									  cout << table.GetEff() << endl;
								  }
								  else
									  cout << endl << endl << "Record not found" << endl << endl;
								  break;
					   }
					   case 3:{
								  TKey key;
								  TValue val;
								  cout << "Enter the key: ";
								  cin >> key;
								  cout << "Enter the value: ";
								  cin >> val;
								  TRecord rec(key, val);
								  table.ResetEff();
								  table.Insert(rec);
								  cout << endl << endl << "Record inserted" << endl << endl;
								  break;
					   }
					   case 4:
						   table.ResetEff();
						   if (table.IsEmpty())
							   cout << "Table is empty" << endl;
						   else
							   table.Print();
								
						   break;
					   case 5:
						   cout << endl << "Efficiency:" << endl;
						   cout << table.GetEff() << endl;
						   table.ResetEff();
						   break;
					   case 6:
						   flag = false;
						   system("cls");
						   break;
					   case 7:
						   for (int i = 0; i < (table.GetMaxSize() / 4) * 3; i++)
						   {
							   TKey key;
							   TValue val;
							   TRecord rec;
							   key = "";
							   val = "";
							   int j = 0;
							   while (j < 2)
							   {
								   key += (rand() % 10 + '0');
								   val += (rand() % 10 + '0');
								   j++;
							   }
							   rec.SetKey(key);
							   rec.SetValue(val);
							   table.Insert(rec);
						   }
						   table.ResetEff();
						   break;
					   }
				   }
				   break;
		}
		case 2:{
				   system("cls");
				   TSortTable table(200);
				   bool flag = true;
				   while (flag){
					   cout << "0 - clrscr" << endl;
					   cout << "1 - Find record" << endl;
					   cout << "2 - Delete record" << endl;
					   cout << "3 - Insert record" << endl;
					   cout << "4 - Print table" << endl;
					   cout << "5 - Print Efficiency" << endl;
					   cout << "6 - Come back" << endl;
					   cout << "7 - Complete the table" << endl;
					   cout << "Enter the command: ";
					   cin >> command;
					   switch (command){
					   case 0:
						   system("cls");
						   break;
					   case 1:{
								  table.ResetEff();
								  cout << "Enter the key: ";
								  TKey key;
								  cin >> key;
								  if (table.Find(key)){
									  cout << endl << endl << "DONE!" << endl << endl;
									  cout << table.GetCurr();
									  cout << endl << "Efficiency:" << endl;
									  cout << table.GetEff() << endl;
									  cout << endl << endl;
								  }
								  else
									  cout << endl << endl << "Not found" << endl << endl;
								  break;
					   }
					   case 2:{
								  cout << "Enter the key: ";
								  TKey key;
								  cin >> key;
								  if (table.Find(key))
								  {
									  table.ResetEff();
									  table.Delete(key);
									  cout << "Record deleted" << endl;
									  cout << endl << "Efficiency:" << endl;
									  cout << table.GetEff() << endl;
								  }
								  else
									  cout << endl << endl << "Record not found" << endl << endl;
								  break;
					   }
					   case 3:{
								  TKey key;
								  TValue val;
								  cout << "Enter the key: ";
								  cin >> key;
								  cout << "Enter the value: ";
								  cin >> val;
								  TRecord rec(key, val);
								  table.ResetEff();
								  table.Insert(rec);
								  cout << endl << endl << "Record inserted" << endl << endl;
								  break;
					   }
					   case 4:
						   if (table.IsEmpty())
							   cout << "Table is empty" << endl;
						   else
							   table.Print();
						   break;
					   case 5:
						   cout << endl << "Efficiency:" << endl;
						   cout << table.GetEff() << endl;
						   table.ResetEff();
						   break;
					   case 6:
						   flag = false;
						   system("cls");
						   break;
					   case 7:
						   for (int i = 0; i < (table.GetMaxSize() / 4) * 3; i++)
						   {
							   TKey key;
							   TValue val;
							   TRecord rec;
							   key = "";
							   val = "";
							   int j = 0;
							   while (j < 2)
							   {
								   key += (rand() % 10 + '0');
								   val += (rand() % 10 + '0');
								   j++;
							   }
							   rec.SetKey(key);
							   rec.SetValue(val);
							   table.Insert(rec);
							   table.ResetEff();
						   }
					   }
				   }
				   break;
		}
		case 3:{
				   system("cls");
				   THashTable table(200,17);
				   bool flag = true;
				   while (flag){
					   cout << "0 - clrscr" << endl;
					   cout << "1 - Find record" << endl;
					   cout << "2 - Delete record" << endl;
					   cout << "3 - Insert record" << endl;
					   cout << "4 - Print table" << endl;
					   cout << "5 - Print Efficiency" << endl;
					   cout << "6 - Come back" << endl;
					   cout << "7 - Complete the table" << endl;
					   cout << "Enter the command: ";
					   cin >> command;
					   cout << endl;
					   switch (command){
					   case 0:
						   system("cls");
						   break;
					   case 1:{
								  table.ResetEff();
								  cout << "Enter the key: ";
								  TKey key;
								  cin >> key;
								  if (table.Find(key)){
									  cout << endl << endl << "DONE!" << endl << endl;
									  cout << table.GetCurr();
									  cout << endl << "Efficiency:" << endl;
									  cout << table.GetEff() << endl;
									  cout << endl << endl;
								  }
								  else
									  cout << endl << endl << "Record not found" << endl << endl;
								  break;
					   }
					   case 2:{
								  cout << "Enter the key: ";
								  TKey key;
								  cin >> key;
								  if (table.Find(key))
								  {
									  table.ResetEff();
									  table.Delete(key);
									  cout << "Record deleted" << endl;
									  cout << "Efficiency: " << table.GetEff() << endl << endl;
								  }
								  else
									  cout << endl << endl << "Record not found" << endl << endl;
								  break;
					   }
					   case 3:{
								  TKey key;
								  TValue val;
								  cout << "Enter the key: ";
								  cin >> key;
								  cout << "Enter the value: ";
								  cin >> val;
								  TRecord rec(key, val);
								  table.ResetEff();
								  table.Insert(rec);
								  cout << endl << endl << "Record inserted" << endl << endl;
								  break;
					   }
					   case 4:
						   if (table.IsEmpty())
							   cout << "Table is empty" << endl;
						   else
							   table.Print();
						   break;
					   case 5:
						   cout << endl << "Efficiency:" << endl;
						   cout << table.GetEff() << endl;
						   table.ResetEff();
						   break;
					   case 6:
						   flag = false;
						   system("cls");
						   break;
					   case 7:
						   for (int i = 0; i < 150; i++)
						   {
							   TKey key;
							   TValue val;
							   TRecord rec;
							   key = "";
							   val = "";
							   int j = 0;
							   while (j < 3)
							   {
								   key += (rand() % 10 + '0');
								   val += (rand() % 10 + '0');
								   j++;
							   }
							   rec.SetKey(key);
							   rec.SetValue(val);
							   table.Insert(rec);
						   }
						   table.ResetEff();
						   break;
					   }
				   }
				   break;
		}
		case 4:{
				   system("cls");
				   TTreeTable table;
				   bool flag = true;
				   while (flag){
					   cout << "0 - clrscr" << endl;
					   cout << "1 - Find record" << endl;
					   cout << "2 - Delete record" << endl;
					   cout << "3 - Insert record" << endl;
					   cout << "4 - Print table" << endl;
					   cout << "5 - Print Efficiency" << endl;
					   cout << "6 - Come back" << endl;
					   cout << "7 - Complete the table" << endl;
					   cout << "Enter the command: ";
					   cin >> command;
					   switch (command){
					   case 0:
						   system("cls");
						   break;
					   case 1:{
								  table.ResetEff();
								  cout << "Enter the key: ";
								  TKey key;
								  cin >> key;
								  if (table.Find(key)){
									  cout << endl << endl << "DONE!" << endl << endl;
									  cout << table.GetCurr();
									  cout << endl << "Efficiency:" << endl;
									  cout << table.GetEff() << endl;
									  cout << endl << endl;
								  }
								  else
									  cout << endl << endl << "Not found" << endl << endl;
								  break;
					   }
					   case 2:{
								  cout << "Enter the key: ";
								  TKey key;
								  cin >> key;
								  if (table.Find(key))
								  {
									  table.ResetEff();
									  table.Delete(key);
									  cout << "Record deleted" << endl;
									  cout << endl << "Efficiency:" << endl;
									  cout << table.GetEff() << endl;
								  }
								  else
									  cout << endl << endl << "Record not found" << endl << endl;
								  break;
					   }
					   case 3:{
								  TKey key;
								  TValue val;
								  cout << "Enter the key: ";
								  cin >> key;
								  cout << "Enter the value: ";
								  cin >> val;
								  TRecord rec(key, val);
								  table.ResetEff();
								  table.Insert(rec);
								  cout << endl << endl << "Record inserted" << endl << endl;
								  break;
					   }
					   case 4:
						   if (table.IsEmpty())
							   cout << "Table is empty" << endl;
						   else
							   table.Print();
						   break;
					   case 5:
						   cout << endl << "Efficiency:" << endl;
						   cout << table.GetEff() << endl;
						   table.ResetEff();
						   break;
					   case 6:
						   flag = false;
						   system("cls");
						   break;
					   case 7:
						   for (int i = 0; i < 200; i++)
						   {
							   TKey key;
							   TValue val;
							   TRecord rec;
							   key = "";
							   val = "";
							   int j = 0;
							   while (j < 3)
							   {
								   key += (rand() % 10 + '0');
								   val += (rand() % 10 + '0');
								   j++;
							   }
							   rec.SetKey(key);
							   rec.SetValue(val);
							   table.Insert(rec);
							   table.ResetEff();
						   }
					   }
				   }
				   break;
		}
		default:
			system("cls");
			break;
		}
	}
}