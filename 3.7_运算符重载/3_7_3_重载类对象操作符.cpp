/*
 * 3.7.3  ����������  �����������
 * ������  320160939811
 */

#include <iostream>
#include <string.h>
using namespace std;

class student       //ѧ����
{
private:
    char name[10];
    int deg1,deg2,deg3;
public:
    student(){deg1=deg2=deg3=0;}        //Ĭ�ϲ�������
    student(const char *na, int d1, int d2, int d3);    //�������Ĺ���
    friend student operator+(const student s1,const student s2);    //��Ԫ�Ĳ��������غ���
    friend void avg(student &s,int n);                   //��Ԫƽ���ּ��㺯��
    //get��set����
    int get_deg1(){return deg1;}
    int get_deg2(){return deg2;}
    int get_deg3(){return deg3;}
    void set_deg(int a,int b,int c);
    void set_name(const char *n);
    void show();
} ;

//ѧ������ӵĲ��������غ���������ֵΪһ��ѧ������
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
//ѧ���ຬ�ι���
student::student(const char *na, int d1, int d2, int d3) {
    strcpy(name,na);
    deg1=d1;
    deg2=d2;
    deg3=d3;
}
//������set����
void student::set_deg(int a, int b, int c) {
    deg1=a;
    deg2=b;
    deg3=c;
}
//���ֵ�set����
void student::set_name(const char *n) {
    strcpy(name,n);
}
//ƽ���ֵ�set����
void avg(student &s, int n) {

    cout<<"\n��ѧ��ƽ���֣�(��"<<n<<"��)"<<"\n������"<<s.get_deg1()/n
        <<"\nӢ�"<<s.get_deg2()/n<<"\n�������"<<s.get_deg3()/n<<endl;
}
//ѧ����Ϣչʾ����
void student::show() {
    cout<<"ѧ����"<<name<<"\n������"<<deg1
        <<"\nӢ�"<<deg2<<"\n�������"<<deg3<<endl;
}
//������
int main()
{
    //����һ��ѧ����������
    student s[5];
    //�ô������Ĺ��취��ֵ
    s[0]=student("С��", 90, 92, 89);
    s[1]=student("����", 87, 79, 85);
    //��set������ֵ
    s[2].set_deg(78,87,95);
    s[2].set_name("����");
    s[3].set_deg(90,98,100);
    s[3].set_name("����");
    s[4]=student("�Ƽ",87,88,90);
    //ѧ����Ϣ��ʾ
    student st;
    for(int i=0;i<5;i++)
    {
        s[i].show();
        st=st+s[i];     //˳�������ѧ����������һ��
    }
    //ƽ������ʾ
    avg(st,5);
    return 0;
}
