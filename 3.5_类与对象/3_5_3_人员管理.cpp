/*
 * 3.5.3
 *员工信息管理
 * 刘金明 320160939811
 */

#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class date      //时间类
{
private:
    int year;
    int month;
    int day;
public:
    //默认参数为0
    date(){year=0;month=0;day=0;}
    date(int y,int m,int d)
    {
        year=y;
        month=m;
        day=d;
    }
    //日期读写函数构造
    void set_year(int y){year=y;}
    void set_month(int m){month=m;}
    void set_day(int d){day=d;}
    int get_year(){return year;}
    int get_month(){return month;}
    int get_day(){return day;}
};

class employee      //员工类
{
    string id;
    string name;
    date birth;
    string position;
public:
    //默认参数为null
    employee(){id="null";name="null",position="null";}
    //带参数的构造
    employee(string i,string n,date b,string p)
    {
        id=i;
        name=n;
        birth=b;
        position=p;
    }
    void set_id(string i){id=i;}
    void set_name(string n){name=n;}
    void set_date(date d){birth=d;}
    void set_position(string p){position=p;}
    string get_name(){return name;}

    void init(string i,string n,date d,string p)
    {
        id=i;
        name=n;
        birth=d;
        position=p;
    }

    //打印函数
    void show()
    {
        cout<<"编号："<<id<<" 姓名："<<name
        <<" 出生日期："<<birth.get_year()<<" 年"
        <<birth.get_month()<<" 月"<<birth.get_day()<<" 日"
        <<" 职位："<<position<<endl;
    }

};

//按名字搜索的函数（按其他参数同理）
int seaech(employee em[],int n,string name)
{
    for(int i=0;i<n;i++)
    {
        if(em[i].get_name()==name)return i;
    }
    return -1;
}

//员工信息更改函数，只传入一个string值
//但是可以根据参数 k 选择修改哪个参数
void set_employee(employee & em,int k,string s)
{

        switch(k)
        {
            case 1:em.set_id(s);break;
            case 2:em.set_name(s);break;
            case 3:em.set_position(s);break;
        }

}

int main()
{
    employee em[4];
    cout<<"数据未初始化："<<endl;
    em[0].show();

    cout<<"\n初始化数据"<<endl;
    em[0].init("10001","jack",date(80,11,1),"普通");
    em[1].init("10002","andy",date(75,1,9),"经理");
    em[2].init("10003","alex",date(81,4,3),"秘书");
    em[3].init("10004","lili",date(82,10,1),"技师");
    for(int i=0;i<4;i++)
    {
        em[i].show();
    }
    int ch=1;
    while(ch!=4)
    {
    cout<<"\n\n1.修改员工信息   2.查询某个员工信息    3.重新显示所有员工信息    4.退出\n选择：";
    cin>>ch;
    system("cls");
    if(ch==1)
    {
        string na;
        int sh;
        cout<<"\n请输入员工姓名:";
        cin>>na;
        int k=seaech(em,4,na);      //找到要修改数据的员工
        if(k!=-1)
        {
        cout<<"\n\n1.修改编号   2.修改员工姓名  3.修改员工职位   4.不修改了\n选择：";
        cin>>sh;                    //选择要修改的信息
        string change;
        cout<<"要修改为：";
        cin>>change;

        set_employee(em[k],sh,change);
        }
        else cout<<"未找到该员工！";
    }
    if(ch==2)                   //员工查找
    {
        string na;
        cout<<"\n请输入员工姓名:";
        cin>>na;
        int k=seaech(em,4,na);
        em[k].show();
    }
    if(ch==3)
    {
        for(int i=0;i<4;i++)
    {
        em[i].show();
    }
    }
    }
    cout<<"谢谢使用！";
    return 0;
}
