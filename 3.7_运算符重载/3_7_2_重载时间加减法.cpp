/*
 * 3.7.2 时间加减法
 * 刘金明 320160939811
 *
 */

#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

class ctime         //时间类
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
        if(h<24)            //只有小时的构造函数
        {
            hour=h;minute=0;second=0;
        }
        else
        {
            hour=0;minute=0;second=0;
        }
    }
    ctime(int h,int m)      //只有时和分的构造函数
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
    ctime(int h,int m,int s)    //完整的构造函数
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
    void print(int n)       //确保能够显示两位数的函数
    {
        if(n<10) cout<<"0"<<n;
        else cout<<n;
    }
    void display()          //打印函数
    {
        print(hour);
        cout<<":";
        print(minute);
        cout<<":";
        print(second);
    }
    ctime operator++();     //前置++操作与后置++操作
    friend ctime operator++(ctime & t,int);
};
ctime ctime::operator++()       //后置++操作符
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
ctime operator++(ctime & t,int n)       //前置++操作符
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
        if(i%10==0)           //每隔10秒清屏一次
        {
            system("cls");
            cout<<"test time 1\t\ttest time 2"<<endl<<endl;
        }
        t1++;             //后置＋＋重载测试
        ++t2;            //前置＋＋重载测试
        t1.display();
        cout<<"\t\t";
        t2.display();
        cout<<endl;
        Sleep(1000);    //进程睡眠一秒,模仿时钟,不过加上程序的执行时间,应该不止一秒

    }

    return 0;
}
