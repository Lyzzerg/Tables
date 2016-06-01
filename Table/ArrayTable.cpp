#include "ArrayTable.h"

TArrayTable::TArrayTable(int size){
	MaxSize = size;
	pRec = new TRecord[size];
	curr = -1;
	DataCount = 0;
	Eff = 0;
}

TArrayTable::~TArrayTable(){
	delete[] pRec;
	pRec = NULL;
}

bool TArrayTable::IsEmpty(){
	return DataCount == 0;
}

bool TArrayTable::IsFull(){
	return DataCount == MaxSize;
}

TRecord TArrayTable::GetCurr(){
	return pRec[curr];
}

void TArrayTable::Reset(){
	curr = 0;
}

void TArrayTable::GoNext(){
	curr++;
}

bool TArrayTable::IsEnd(){
	return curr == DataCount;
}