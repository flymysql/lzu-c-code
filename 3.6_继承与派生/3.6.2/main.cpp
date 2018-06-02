/*
 * 继承与派生
 * 3.6.2  教师干部类
 * 刘金明  320160939811
 */

#include <iostream>
#include <string>
using  namespace std;

class teacher      //教师基类
{
protected:
    string name;
    int age;
    string sex;
    string address;
    string phone;
    string title;
public:
    teacher()   //默认参数
    {
        name="null";
        age=0;
        sex="null";
        address="null";
        phone="null";
        title="null";
    }
    //带参数构造
    teacher(string n,int o,string s,string add,string ph,string ti)
    {
        name=n;
        age=o;
        sex=s;
        address=add;
        phone=ph;
        title=ti;
    }
    void diplay()   //打印函数
    {
        cout<<"姓名："<<name<<" 年龄："<<age<<" 性别：" <<sex
            <<" 地址："<<address<<" 电话："<<phone<<" 职称："<<title;
    }
};

class cader     //干部类
{
protected:
    string name;
    int age;
    string sex;
    string address;
    string phone;
    string post;
public:
    cader()     //默认参数
    {
        name="null";
        age=0;
        sex="null";
        address="null";
        phone="null";
        post="null";
    }
    //带参数构造方法
    cader(string n,int o,string s,string add,string ph,string ti)
    {
        name=n;
        age=o;
        sex=s;
        address=add;
        phone=ph;
        post=ti;
    }
    void diplay()       //打印函数
    {
        cout<<"姓名："<<name<<" 年龄："<<age<<" 性别：" <<sex
            <<" 地址："<<address<<" 电话："<<phone<<" 职务："<<post;
    }
};

//教师干部类，多重继承
class teacher_cader:public teacher,public cader
{
protected:
    float wages;
public:
    //默认参数构造
    teacher_cader():teacher(),cader(){}
    //带参数的构造
    teacher_cader(string n,int o,string s,string add,string ph,string ti, string po,float w):
            teacher(n, o, s, add, ph,ti), cader(n, o, s, add, ph,po), wages(w){}
    void show()
    {
        teacher::diplay();
        cout << " 职务：" <<cader::post<<endl;
    }

};

int main()
{
    teacher_cader t[3];         //对象数组
    cout<<"默认参数的构造："<<endl;
    t[0].show();
    cout<<"\n带参数的构造："<<endl;
    t[0]=teacher_cader("zhang",20,"male","bulid 305-503","6081202","tutor（助教）","普通职工",20000);
    t[1]=teacher_cader("chen",38,"male","bulid A 307-603","6081772","associate professor（副教授）","副院长",30423);
    t[2]=teacher_cader("fan",30,"female","Build 2A-202","6088099","lectuer（讲师）","教研室主任",34723);

    for(int i=0;i<3;i++)t[i].show();
    return 0;
}