/*
 * 3.2.3  排序查找
 * 刘金明 320160939811
 */

#include <iostream>
using namespace std;
#define stu 15
void sort(int r[stu])
{
    int temp;
    for (int i=0 ; i< stu-1 ; i++) //n-1趟排序
    {
        int index=i;       //假设index处对应的数组元素是最小的
        for (int j=i+1 ; j < stu; j++) //查找最小记录的位置
        if (r[j] < r[index])
            index=j;
        if ( index!=i) //若无序区第一个元素不是无序区中最小元素，则进行交换
        {
            temp=r[i];
            r[i]=r[index];
            r[index]=temp;
        }
    }
}
int search(int r[],int key)
{
    int low=0,high=stu-1,mid;
    while (low<=high)
    {
        mid=(low+high)/2;       //折半查找
        if(r[mid]==key)return mid;
          else if(r[mid]<key) low=mid+1;
             else high=mid-1;
    }
    return -1;
}

int main() {
    int a[stu],key;
    cout<<"please input scores of the "<<stu<<" students"<<endl;
    for(int i=0;i<stu;i++)cin>>a[i];
    sort(a);
    cout<<"\n\nplease input the score you want to search!\nscore:";
    cin>>key;
    key=search(a,key);
    if(key!=-1)cout<<"\n\nthe rank is:"<<key;
    else cout<<"there is no such score!!!please input again!!!";
    return 0;
}