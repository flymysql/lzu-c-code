#include <iostream>
#define len 15
using namespace std;
int* Sort(int *r, int length);      //排序函数
int select(int *r,int length,int key);      //查找函数
int main()
{
    int num[len],key;
    cout<<"请输入"<<len<<"个数："<<endl;
    for(int i=0;i<len;i++)cin>>num[i];
    int *p=Sort(num,len);
    cout<<"请输入要查找的数:";
    cin>>key;
    key=select(p,len,key);          //查找结果存在key里面
    if(key!=-1)cout<<"\n\n该数是数组的第"<<key+1<<"个元素";
    else cout<<"\n\n查无此数!";
    return 0;
}
int* Sort(int *r, int length)
{
    int temp;
    for (int i=0 ; i< length-1 ; i++) //n-1趟排序
    {
        int index=i;
        for (int j=i+1 ; j < length ; j++)
            if (*(r+j) < *(r+index) )  //查找最小记录的位置
                 index=j;
        if ( index!=i)   //若无序区第一个元素不是无序区中最小元素，则进行交换
        {
            temp = *(r+i);
            *(r+i) = *(r+index);
            *(r+index) = temp;
        }
    }
    return r;
}
int select(int *r,int length,int key)
{
    int low=0,high=length-1,mid;
    while(low<=high)
    {
        mid =(low + high)/2;    //折半
        if(*(r+mid)==key)return mid;
        if(*(r+mid)<key)  low =mid + 1;  //判断区域
        if(*(r+mid)>key)  high= mid - 1;
    }
    return -1;
}
