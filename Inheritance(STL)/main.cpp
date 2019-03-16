#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <fstream>
#include "header.h"

using namespace std;
#pragma warning(disable:4996)
int main()
{
    int l;
    size_t i;
    double x;
    char tmp[256], *s;
    vector<vector<double> > h;
    ifstream fin("input.txt");
    while (!fin.eof())
    {
        vector<double> tm;
        fin.getline(tmp, 256);
        for (s = tmp, l = 0; sscanf(s, "%lf%n", &x, &l) == 1; s += l)
            tm.push_back(x);
        h.push_back(tm);
    }

    cout<<"size="<<h.size()<<endl;
    CVector **t;
    t = new CVector*[h.size()];
    for (i = 0; i < h.size(); i++)
    {
        t[i] = CVector::create(int(h[i][0]), h[i]);
    }
    for (i = 0; i < h.size(); i++) t[i]->output();
    
	//cout << t[0]->k << " " << t[1]->k << " " << t[2]->k << endl;
    *t[0]=*t[1] + *t[2];
    cout<<"t[1] + t[2] = ";
    t[0] -> output();
    for(i=0;i<h.size();i++){delete t[i];}
    delete[] t;
    t=NULL;
    
    return 0;
}
