#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <fstream>
#include "1.h"

using namespace std;
#pragma warning (disable:4996)
int main()
{
	/*CVector1 x1(3);
	CVector2 x2(3);
	cin >> x1;
	cin >> x2;
	double p = x1 ^ x2;
	x1.output();
	cout << p << endl;*/

	int i,j,l;
	double x;
	char tmp[256], *s;
	vector<vector<double> > h;
	ifstream fin("input.txt");
	FILE *f = fopen("input.txt", "r");
	while (!fin.eof())
	{
		vector<double> tm;
		fin.getline(tmp, 256);
		for (s = tmp, l = 0; sscanf(s, "%lf%n", &x, &l) == 1; s += l)
			tm.push_back(x);
		h.push_back(tm);
	}

	
	CVector **t;
	t = new CVector*[h.size()];
	for (i = 0; i < h.size(); i++)
	{
		t[i] = CVector::create(int(h[i][0]), h[i]);
	}
	for (i = 0; i < h.size(); i++) t[i]->output();



	return 0;
}