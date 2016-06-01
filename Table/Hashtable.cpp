#include "Hashtable.h"

int THashTable::HashFunc(TKey _key){
	int length = _key.length();
	int result = 0;
	int k = 1;
	for (int i = 0; i < length; i++){
		result += _key[i] * k;
		k *= 2;
	}
	return result;
}

bool THashTable::Find(TKey _key){
	curr = HashFunc(_key) % MaxSize;
	free = -1;
	for (int i = 0; i < MaxSize; i++){
		Eff++;
		if (pRec[curr].GetKey() == _key)
			return true;
		if (pRec[curr].GetKey() == "&"){
			if (free == -1)
				free = curr;
		}
		if (pRec[curr].GetKey() == "")
			break;
		curr = (step + curr) % MaxSize;
	}
	if (free != -1)
		curr = free;
	return false;
}

void THashTable::Delete(TKey _key){
	if (IsEmpty())
		return;
	if (Find(_key)){
		pRec[curr].SetKey("&");
		DataCount--;
	}
}

void THashTable::Insert(TRecord rec){
	if (IsFull())
		return;
	if (!Find(rec.GetKey())){
		pRec[curr] = rec;
		DataCount++;
	}
}

THashTable::~THashTable(){
	delete[] pRec;
	pRec = NULL;
}

THashTable::THashTable(int _MaxSize, int _step){
	MaxSize = _MaxSize;
	step = _step;
	pRec = new TRecord[MaxSize];
	for (int i = 0; i < MaxSize; i++)
	{
		pRec[i].SetKey("");
		pRec[i].SetValue("");
	}
	curr = -1;
	DataCount = 0;
	Eff = 0;
}

void THashTable::Reset(){
	curr = 0;
	while ((pRec[curr].GetKey() == "&" || pRec[curr].GetKey() == "") && curr < MaxSize)
		curr++;
}

void THashTable::GoNext(){
	curr++;
	while (curr<MaxSize && (pRec[curr].GetKey() == "&" || pRec[curr].GetKey() == ""))
		curr++;
}