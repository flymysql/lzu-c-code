#include <iostream>
using namespace std;
int n=0;
int func(int x=10);
int main()
{
    int a,b;
    a=5;
    b=func(a);
    cout<<"\nlocal a="<<a<<"\nlocal b="<<b<<"\nglobal n="<<n<<endl;
    func();
}
int func(int x)
{
    int a=1;
    static int b=10;
    a++;
    b++;
    x++;
    n++;
    cout<<"\nlocal a="<<a<<"\nlocal b="<<b<<"\nparameter x="<<x<<endl;
    return a+b;
}