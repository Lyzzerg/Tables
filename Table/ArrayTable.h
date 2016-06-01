#include "TTable.h"
#pragma once
class TArrayTable : public TTable {
protected:
	TRecord *pRec;
	int curr;
	int MaxSize;
public:
	TArrayTable(int size)
	{
		MaxSize = size;
		pRec = new TRecord[size];
		curr = -1;
		DataCount = 0;
		Eff = 0;
	}
	~TArrayTable()
	{
		delete[] pRec;
		pRec = NULL;
	}
	virtual bool IsEmpty() { return DataCount == 0; }
	virtual bool IsFull() { return DataCount == MaxSize; }
	virtual TRecord GetCurr() { return pRec[curr]; }
	virtual void Reset() { curr = 0; }
	virtual void GoNext() { curr++; }
	virtual bool IsEnd() { return curr == DataCount; }
	virtual int GetMaxSize() { return MaxSize; }
};