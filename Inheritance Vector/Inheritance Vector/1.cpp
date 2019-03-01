#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "1.h"

using namespace std;
#pragma warning (disable : 4996)


CVector1::CVector1(int len)
{
    if(!len) SetZero();
    else
    {
		k=len;
		arr=new double[len];
		for(int i=0; i<k; i++) arr[i]=0;
    }
}

CVector2::CVector2(int len)
{
	if (!len) SetZero();
	else
	{
		k = len;
		arr = new double[len];
		for (int i = 0; i<k; i++) arr[i] = 0;
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

/*CVector CVector::operator+(const CVector &b)
{
	try
	{
		if(k!=b.k) throw("dimension");
		CVector c(b.k);
		for(int i=0; i<b.k; i++) c.arr[i]=arr[i]+b.arr[i];
		return c;
	}catch(const char *s){cout << "error: " << s << endl; exit(1);}
}

CVector CVector::operator-(const CVector &b)
{
	try
	{
		if(k!=b.k) throw("dimension");
		CVector c(b.k);
		for(int i=0; i<b.k; i++) c.arr[i]=arr[i]-b.arr[i];
		return c;
	}catch(const char *s){cout << "error: " << s << endl; exit(2);}
}
*/
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
	
	/*while(sscanf(s,"%lf",&x)==1)
	{
		i++; 
		cout << "check" << endl;
		/*if(i>b.k) 
		{
			throw('>');break;f=1;
		} 
		b.n[i]=x;
	}*/
	for (; i < b.k; i++)
	{
		cin >> x;
		b.arr[i] = x;
	}
	if(i<b.k) throw('>');
	return cc;
}


