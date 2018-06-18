/*
 * 3.6.3  С��˾��Ա����  �̳�������
 * ������   320160939811
 * ���ļ�ʵ�� emlpoyy.cpp  empolyee.h
 */

#include <iostream>
#include "employee.h"   //����employee��

using namespace std;
class manager:public employee   //����Ա��
{
public:
    manager():employee(){}      //�������췽��
    manager(string i,string n,string s,date b,string p);
    ~manager();

    virtual void show();        //��ʾ����
    void set_wages()            //������ʾ����
    {
        employee::set_wages(8000);
    }

};

class technician:public employee    //����Ա��
{
cout
public:
    int worktime;
    technician():employee(){}          //���캯��
    technician(string i, string n, string s, date b, string p, float w, int wt);
    ~technician();
    void show();
    void set_wages()            //ʹ�ø���Ĺ�������ʾ����
    {
        employee::set_wages(worktime*25);

    }

};
class saleman:public employee   //����Ա��
{
protected:
    int salenum;
    string depart;
public:
    saleman():employee(){}      //���캯��
    saleman(string i, string n, string s, date b, string p, float w,int sn,string de);
    virtual ~saleman();
    int get_salenum(){ return salenum;}
    void show();

    virtual void set_wages()
    {
        employee::set_wages(salenum*0.04);

    }
    void set_son_wage(int n)    //��������salesmanagerʹ�õĹ�����ʾ����
    {
        employee::set_wages(5000+salenum*0.005);
    }
};

class salesmanager:public manager,saleman   //���۾�����
{
public:
    salesmanager():saleman(),manager(){}    //���캯��
    salesmanager(string i, string n, string s, date b, string p, float w, int sn, string de);
    ~salesmanager();
    void show();
    void set_wages()
    {
        saleman::set_son_wage(saleman::get_salenum());
    }
};


//�����ĸ���Ĺ��캯��
salesmanager::salesmanager(string i, string n, string s, date b, string p, float w, int sn, string de) :
        saleman(i,n,s,b,p,w,sn,de),manager(i,n,s,b,p){}

technician::technician(string i, string n, string s, date b, string p, float w,int wt):
        employee(i,n,s,b,p,w),worktime(wt){}

saleman::saleman(string i, string n, string s, date b, string p, float w, int sn, string de):
        employee(i,n,s,b,p,w),salenum(sn),depart(de){}

manager::manager(string i, string n, string s, date b, string p) :
        employee(i,n,s,b,p,8000){}

salesmanager::~salesmanager() {}

void salesmanager::show() {
    saleman::show();
}

technician::~technician() {}

void technician::show() {
    employee::show();
    cout<<" ����ʱ�䣺"<<worktime<<endl;
}

saleman::~saleman() {}

void saleman::show() {
    employee::show();
    cout<<" �������ţ�"<<depart<<endl;
}

manager::~manager() {}

void manager::show() {
    employee::show();
    cout<<endl;
}

void intxt()
{

}

//������
int main() {

    cout<<"Ա����Ϣ��"<<endl;
    manager e1("10001","�ſ�","��",date(1975,6,10),"�ܾ���");
    salesmanager e2("10002","���","��",date(1979,12,10),"���۾���",0,340000,"��������");
    saleman e3("10003","����","��",date(1980,1,10),"����Ա",0,98000,"��������");
    saleman e4("10004","�����","Ů",date(1982,1,19),"����Ա",0,88000,"��������");
    technician e5("10005", "����", "��", date(1979,1,19), "������Ա", 0, 120);
    saleman e6("10006","��ǿ","��",date(1982,4,12),"����Ա",0,89000,"��������");

    e1.show();
    e2.show();
    e3.show();
    e4.show();
    e5.show();
    e6.show();

    cout<<"\n\n������Ϣ��"<<endl;

    e1.set_wages();
    e2.set_wages();
    e3.set_wages();
    e4.set_wages();
    e5.set_wages();
    e6.set_wages();

    cout<<"\nллʹ�ã�";
    return 0;
}
