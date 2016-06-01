#include "SortTable.h"

bool TSortTable::Find(TKey key)
{
	bool flag = false;
	int pos, left = 0, right = DataCount - 1;
	while (left <= right)
	{
		Eff++;
		pos = (right + left) / 2;
		if (pRec[pos].GetKey() == key)
		{
			right = pos;
			left = pos + 1;
			flag = true;
		}
		if (pRec[pos].GetKey() < key)
			left = pos + 1;
		else
			right = pos - 1;
	}
	//if (right < 0 || pRec[pos].GetKey() != key)
		right++;
	curr = right;
	return flag;
}

void TSortTable::Insert(TRecord rec)
{
	if (IsFull()) return;
	if (!Find(rec.GetKey()))
	{
		for (int pos = DataCount; pos > curr; pos--)
		{
			pRec[pos] = pRec[pos - 1];
			Eff++;
		}
		pRec[curr] = rec;
		DataCount++;
	}
}

void TSortTable::Delete(TKey key)
{
	if (IsEmpty()) return;
	if (Find(key))
	{
		/*if (pRec[curr].GetKey()!=key)
			curr++;*/
		for (int pos = curr; pos < DataCount - 1; pos++)
		{
			pRec[pos] = pRec[pos + 1];
			Eff++;
		}
		DataCount--;
	}
}

void TSortTable::quickSort(int left, int right){
	TRecord tmp = pRec[left + (right - left) / 2];
	int i = left;
	int j = right;
	while (i <= j){
		while (pRec[i] < tmp) i++;
		while (pRec[j] > tmp) j--;
		if (i <= j){
			swap(pRec[i], pRec[j]);
			i++;
			j--;
		}
	}
	if (i < right)
		quickSort(i, right);
	if (left < j)
		quickSort(left, j);
}

TSortTable::TSortTable(TScanTable sTable) : TArrayTable(0) {
	int i = 0;
	pRec = new TRecord[sTable.GetDataCount()];
	for (sTable.Reset(); !sTable.IsEnd(); sTable.GoNext()){
		pRec[i] = sTable.GetCurr();
		i++;
	}
	DataCount = i;
	quickSort(0, DataCount - 1);
}