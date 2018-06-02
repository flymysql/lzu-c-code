//
// Created by 小金 on 2018/6/2.
// 320160939811

#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class date      //时间类
{
private:
    int year;
    int month;
    int day;
public:
    //默认参数为0
    date();
    date(int y,int m,int d);
    //日期读写函数构造
    void set_year(int y);
    void set_month(int m);
    void set_day(int d);
    int get_year();
    int get_month();
    int get_day();
};

date::date(int y, int m, int d) {
    year=y;
    month=m;
    day=d;
}

date::date() {year=0;month=0;day=0;}

void date::set_year(int y) {year=y;}

void date::set_month(int m) {month=m;}

void date::set_day(int d) {day=d;}

int date::get_year() {return year;}

int date::get_month() {return month;}

int date::get_day() {return day;}

class employee      //员工类
{
private:
    string id;
    string name;
    string sex;
    date birth;
    string position;
    float wages;
public:
    //默认参数为null
    employee();
    //带参数的构造
    employee(string i,string n,string s,date b,string p, float w);
    void set_id(string i);
    void set_name(string n);
    void set_date(date d);
    void set_position(string p);
    void set_wages(float w);

    friend float get_wages(employee &em);
    friend string get_name(employee &em);
    friend string get_position(employee &em);
    void init(string i,string n,date d,string p);

    //打印函数
    void show();

};
float get_wages(employee &em) { return em.wages; }
string get_name(employee &em) { return em.name;}
string get_position(employee &em){ return  em.position;}

employee::employee(string i, string n, string s, date b, string p, float w) {
    id=i;
    name=n;
    sex=s;
    birth=b;
    position=p;
    wages=w;
}

void employee::show() {
    cout<<"编号："<<id<<" 姓名："<<name
        <<" 出生日期："<<birth.get_year()<<" 年"
        <<birth.get_month()<<" 月"<<birth.get_day()<<" 日"
        <<" 职位："<<position;
}

void employee::init(string i, string n, date d, string p) {
    id=i;
    name=n;
    birth=d;
    position=p;
}

employee::employee() {id="null";name="null";sex="null";position="null";wages=0;}

void employee::set_id(string i) {id=i;}

void employee::set_name(string n) {name=n;}

void employee::set_date(date d) {birth=d;}

void employee::set_wages(float w)
{
    wages=w;
    cout<<get_name(*this)<<" 职位："<<get_position(*this)
        <<" 工资："<<get_wages(*this)<<endl;
}

void employee::set_position(string p) {position=p;}

//按名字搜索的函数（按其他参数同理）
//在作业3.5.3中使用，这个程序里没有调用
int search(employee em[],int n,string name)
{
    for(int i=0;i<n;i++)
    {
        if(get_name(em[i])==name)return i;
    }
    return -1;
}

//员工信息更改函数，只传入一个string值
//但是可以根据参数 k 选择修改哪个参数
//在作业3.5.3中使用，这个程序里没有调用
void set_employee(employee & em,int k,string s)
{

    switch(k)
    {
        case 1:em.set_id(s);break;
        case 2:em.set_name(s);break;
        case 3:em.set_position(s);break;
    }

}
