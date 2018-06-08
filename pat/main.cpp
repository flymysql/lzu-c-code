#include <iostream>
using namespace std;

class pat   //������������
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
    //���崿�麯��speak
    virtual void speak() const =0 ;
};

//set����
void pat::set(string co, float we, int a) {
    color=co;
    weight=we;
    age=a;
}

//������Ĺ��췽��
pat::pat() {
    set("null",0,0);
}

pat::pat(string co, float we, int a) {
    set(co,we,a);
}

class cat:public pat    //С����
{
public:
    cat(string co, float we, int a): pat(co, we, a){}
    cat():pat(){}
    ~cat(){}
    void speak() const ;
};

class dog:public pat    //Сè��
{
public:
    dog(string co, float we,int a):pat(co,we,a){}
    dog():pat(){}
    ~dog(){}
    void speak() const ;
};

//С�����speak����
void cat::speak() const {
    cout<<color<<"è˵��"<<"����~"<<endl;
}
//Сè���speak����
void dog::speak() const {
    cout<<color<<"��˵��"<<"����~"<<endl;
}

int main() {
    pat *p[4];  //����ָ�����飬��ָ��������

    p[0]=new cat("��",12.3,3);
    p[1]=new dog("��",11.9,2);
    p[2]=new dog("��",8.5,1);
    p[3]=new cat("��",3.4,3);

    for(int i=0;i<4;i++)
    {
        p[i]->speak();      //����speak����
        delete p[i];        //�ͷſռ�
    }
    return 0;
}