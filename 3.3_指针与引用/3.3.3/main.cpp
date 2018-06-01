#include <iostream>
#define len 15
using namespace std;
int* Sort(int *r, int length);      //������
int select(int *r,int length,int key);      //���Һ���
int main()
{
    int num[len],key;
    cout<<"������"<<len<<"������"<<endl;
    for(int i=0;i<len;i++)cin>>num[i];
    int *p=Sort(num,len);
    cout<<"������Ҫ���ҵ���:";
    cin>>key;
    key=select(p,len,key);          //���ҽ������key����
    if(key!=-1)cout<<"\n\n����������ĵ�"<<key+1<<"��Ԫ��";
    else cout<<"\n\n���޴���!";
    return 0;
}
int* Sort(int *r, int length)
{
    int temp;
    for (int i=0 ; i< length-1 ; i++) //n-1������
    {
        int index=i;
        for (int j=i+1 ; j < length ; j++)
            if (*(r+j) < *(r+index) )  //������С��¼��λ��
                 index=j;
        if ( index!=i)   //����������һ��Ԫ�ز�������������СԪ�أ�����н���
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
        mid =(low + high)/2;    //�۰�
        if(*(r+mid)==key)return mid;
        if(*(r+mid)<key)  low =mid + 1;  //�ж�����
        if(*(r+mid)>key)  high= mid - 1;
    }
    return -1;
}
