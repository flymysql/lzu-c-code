/*
 * 3.7.3  操作符重载  类对象做参数
 * 刘金明  320160939811
 */

#include <iostream>
#include <string.h>
using namespace std;

class student       //学生类
{
private:
    char name[10];
    int deg1,deg2,deg3;
public:
    student(){deg1=deg2=deg3=0;}        //默认参数构造
    student(const char *na, int d1, int d2, int d3);    //带参数的构造
    friend student operator+(const student s1,const student s2);    //友元的操作符重载函数
    friend void avg(student &s,int n);                   //友元平均分计算函数
    //get和set方法
    int get_deg1(){return deg1;}
    int get_deg2(){return deg2;}
    int get_deg3(){return deg3;}
    void set_deg(int a,int b,int c);
    void set_name(const char *n);
    void show();
} ;

//学生类相加的操作符重载函数，返回值为一个学生对象
student operator+ (student s1, student s2)
{
    student a;
    int d1;
    d1 = s1.get_deg1() + s2.get_deg1();
    int d2=s1.get_deg2()+s2.get_deg2();
    int d3=s1.get_deg3()+s2.get_deg3();
    a.set_deg(d1,d2,d3);
    a.set_name("new_stu");
    return a;
}
//学生类含参构造
student::student(const char *na, int d1, int d2, int d3) {
    strcpy(name,na);
    set_deg(d1,d2,d3);
}
//分数的set方法
void student::set_deg(int a, int b, int c) {
    deg1=a;
    deg2=b;
    deg3=c;
}
//名字的set方法
void student::set_name(const char *n) {
    strcpy(name,n);
}
//平均分的set方法
void avg(student &s, int n) {

    cout<<"\n各学科平均分：(共"<<n<<"人)"<<"\n高数："<<s.get_deg1()/n
        <<"\n英语："<<s.get_deg2()/n<<"\n计算机："<<s.get_deg3()/n<<endl;
}
//学生信息展示函数
void student::show() {
    cout<<"学生："<<name<<"\n高数："<<deg1
        <<"\n英语："<<deg2<<"\n计算机："<<deg3<<endl;
}
//主函数
int main()
{
    //定义一个学生对象数组
    student s[5];
    //用带参数的构造法赋值
    s[0]=student("小鸡", 90, 92, 89);
    s[1]=student("阿敏", 87, 79, 85);
    //用set方法赋值
    s[2].set_deg(78,87,95);
    s[2].set_name("花花");
    s[3].set_deg(90,98,100);
    s[3].set_name("西西");
    s[4]=student("铷萍",87,88,90);
    //学生信息显示
    student st;
    for(int i=0;i<5;i++)
    {
        s[i].show();
        st=st+s[i];     //顺便把所有学生分数加在一起
    }
    //平均分显示
    avg(st,5);
    return 0;
}
