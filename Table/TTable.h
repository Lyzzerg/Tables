#include "Record.h"
#pragma once
class TTable{
protected:
	int DataCount;
	int Eff;
public:
	TTable(){
		DataCount = 0;
		Eff = 0;
	}
	~TTable(){}
	int GetDataCount() const { return DataCount; }
	int GetEff() const { return Eff; }
	void ResetEff() { Eff = 0; }
	virtual bool IsEmpty() = 0;
	virtual bool IsFull() = 0;
	virtual bool Find(TKey _key) = 0;
	virtual void Delete(TKey _key) = 0;
	virtual void Insert(TRecord rec) = 0;
	virtual void Reset() = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() = 0;
	virtual TRecord GetCurr() = 0;
	void Print()
	{
		cout << endl;
		cout << "Keys:        Values:" << endl;
		for (Reset(); !IsEnd(); GoNext())
		{
			TRecord curr = GetCurr();
			cout << curr;
		}
		cout << "----------|------------"<< endl<<endl<<endl;
	}
};