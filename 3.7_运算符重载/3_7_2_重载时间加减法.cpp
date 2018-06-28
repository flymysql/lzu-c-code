/*
 * 3.7.2 ʱ��Ӽ���
 * ������ 320160939811
 *
 */

#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

class ctime         //ʱ����
{
public:
    int hour;
    int minute;
    int second;
public:
    ctime()
    {
        hour=0;minute=0;second=0;
    }
    ctime(int h)
    {
        if(h<24)            //ֻ��Сʱ�Ĺ��캯��
        {
            hour=h;minute=0;second=0;
        }
        else
        {
            hour=0;minute=0;second=0;
        }
    }
    ctime(int h,int m)      //ֻ��ʱ�ͷֵĹ��캯��
    {
        if(h<24&&m<60)
        {
            hour=h;minute=m;second=0;
        }
        else
        {
            hour=0;minute=0;second=0;
        }
    }
    ctime(int h,int m,int s)    //�����Ĺ��캯��
    {
        if(h<24&&m<60&&s<60)
        {
            hour=h;minute=m;second=s;
        }
        else
        {
            hour=0;minute=0;second=0;
        }
    }

    void set_hour(int h)
    {
        hour=h;
    }
    void set_minute(int m)
    {
        minute=m;
    }
    void set_second(int s)
    {
        second=s;
    }
    void print(int n)       //ȷ���ܹ���ʾ��λ���ĺ���
    {
        if(n<10) cout<<"0"<<n;
        else cout<<n;
    }
    void display()          //��ӡ����
    {
        print(hour);
        cout<<":";
        print(minute);
        cout<<":";
        print(second);
    }
    ctime operator++();     //ǰ��++���������++����
    friend ctime operator++(ctime & t,int);
};
ctime ctime::operator++()       //����++������
{
    if( second<59) second++;
    else
    {
        if( minute<59)
        {
             minute++;
             second=0;
        }
        else
        {
            if( hour<23)
            {
                 hour++;
                 second=0;
                 minute=0;
            }
            else
            {
                 hour=0;
                 minute=0;
                 second=0;
            }
        }
    }
    return *this;
}
ctime operator++(ctime & t,int n)       //ǰ��++������
{
    if(t.second<59)t.second++;
    else
    {
        if(t.minute<59)
        {
            t.minute++;
            t.second=0;
        }
        else
        {
            if(t.hour<23)
            {
                t.hour++;
                t.second=0;
                t.minute=0;
            }
            else
            {
                t.hour=0;
                t.minute=0;
                t.second=0;
            }
        }
    }
    return t;
}
int main()
{
    ctime t1(13,45,39);
    ctime t2(23,58,5);
    for(int i=0;i<10000;i++)
    {
        if(i%10==0)           //ÿ��10������һ��
        {
            system("cls");
            cout<<"test time 1\t\ttest time 2"<<endl<<endl;
        }
        t1++;             //���ã������ز���
        ++t2;            //ǰ�ã������ز���
        t1.display();
        cout<<"\t\t";
        t2.display();
        cout<<endl;
        Sleep(1000);    //����˯��һ��,ģ��ʱ��,�������ϳ����ִ��ʱ��,Ӧ�ò�ֹһ��

    }

    return 0;
}
