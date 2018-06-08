#include <iostream>
using namespace std;

class pat   //宠物抽象类基类
{
protected:
    string color;
    float weight;
    int age;
public:
    pat();
    pat(string co, float we,int a);
    void set(string co, float we,int a);
    ~pat(){}
    //定义纯虚函数speak
    virtual void speak() const =0 ;
};

//set方法
void pat::set(string co, float we, int a) {
    color=co;
    weight=we;
    age=a;
}

//宠物类的构造方法
pat::pat() {
    set("null",0,0);
}

pat::pat(string co, float we, int a) {
    set(co,we,a);
}

class cat:public pat    //小狗类
{
public:
    cat(string co, float we, int a): pat(co, we, a){}
    cat():pat(){}
    ~cat(){}
    void speak() const ;
};

class dog:public pat    //小猫类
{
public:
    dog(string co, float we,int a):pat(co,we,a){}
    dog():pat(){}
    ~dog(){}
    void speak() const ;
};

//小狗类的speak函数
void cat::speak() const {
    cout<<color<<"猫说："<<"喵喵~"<<endl;
}
//小猫类的speak函数
void dog::speak() const {
    cout<<color<<"狗说："<<"汪汪~"<<endl;
}

int main() {
    pat *p[4];  //基类指针数组，可指向派生类

    p[0]=new cat("黄",12.3,3);
    p[1]=new dog("黑",11.9,2);
    p[2]=new dog("蓝",8.5,1);
    p[3]=new cat("白",3.4,3);

    for(int i=0;i<4;i++)
    {
        p[i]->speak();      //调用speak函数
        delete p[i];        //释放空间
    }
    return 0;
}