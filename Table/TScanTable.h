#pragma once
#include "TArrayTable.h"
class TScanTable : public TArrayTable {
public:
	TScanTable(int _SIZE=256) : TArrayTable(_SIZE) {};
	~TScanTable() {};

	bool Find(TKey _KEY) {
		for (Reset(); !IsEnd(); GoNext())
		{
			Efficiency++;
			if (_KEY == Array[CurrentPosition].GetKey())
				return true;
		}
		return false;
	}

	void InsertRecord(const TRecord& _REC) {
		if (!IsFull()) {
			if (!Find(_REC.GetKey())) {
				TRecord tmp(_REC);
				tmp.SetValue(1);
				Array[CurrentPosition] = tmp;
				Efficiency++;
				DataCount++;
			}
			else {
				Array[CurrentPosition].SetValue(Array[CurrentPosition].GetValue() + 1);
			}
		}
		else {
			return;
		}
	}

	void DeleteRecord(const TKey& _KEY) {
		if (!IsEmpty()) {
			if (Find(_KEY)) {
				Array[CurrentPosition] = Array[DataCount - 1];
				DataCount--;
				Efficiency++;
			}
			else return;
		}
		else {
			//обработка
		}
	}
};

