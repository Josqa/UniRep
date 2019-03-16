#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stdio.h>
#include "header.h"

using namespace std;


CVector1::CVector1(int len)
{
    if (len == 0)
    {
		arr.resize(1);
    }
    else
    {
		arr.resize(len);
    }

}

CVector2::CVector2(int len)
{
	if (len == 0)
	{
		arr.resize(1);
	}
	else
	{
		arr.resize(len);
	}
}



CVector &CVector::operator=(const CVector &b)
{
    try
    {
		if (arr.size() != b.arr.size()) throw("dimension");
		if (this != &b) arr = b.arr;
        return *this;
    }catch(const char *s){cout << "error: " << s << endl; exit(3);}
}

double CVector::operator^(const CVector &b)
{
    try
    {
		if (arr.size() != b.arr.size()) throw("dimension");
        double l=0;
		for (size_t i = 0; i<b.arr.size(); i++) l += arr[i] * b.arr[i];
        return l;
    }catch(const char *s){cout << "error: " << s << endl; exit(4);}
}

ostream &operator<<(ostream &cc, CVector &b)
{
	for (size_t i = 0; i<b.arr.size(); i++) cc << b.arr[i] << " ";
    cc << endl;
    return cc;
}

istream &operator>>(istream &cc, CVector &b)
{
    cout << "Enter vector coordinates: " <<  endl;
    double x;
    int i = 0;
	for (; i < b.arr.size(); i++)
    {
        cin >> x;
        b.arr[i] = x;
    }
    return cc;
}


CVector1 operator+(const CVector &a, const CVector&b)
{
	CVector1 res(a.arr.size());
    int i = 0;
	for (; i < a.arr.size(); i++)
    {
        res.arr[i] = a.arr[i] + b.arr[i];
	}
    return res;
}

CVector *CVector::create(int type, vector<double> x)
{
    CVector *t;
    size_t i;
    if (type == 1)
    {
        t = new CVector1;
        t->arr.resize(x.size() - 1);
        for (i = 1; i < x.size(); i++)
        {
            t->arr[i-1] = x[i];
        }
        return t;
    }
    else
    {
        t = new CVector2;
		t->arr.resize(x.size() - 1);
        for (i = 1; i < x.size(); i++)
            t->arr[i-1] = x[i];
        return t;
    }

}
