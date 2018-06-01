/*
 * 3.3.1
 * 刘金明 320160939811
 */

#include <iostream>
using namespace std;
void swap(int * p1,int *p2);
int main() {
    cout<<"---------------------------"<<endl;
    int iv1=888;
    int *pointer_1;
    pointer_1=&iv1;         //指针指向iv1的地址
    cout<<"iv1        ="<<iv1<<endl;
    cout<<"*pointer_1 ="<<*pointer_1<<endl;
    cout<<"&iv1       ="<<&iv1<<endl;       //输出iv1地址
    cout<<"pointer_1  ="<<pointer_1<<endl;  //输出指针内容(iv1地址)
    cout<<"---------------------------"<<endl;

    int iv2=888;
    int *pointer_2;
    pointer_2=&iv2;
    cout<<"iv2        ="<<iv2<<endl;
    cout<<"*pointer_2 ="<<*pointer_2<<endl;
    cout<<"&iv2       ="<<&iv2<<endl;
    cout<<"pointer_2  ="<<pointer_2<<endl;
    cout<<"---------------------------"<<endl;

    swap(pointer_1,pointer_2);

    cout<<"iv1        ="<<iv1<<endl;
    cout<<"iv2        ="<<iv2<<endl;
    cout<<"*pointer_1 ="<<*pointer_1<<endl;
    cout<<"*pointer_2 ="<<*pointer_2<<endl;
    cout<<"pointer_1 ="<<pointer_1<<endl;
    cout<<"pointer_2 ="<<pointer_2<<endl;
    return 0;
}

void swap(int *p1,int *p2)
{
    int temp;
    temp =*p1;  //一个是改变地址，一个是改变地址指向的值
    *p1=*p2;    //将p2存的地址指向的值赋予p1存的地址指向的值
    *p2=temp;   //将p1的值赋予p2
}