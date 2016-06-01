#include <iostream>
#include <string>
#pragma once
using namespace std;

typedef string TKey;
typedef string TValue;

class TRecord{
private:
	TKey key;
	TValue value;
public:
	TRecord(TKey _key = "", TValue _val = ""){
		key = _key;
		value = _val;
	}
	void SetKey(TKey _key){	key = _key;	}
	string GetKey(){ return key; }
	void SetValue(TValue _val){ value = _val; }
	string GetValue(void){ return value; }
	bool operator>(const TRecord &rec) { return key > rec.key; }
	bool operator<(const TRecord &rec) { return key < rec.key; }
	bool operator==(const TRecord &rec) { return key == rec.key; }
	friend ostream& operator<<(ostream &out, const TRecord rec){
		out << "----------|------------" << endl;
		out << rec.key << "            " << rec.value << endl;
		return out;
	}
};