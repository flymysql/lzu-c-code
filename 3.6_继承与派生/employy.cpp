//
// Created by С�� on 2018/6/2.
// 320160939811

#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class date      //ʱ����
{
private:
    int year;
    int month;
    int day;
public:
    //Ĭ�ϲ���Ϊ0
    date();
    date(int y,int m,int d);
    //���ڶ�д��������
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

class employee      //Ա����
{
private:
    string id;
    string name;
    string sex;
    date birth;
    string position;
    float wages;
public:
    //Ĭ�ϲ���Ϊnull
    employee();
    //�������Ĺ���
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

    //��ӡ����
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
    cout<<"��ţ�"<<id<<" ������"<<name
        <<" �������ڣ�"<<birth.get_year()<<" ��"
        <<birth.get_month()<<" ��"<<birth.get_day()<<" ��"
        <<" ְλ��"<<position;
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
    cout<<get_name(*this)<<" ְλ��"<<get_position(*this)
        <<" ���ʣ�"<<get_wages(*this)<<endl;
}

void employee::set_position(string p) {position=p;}

//�����������ĺ���������������ͬ��
//����ҵ3.5.3��ʹ�ã����������û�е���
int search(employee em[],int n,string name)
{
    for(int i=0;i<n;i++)
    {
        if(get_name(em[i])==name)return i;
    }
    return -1;
}

//Ա����Ϣ���ĺ�����ֻ����һ��stringֵ
//���ǿ��Ը��ݲ��� k ѡ���޸��ĸ�����
//����ҵ3.5.3��ʹ�ã����������û�е���
void set_employee(employee & em,int k,string s)
{

    switch(k)
    {
        case 1:em.set_id(s);break;
        case 2:em.set_name(s);break;
        case 3:em.set_position(s);break;
    }

}
