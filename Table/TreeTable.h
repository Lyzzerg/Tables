#include "TTable.h"
#include "TStack.h"
#pragma once

class TTreeNode{
public:
	TRecord rec;
	TTreeNode *pLeft, *pRight;
	TTreeNode(TRecord _rec, TTreeNode *left = NULL, TTreeNode *right = NULL){
		rec = _rec;
		pLeft = left;
		pRight = right;
	}
	~TTreeNode(){}
};

class TTreeTable :public TTable {
protected:
	TTreeNode *pRoot;
	TTreeNode *pCurr;
	TTreeNode **pRef;
	int pos;
	TStack <TTreeNode*> stack;
public:
	TTreeTable(); //+
	~TTreeTable() {} //+
	virtual bool IsEmpty() { return DataCount == 0; } //+
	virtual bool IsFull() { return false; };
	virtual bool Find(TKey _key); //+
	virtual void Delete(TKey _key); //+
	virtual void Insert(TRecord rec); //+
	virtual void Reset(); //+
	virtual void GoNext(); //+
	virtual bool IsEnd() { return (pos == DataCount); }
	virtual TRecord GetCurr() { return pCurr->rec; }
};
TTreeTable::TTreeTable() : TTable()
{
	pRoot = NULL;
	pCurr = NULL;
	pRef = NULL;
}

bool TTreeTable::Find(TKey _key) {
	pCurr = pRoot;
	pRef = &pRoot;
	while (pCurr != NULL) {
		Eff++;
		if (pCurr->rec.GetKey() == _key)
			return true;
		else if (pCurr->rec.GetKey() > _key)
			pRef = &(pCurr->pRight);
		else
			pRef = &(pCurr->pLeft);
		pCurr = *pRef;
	}
	return false;
}

void TTreeTable::Delete(TKey _key) {
	if (!Find(_key))
		return;
	else
	{
		TTreeNode *p = *pRef;
		if ((*pRef)->pLeft == NULL) {
			*pRef = (*pRef)->pRight;
			Eff++;
		}
		else if ((*pRef)->pRight == NULL) {
			*pRef = (*pRef)->pLeft;
			Eff++;
		}
		else {
			TTreeNode **tmp = &((*pRef)->pLeft);
			TTreeNode **q = &((*pRef)->pLeft);
			TTreeNode **z = tmp;
			while ((*tmp)->pRight != NULL)
			{
				z = tmp;
				*tmp = (*tmp)->pRight;
				Eff++;
			}
			(*pRef)->rec = (*tmp)->rec;
			(*z)->pRight = (*tmp)->pLeft;
			p = *tmp;
			(*pRef)->pLeft = *q;
		}
		delete p;
		DataCount--;
	}
}

void TTreeTable::Insert(TRecord rec) {
	if (!Find(rec.GetKey()))
	{
		TTreeNode *tmp = new TTreeNode(rec);
		*pRef = tmp;
		DataCount++;
	}
}

void TTreeTable::Reset() {
	pCurr = pRoot;
	stack.stclear();
	pos = 0;
	while (pCurr != NULL)
	{
		stack.push(pCurr);
		pCurr = pCurr->pLeft;
	}
	pCurr = stack.pop();
}

void TTreeTable::GoNext() {
	if (pCurr != NULL) {
		pos++;
		pCurr = pCurr->pRight;
		if (pCurr != NULL) {
			while (pCurr->pLeft != NULL) {
				stack.push(pCurr);
				pCurr = pCurr->pLeft;
			}
		}
		else if (!stack.IsEmpty())
			pCurr = stack.pop();
	}
}