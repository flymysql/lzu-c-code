//
// Created by 小金 on 2018/5/27.
//
#include <iostream>
#include "func.h"
using namespace std;

double fn(int n)
{
    if(n==0)return 1;
    double all=1;
    while(n)
    {
        all=all*n;
        n--;
    }
    return all;
}
double cnr(int n,int r)
{
    double s,t;
    s=fn(n);
    t=fn(n-r)*fn(r);
    return s/t;
}

double C(int n,int r)
{
    if(r<=1)
    {
        if(r==1)return n;
        else return 1;
    }
    else return C(n,r-1)*(n-r+1)/r;
}

