#pragma once
#include "TTable.h"


class TArrayTable:public TTable {
protected:
	int MaxSize;
	TRecord* Array;
	int CurrentPosition;
public:


	TArrayTable(int _SIZE) {
		Array = new TRecord[_SIZE];
		MaxSize = _SIZE;
		DataCount = 0;
	}
	~TArrayTable() {
		delete[] Array;
	}

	bool IsFull() {
		return (MaxSize == DataCount);
	}

	TRecord GetCurrentRecord() {
		return (Array[CurrentPosition]);
	}

	void Reset() {
		CurrentPosition = 0;
		return;
	}

	bool IsEnd() {
		return (CurrentPosition == DataCount);
	}

	void GoNext() {
		CurrentPosition++;
		return;
	}
};

