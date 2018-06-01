
#include <iostream>

using namespace std;

class ctime
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
        if(h<24)
        {
            hour=h;minute=0;second=0;
        }
        else
        {
            hour=0;minute=0;second=0;
        }
    }
    ctime(int h,int m)
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
    ctime(int h,int m,int s)
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
    void print(int n)
    {
        if(n<10) cout<<"0"<<n;
        else cout<<n;
    }
    void display()
    {
        print(hour);
        cout<<":";
        print(minute);
        cout<<":";
        print(second);
    }
    ctime operator++();
    friend ctime operator++(ctime & t,int);
};
ctime ctime::operator++()
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
ctime operator++(ctime & t,int n)
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
    ctime t(23,59,45);
    //后置＋＋重载测试
    for(int i=0;i<30;i++)
    {
        t++;
        t.display();
        cout<<endl;
    }
    //前置＋＋重载测试
    ctime t2(34); //异常时间输入测试
    for(int i=0;i<30;i++)
    {
        ++t2;
        t2.display();
        cout<<endl;
    }
    return 0;
}
