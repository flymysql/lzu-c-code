//
// Created by 小金 on 2018/6/2.
// 320160939811

#ifndef INC_3_6_3_EMPLOYEE_H
#define INC_3_6_3_EMPLOYEE_H
#include <iostream>
#include <string.h>
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
float get_wages(employee &em) ;
string get_name(employee &em) ;
string get_position(employee &em);
int search(employee em[],int n,string name);
void set_employee(employee & em,int k,string s);
#endif //INC_3_6_3_EMPLOYEE_H
