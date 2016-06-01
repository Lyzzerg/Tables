#pragma once
#include "TRecord.h"
class TTreeNode {
public:
	TRecord Rec;
	TTreeNode* L, *R;
	int Balance;

	TTreeNode() {
		L = nullptr;
		R = nullptr;
	};

	TTreeNode(const TRecord& _REC) {
		Rec = _REC;
		L = nullptr;
		R = nullptr;
	}

	TTreeNode(const TTreeNode& _NODE) {
		//��������� ����� ��� ����������� ����� ���������
		Rec = _NODE.Rec;
		Balance = _NODE.Balance;
	}
	~TTreeNode() {};//���� �� ����� �������?
};

