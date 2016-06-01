#include "TreeTable.h"

TTreeTable::TTreeTable() : TTable()
{
	pRoot = NULL;
	pCurr = NULL;
	pRef = NULL;
}

bool TTreeTable::IsEmpty(){
	return DataCount == 0;
}

bool TTreeTable::Find(TKey _key){
	pCurr = pRoot;
	pRef = &pRoot;
	while (pCurr != NULL){
		Eff++;
		if (pCurr->rec.GetKey() == _key)
			return true;
		else if (pCurr->rec.GetKey() < _key)
			pRef = &(pCurr->pRight);
		else
			pRef = &(pCurr->pLeft);
		pCurr = *pRef;
	}
	return false;
}

void TTreeTable::Delete(TKey _key){
	if (!Find(_key))
		return;
	if (Find(_key)){
		TTreeNode *p = *pRef;
		if ((*pRef)->pLeft == NULL){
			*pRef = (*pRef)->pRight;
			Eff++;
		}
		else if ((*pRef)->pRight == NULL){
			*pRef = (*pRef)->pLeft;
			Eff++;
		}
		else{
			TTreeNode **tmp = &((*pRef)->pLeft);
			TTreeNode **q = &((*pRef)->pLeft);
			int iter = 0;
			while ((*tmp)->pRight != NULL)
			{
				if (iter > 0)
					*q = *tmp;
				*tmp = (*tmp)->pRight;
				Eff++;
				iter++;
			}
			(*pRef)->rec = (*tmp)->rec;
			p = *tmp;
			*tmp = (*tmp)->pLeft;
			*q = *tmp;
		}
		delete p;
		DataCount--;
	}
}

void TTreeTable::Insert(TRecord rec){
	if (!Find(rec.GetKey())){
		TTreeNode *tmp = new TTreeNode(rec);
		*pRef = tmp;
		DataCount++;
	}
}

void TTreeTable::Reset(){
	pCurr = pRoot;
	stack.clear();
	pos = 0;
	while (pCurr != NULL)
	{
		stack.Push(pCurr);
		pCurr = pCurr->pLeft;
	}
	pCurr = stack.Pop();
}

void TTreeTable::GoNext(){
	if (pCurr != NULL){
		pos++;
		pCurr = pCurr->pRight;
		if (pCurr != NULL){
			while (pCurr->pLeft != NULL){
				stack.Push(pCurr);
				pCurr = pCurr->pLeft;
			}
		}
		else if (!stack.IsEmpty())
			pCurr = stack.Pop();
	}
}