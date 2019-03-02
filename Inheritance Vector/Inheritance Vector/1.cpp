#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stdio.h>
#include "1.h"

using namespace std;
#pragma warning (disable : 4996)


CVector1::CVector1(int len)
{
	if (len == 0)
	{
		arr = new double[3];
		memset(arr, 0, sizeof(double)* 3);
		k = 3;
	}
	else
	{
		arr = new double[len];
		memset(arr, 0, sizeof(double)*len);
		k = len;
	}
		
}
/*{
    if(!len) SetZero();
    else
    {
		len = 4;
		k=4;
		arr=new double[len];
		for(int i=0; i<k; i++) arr[i]=0;
    }
}*/

CVector2::CVector2(int len)
{
	if (len == 0)
	{
		arr = new double[3];
		memset(arr, 0, sizeof(double)* 3);
		k = 3;
	}
	else
	{
		arr = new double[len];
		memset(arr, 0, sizeof(double)*len);
		k = len;
	}
}

void CVector::SetZero(){memset(this,0,sizeof(*this));}

void CVector::CopyOnly(const CVector &b)
{
    k=0; arr=NULL;
    if(b.k>0)
    {
		arr=new double[k=b.k];
		memcpy(arr, b.arr, k*sizeof(double));
    }
}

CVector1 operator+(const CVector &a, const CVector&b)
{
	CVector1 res;
	int i = 0;
	for (; i < a.k; i++)
	{
		res.arr[i] = a.arr[i] + b.arr[i];
	}
	return res;
}

CVector &CVector::operator=(const CVector &b)
{
	try
	{
		if(k!=b.k) throw("dimension");
		if(this!=&b) {Clean(); CopyOnly(b);}
		return *this;
	}catch(const char *s){cout << "error: " << s << endl; exit(3);}
}

double CVector::operator^(const CVector &b)
{
	try
	{
		if(k!=b.k) throw("dimension");
		double l=0;
		for(int i=0; i<b.k; i++) l+=arr[i]*b.arr[i];
		return l;
	}catch(const char *s){cout << "error: " << s << endl; exit(4);}
}

ostream &operator<<(ostream &cc, CVector &b)
{
	for(int i=0; i<b.k; i++) cc << b.arr[i]<< " ";
	cc << endl;
	return cc;
}

istream &operator>>(istream &cc, CVector &b)
{
	cout << "Enter vector coordinates: " <<  endl;
	double x;
	int i = 0;
	for (; i < b.k; i++)
	{
		cin >> x;
		b.arr[i] = x;
	}
	if(i<b.k) throw('>');
	return cc;
}

void CVector::resize(int n)
{

	double *pm;
	int i;
	pm = new double[n];
	for (i = 0; i < k; i++)
		pm[i] = arr[i];
	k = n;
	delete[] arr;
	arr = pm;
	for (; i < k; i++) arr[i] = 0;
}

CVector *CVector::create(int type, vector<double> x)
{
	CVector *t;
	int i;
	if (type == 1)
	{
		t = new CVector1;
		t->resize(x.size() - 1);
		for (i = 1; i < x.size(); i++)
		{
			t->arr[i-1] = x[i];
		}	
		return t;
	}
	else
	{
		t = new CVector2;
		t->resize(x.size() - 1);
		for (i = 1; i < x.size(); i++)
			t->arr[i-1] = x[i];
		return t;
	}
	
}
