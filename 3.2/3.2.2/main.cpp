#include <iostream>
#include <stdlib.h>
using namespace std;
#include "func.h"
int main()
{
    int a=5,b=3;
    cout << "please input two num (a>b):" << endl;
    while(a!=0&&b!=0)
    {
        if(a<b||a<1)
        {
            cout<<"\n\nerr input, please input again"<<endl;
        }
        else
        {
            double m=C(a,b);
            cout<<"C("<<a<<","<<b<<")="<<m<<endl;
        }
        cout << "\nplease input two num (input 0 0 to exit):" << endl;
        cin>>a>>b;
        system("cls");
    }

    return 0;
}
