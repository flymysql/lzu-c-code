/*
*   3.1.5 ����+��-��*��/�ĳ���
*   ������
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
    switch(op)      //�ж������
    {
        case'+': {cout<<a<<op<<b<<'='<<a+b; break;}
        case'-': {cout<<a<<op<<b<<'='<<a-b; break;}
        case'*': {cout<<a<<op<<b<<'='<<a*b; break;}
        case'/': {cout<<a<<op<<b<<'='<<a/b; break;}
    }

    cout<<"\n\nkeep input other arithmetic(input:0 0 0 to exit)"<<endl;
    cin>>a>>op>>b;
    system("cls");      //������������

    }

    return 0;
}
