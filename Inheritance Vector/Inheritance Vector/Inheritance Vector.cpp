#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "1.h"

using namespace std;

int main()
{
	CVector1 x1(3);
	CVector2 x2(3);
	cin >> x1;
	cin >> x2;
	double p = x1 ^ x2;
	x1.output();
	cout << p << endl;;
	return 0;
}