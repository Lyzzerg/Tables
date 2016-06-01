#pragma once
#include "TTable.h"
#include <string>
using namespace std;

class THashTable : public TTable {
protected:
	int MaxSize, Step, Current, Free;
	TRecord* pRec;
public:
	THashTable(int _MaxSize = 100, int _Step = 10) {
		MaxSize = _MaxSize;
		Step = _Step;
		pRec = new TRecord[MaxSize];
		Current = -1;
		Free = 0;
		for (int i = 0; i < MaxSize; i++)
			pRec[i].SetKey("");
	}

	~THashTable() {
		delete[] pRec;
	}

	int HashFunc(TKey _key) {
		int Sum = 0;
		for (int i = 0; i < _key.length(); i++)
			Sum += (int)(_key[i])*(_key.length() - i);
		return (Sum % MaxSize);
	}

	bool IsFull() {
		return (DataCount == MaxSize);
	}

	bool Find(TKey _KEY) {
		int tmp = -1;
		Current = HashFunc(_KEY);
		for (int i = 0; i<MaxSize; i++) {
			Efficiency++;
			if (pRec[Current].GetKey() == "") {
				if (tmp != -1)
					Current = tmp;
				return false;
			}
			else {
				if ((pRec[Current].GetKey() == "***") && (tmp == -1))
					tmp = Current;
				else {
					if (pRec[Current].GetKey() == _KEY)
						return true;
				}
			}
			Current = ((Current + Step) % MaxSize);// Делаем шаг
		}
	}

	TRecord GetCurrentRecord() {
		return pRec[Current];
	}

	void InsertRecord(const TRecord& _REC) {
		if (!IsFull()) {
			if (!Find(_REC.GetKey())) {
				pRec[Current] = _REC;
				DataCount++;
			}
			else
			{
				pRec[Current].SetValue(pRec[Current].GetValue() + 1);
			}
		}
	}

	void DeleteRecord(const TKey& _KEY)
	{
		if (!IsEmpty()) {
			if (Find(_KEY)) {
				pRec[Current].SetKey("***");
				DataCount--;
			}
		}
	}

	void GoNext()
	{
		Free++;
		int i = 0;
		for (i = (Current + 1); i < MaxSize; i++) {
			if (((pRec[i].GetKey()) != "") && ((pRec[i].GetKey()) != "***")) {
				Current = i;
				break;
			}
		}
		if (i == MaxSize)
			Current = i;
	}

	void Reset() {
		Free = 0;
		for (int i = 0; i < MaxSize; i++) {
			if (((pRec[i].GetKey()) != "") && ((pRec[i].GetKey()) != "***")) {
				Current = i;
				break;
			}
		}

	}

	bool IsEnd() {
		return Current == MaxSize;
	}
};