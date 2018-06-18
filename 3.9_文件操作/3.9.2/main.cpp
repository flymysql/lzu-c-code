/*
 * 3.6.3  小公司人员管理  继承与派生
 * 刘金明   320160939811
 * 多文件实现 emlpoyy.cpp  empolyee.h
 */

#include <iostream>
#include "employee.h"   //声明employee类

using namespace std;
class manager:public employee   //管理员类
{
public:
    manager():employee(){}      //两个构造方法
    manager(string i,string n,string s,date b,string p);
    ~manager();

    virtual void show();        //显示函数
    void set_wages()            //工资显示函数
    {
        employee::set_wages(8000);
    }

};

class technician:public employee    //技术员类
{
cout
public:
    int worktime;
    technician():employee(){}          //构造函数
    technician(string i, string n, string s, date b, string p, float w, int wt);
    ~technician();
    void show();
    void set_wages()            //使用父类的工资类显示工资
    {
        employee::set_wages(worktime*25);

    }

};
class saleman:public employee   //销售员类
{
protected:
    int salenum;
    string depart;
public:
    saleman():employee(){}      //构造函数
    saleman(string i, string n, string s, date b, string p, float w,int sn,string de);
    virtual ~saleman();
    int get_salenum(){ return salenum;}
    void show();

    virtual void set_wages()
    {
        employee::set_wages(salenum*0.04);

    }
    void set_son_wage(int n)    //供给子类salesmanager使用的工资显示函数
    {
        employee::set_wages(5000+salenum*0.005);
    }
};

class salesmanager:public manager,saleman   //销售经理类
{
public:
    salesmanager():saleman(),manager(){}    //构造函数
    salesmanager(string i, string n, string s, date b, string p, float w, int sn, string de);
    ~salesmanager();
    void show();
    void set_wages()
    {
        saleman::set_son_wage(saleman::get_salenum());
    }
};


//上面四个类的构造函数
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
    cout<<" 工作时间："<<worktime<<endl;
}

saleman::~saleman() {}

void saleman::show() {
    employee::show();
    cout<<" 所属部门："<<depart<<endl;
}

manager::~manager() {}

void manager::show() {
    employee::show();
    cout<<endl;
}

void intxt()
{

}

//主函数
int main() {

    cout<<"员工信息："<<endl;
    manager e1("10001","张可","男",date(1975,6,10),"总经理");
    salesmanager e2("10002","李冰","男",date(1979,12,10),"销售经理",0,340000,"华北地区");
    saleman e3("10003","王刚","男",date(1980,1,10),"销售员",0,98000,"华北地区");
    saleman e4("10004","陈皓月","女",date(1982,1,19),"销售员",0,88000,"华北地区");
    technician e5("10005", "宋书", "男", date(1979,1,19), "技术人员", 0, 120);
    saleman e6("10006","付强","男",date(1982,4,12),"销售员",0,89000,"华东地区");

    e1.show();
    e2.show();
    e3.show();
    e4.show();
    e5.show();
    e6.show();

    cout<<"\n\n工资信息："<<endl;

    e1.set_wages();
    e2.set_wages();
    e3.set_wages();
    e4.set_wages();
    e5.set_wages();
    e6.set_wages();

    cout<<"\n谢谢使用！";
    return 0;
}
