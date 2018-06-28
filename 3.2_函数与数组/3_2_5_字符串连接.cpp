/*
 * 3.2.5 字符串链接
 * 刘金明  320160939811
 */

#include <iostream>
using namespace std;
#define lenth 100
//传入数组为引用参数
void link(char (&a)[lenth],const char b[])
{
    int i=0,j=0;
    while(a[i]!='\0')i++;
    //i<lenth 确保不会溢出
    while(b[j]!='\0'&&i<lenth)a[i++]=b[j++];
    a[i++]='\0';
}

int main() {
    char a[lenth]="love",b[10]="c++";
    cout<<a<<" + "<<b<<endl;
    link(a,b);
    cout<<a;
    return 0;
}
