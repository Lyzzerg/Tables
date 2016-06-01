#include "ScanTable.h"

bool TScanTable::Find(TKey _key){
	for (Reset(); !IsEnd(); GoNext()){
		Eff++;
		if (pRec[curr].GetKey() == _key)
			return true;
	}
	return false;
}

void TScanTable::Insert(TRecord rec){
	if (IsFull())
		return;
	if (!Find(rec.GetKey())){
		pRec[curr] = rec;
		Eff++;
		DataCount++;
	}
}

void TScanTable::Delete(TKey _key){
	if (IsEmpty())
		return;
	if (Find(_key)){
		pRec[curr] = pRec[DataCount - 1];
		DataCount--;
		Eff++;
	}
}