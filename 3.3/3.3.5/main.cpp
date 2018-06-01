#include <iostream>
#include <stdlib.h>
#include <math.h>
#define PCS 1e-8
using namespace std;

//开n次方算法
double sqr(double x,unsigned n){

    double lower=0,higher=x;
    double value=(lower+higher)/2;
    if(n==1) goto end;
    //利用二分法求解
    while(pow(value,n)-x>PCS||pow(value,n)-x<-PCS){
        if(pow(value,n)-x>0) higher=value ;
        else lower=value;
        value=(higher+lower)/2;
    }
    return value;
    end:
    return x;
}
void cal_1()
{
    char op;
    double a=0,b=0;
    cout<<"pealse input arithmetic expression( eg: 4+6 )"<<endl;
    cin>>a>>op>>b;
    while(a!=0&&b!=0&&op!='0')
    {
        switch(op)      //ÅÐ¶ÏÔËËã·û
        {
            case'+': {cout<<a<<op<<b<<'='<<a+b; break;}
            case'-': {cout<<a<<op<<b<<'='<<a-b; break;}
            case'*': {cout<<a<<op<<b<<'='<<a*b; break;}
            case'/': {cout<<a<<op<<b<<'='<<a/b; break;}
        }

        cout<<"\n\nkeep input other arithmetic(input:0 0 0 to exit)"<<endl;
        cin>>a>>op>>b;
        system("cls");      //ÇåÆÁ¼ÌÐø¼ÆËã

    }
}
void cal_2()
{
    char op;
    double a=0,b=0;
    cout<<"pealse input ( eg: 2^3  or 2|3 )"<<endl;
    cin>>a>>op>>b;
    while(a!=0&&b!=0&&op!='0')
    {
        switch(op)      //ÅÐ¶ÏÔËËã·û
        {
            case'^': {cout<<a<<op<<b<<'='<<pow(a,b); break;}
            case'|': {cout<<a<<"开"<<b<<"次方="<<sqr(a,b); break;}

        }

        cout<<"\n\nkeep input other arithmetic(input:0 0 0 to exit)"<<endl;
        cin>>a>>op>>b;
        system("cls");      //ÇåÆÁ¼ÌÐø¼ÆËã

    }
}
int main()
{

    return 0;
}