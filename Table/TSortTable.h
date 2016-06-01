#pragma once
#include "TArrayTable.h"
#include "TScanTable.h"

class TSortTable: public TArrayTable {

public:
	TSortTable(int _SIZE=256) :TArrayTable(_SIZE) {};
	TSortTable(const TScanTable& SCAN) : TArrayTable(SCAN.GetDataCount()) {};
	~TSortTable() {};

	bool Find(TKey k) {
		int left = 0;
		int right = DataCount - 1;
		int M;
		while (left <= right) {
			Efficiency++;
			M = (right + left) / 2;
			if (Array[M].GetKey() == k) {
				CurrentPosition = M;
				return true;
			}
			else
				if (Array[M].GetKey() > k)
					left = M + 1;
				else
					right = M - 1;
		}
		CurrentPosition = left;
		return false;
	}
	
	void quickSort(int left, int right) {
		TRecord tmp = Array[left + (right - left) / 2];
		int i = left;
		int j = right;
		while (i <= j) {
			while (Array[i] < tmp) i++;
			while (Array[j] > tmp) j--;
			if (i <= j) {
				swap(Array[i], Array[j]);
				i++;
				j--;
			}
		}
		if (i < right)
			quickSort(i, right);
		if (left < j)
			quickSort(left, j);
	}

	TSortTable(TScanTable sTable) : TArrayTable(0) {
		int i = 0;
		Array = new TRecord[sTable.GetDataCount()];
		for (sTable.Reset(); !sTable.IsEnd(); sTable.GoNext()) {
			Array[i] = sTable.GetCurrentRecord();
			i++;
		}
		DataCount = i;
		quickSort(0, DataCount - 1);
	}

	void InsertRecord(const TRecord& _REC) {
		if (IsFull()) return;
		if (!Find(_REC.GetKey())) {
			DataCount++;
			for (int i = DataCount - 1; i > CurrentPosition; i--) {
				Array[i] = Array[i - 1];
				Efficiency++;
			}
			TRecord tmp(_REC);
			//tmp.SetValue(1);
			Array[CurrentPosition] = tmp;
			Efficiency++;
		}
		else {
			Array[CurrentPosition].SetValue(Array[CurrentPosition].GetValue() + 1);
		}
	}


	void DeleteRecord(const TKey& _KEY) {
		if (IsEmpty()) return;
		if (Find(_KEY)) {
			for (int i = CurrentPosition; i < DataCount; i++) {
				Array[i] = Array[i + 1];
				Efficiency++;
			}
			DataCount--;
		}
	}

};

