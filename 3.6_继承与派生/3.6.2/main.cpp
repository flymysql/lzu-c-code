/*
 * �̳�������
 * 3.6.2  ��ʦ�ɲ���
 * ������  320160939811
 */

#include <iostream>
#include <string>
using  namespace std;

class teacher      //��ʦ����
{
protected:
    string name;
    int age;
    string sex;
    string address;
    string phone;
    string title;
public:
    teacher()   //Ĭ�ϲ���
    {
        name="null";
        age=0;
        sex="null";
        address="null";
        phone="null";
        title="null";
    }
    //����������
    teacher(string n,int o,string s,string add,string ph,string ti)
    {
        name=n;
        age=o;
        sex=s;
        address=add;
        phone=ph;
        title=ti;
    }
    void diplay()   //��ӡ����
    {
        cout<<"������"<<name<<" ���䣺"<<age<<" �Ա�" <<sex
            <<" ��ַ��"<<address<<" �绰��"<<phone<<" ְ�ƣ�"<<title;
    }
};

class cader     //�ɲ���
{
protected:
    string name;
    int age;
    string sex;
    string address;
    string phone;
    string post;
public:
    cader()     //Ĭ�ϲ���
    {
        name="null";
        age=0;
        sex="null";
        address="null";
        phone="null";
        post="null";
    }
    //���������췽��
    cader(string n,int o,string s,string add,string ph,string ti)
    {
        name=n;
        age=o;
        sex=s;
        address=add;
        phone=ph;
        post=ti;
    }
    void diplay()       //��ӡ����
    {
        cout<<"������"<<name<<" ���䣺"<<age<<" �Ա�" <<sex
            <<" ��ַ��"<<address<<" �绰��"<<phone<<" ְ��"<<post;
    }
};

//��ʦ�ɲ��࣬���ؼ̳�
class teacher_cader:public teacher,public cader
{
protected:
    float wages;
public:
    //Ĭ�ϲ�������
    teacher_cader():teacher(),cader(){}
    //�������Ĺ���
    teacher_cader(string n,int o,string s,string add,string ph,string ti, string po,float w):
            teacher(n, o, s, add, ph,ti), cader(n, o, s, add, ph,po), wages(w){}
    void show()
    {
        teacher::diplay();
        cout << " ְ��" <<cader::post<<endl;
    }

};

int main()
{
    teacher_cader t[3];         //��������
    cout<<"Ĭ�ϲ����Ĺ��죺"<<endl;
    t[0].show();
    cout<<"\n�������Ĺ��죺"<<endl;
    t[0]=teacher_cader("zhang",20,"male","bulid 305-503","6081202","tutor�����̣�","��ְͨ��",20000);
    t[1]=teacher_cader("chen",38,"male","bulid A 307-603","6081772","associate professor�������ڣ�","��Ժ��",30423);
    t[2]=teacher_cader("fan",30,"female","Build 2A-202","6088099","lectuer����ʦ��","����������",34723);

    for(int i=0;i<3;i++)t[i].show();
    return 0;
}