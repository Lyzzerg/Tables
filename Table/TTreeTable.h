#pragma once
#include "TTreeNode.h"
#include "TTable.h"
#include <stack>
class TTreeTable:public TTable {
protected:
	TTreeNode* Root;
	TTreeNode* Current;
	TTreeNode** Place;
	std::stack<TTreeNode*> st;
	int Num;
public:
	TTreeTable() {
		Root = nullptr;
		Place = nullptr;
		Current = nullptr;
	};
	~TTreeTable() {
		//обход и удаление каждого
	};

	TRecord GetCurrentRecord() {
		return ((*Current).Rec);
	}

	void Reset() {
		Current = Root;
		//st.Clear():
		while (st.size() != 0) {
			st.pop();
		}
		//
		Num = 1;
		do {
			st.push(Current);
			Current = Current->L;
		} while (Current != nullptr);
		Current = st.top();
	}

	bool IsEnd() {
		return(Num == DataCount);
	}

	void GoNext() {
		st.pop();
		Current = Current->R;
		while (Current != nullptr) {
			st.push(Current);
			Current = Current->L;
		}
		if (!st.empty()) {
			Current = st.top();
		}
		Num++;
	}

	bool Find(TKey _KEY) {
		Place = &Root;
		while (*Place != nullptr) {
			Efficiency++;
			if ((*Place)->Rec.GetKey() == _KEY)
				return true;
			if ((*Place)->Rec.GetKey() > _KEY) {
				Place = &((*Place)->L);
			}
			else
				Place = &((*Place)->R);
		}
		return false;
	}

	void InsertRecord(const TRecord& _REC) {
		if (!Find(_REC.GetKey())) {
			(*Place) = new TTreeNode(_REC);
			DataCount++;
		}
		else {
			(*Place)->Rec.SetValue((*Place)->Rec.GetValue() + 1);
		}
		Efficiency++;
	}

	bool IsFull() {
		return false;
	}

	void DeleteRecord(const TKey& _KEY) {
		if (Find(_KEY)) {
			TTreeNode* Node = *Place;
			TTreeNode* tmp = *Place;
			TTreeNode* Max = *Place;
			if (tmp->L == nullptr) {
				*Place = tmp->R;
				delete tmp;
				DataCount--;
				return;
			}
			else
				if (tmp->R == nullptr) {
					*Place = tmp->L;
					delete tmp;
					DataCount--;
					return;
				}
				else {
					Max = Max->L;
					if (Max->R == nullptr)
						Node = Max->L;
					else {
						while (Max->R != nullptr) {
							Efficiency++;
							tmp = Max;
							Max = Max->R;
						}
						Node->Rec = Max->Rec;
						tmp->R = Max->L;
					}
				}
			delete Max;
			DataCount--;
		}
		else
			return;
	}

};

