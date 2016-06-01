#pragma once
#include <string>
#include <string.h>
using namespace std;

typedef string TKey;
typedef int TValue;

class TRecord
{
	TKey Key;
	TValue Value;
public:
	TRecord() {};

	TRecord(TKey _key, TValue _val) {
		Key = _key;
		Value = _val;
	};

	TRecord(const TRecord& _REC) {
		Key = _REC.GetKey();
		Value = _REC.GetValue();
	}

	~TRecord() {};

	TKey GetKey() const {
		return Key;
	}

	TValue GetValue() const {
		return Value;
	}

	void SetValue(TValue val) {
		Value = val;
	}
	
	void SetKey(TKey key) {
		Key = key;
	}
	bool operator==(const TRecord& Rec) {
		return (this->GetKey() == Rec.GetKey());
	}
	

	bool operator<(const TRecord &rec) {
		if (this->Key < rec.Key)
			return true;
		else
			return false;
	}

	bool operator>(const TRecord &rec) {
		if (this->Key > rec.Key)
			return true;
		else
			return false;
	}

};

