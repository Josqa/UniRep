#pragma once
using namespace std; 

class CVector 
{ 
public:
	vector<double> arr;
	void SetZero(); 
	CVector (){};
	CVector(const CVector &b) { arr = b.arr; }
	virtual ~CVector(){}
	CVector &operator=(const CVector &b); 
	double operator^(const CVector &b); 
	friend ostream &operator<<(ostream &cc, CVector &b); 
	friend istream &operator>>(istream &cc, CVector &b); 
	virtual void output() = 0;
	static CVector *create(int type, vector<double> x);
};

class CVector1 : public CVector
{
public:
	CVector1(int l = 0);
	virtual ~CVector1(){}
	CVector1(const CVector &b) { arr = b.arr; }
	virtual void output() { int i; cout << "[ ";  for (i=0; i < arr.size(); i++) cout << arr[i] << " "; cout << "]" << endl; }
	CVector &operator=(const CVector &b) { arr = b.arr;  return *this; }
};

class CVector2 : public CVector
{
public:
	CVector2(int l = 0);
	virtual ~CVector2() {}
	virtual void output() { int i; cout << "( ";  for (i=0; i < arr.size(); i++) cout << arr[i] << " "; cout << ")" << endl; }
	CVector &operator=(const CVector &b) { arr = b.arr;  return *this; }
};

CVector1 operator+(const CVector &a, const CVector&b);
