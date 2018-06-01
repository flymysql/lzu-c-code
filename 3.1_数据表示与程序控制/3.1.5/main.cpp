/*
*   3.1.5 计算+、-、*、/的程序
*   刘金明
*   320160939811
*
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    char op;
    double a=0,b=0;
    cout<<"pealse intput arithmetic expression( eg: 4+6 )"<<endl;
    cin>>a>>op>>b;
    while(a!=0&&b!=0&&op!='0')
    {
    switch(op)      //判断运算符
    {
        case'+': {cout<<a<<op<<b<<'='<<a+b; break;}
        case'-': {cout<<a<<op<<b<<'='<<a-b; break;}
        case'*': {cout<<a<<op<<b<<'='<<a*b; break;}
        case'/': {cout<<a<<op<<b<<'='<<a/b; break;}
    }

    cout<<"\n\nkeep input other arithmetic(input:0 0 0 to exit)"<<endl;
    cin>>a>>op>>b;
    system("cls");      //清屏继续计算

    }

    return 0;
}
