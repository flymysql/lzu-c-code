/*
 * 3.5.3
 *Ա����Ϣ����
 * ������ 320160939811
 */

#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class date      //ʱ����
{
private:
    int year;
    int month;
    int day;
public:
    //Ĭ�ϲ���Ϊ0
    date(){year=0;month=0;day=0;}
    date(int y,int m,int d)
    {
        year=y;
        month=m;
        day=d;
    }
    //���ڶ�д��������
    void set_year(int y){year=y;}
    void set_month(int m){month=m;}
    void set_day(int d){day=d;}
    int get_year(){return year;}
    int get_month(){return month;}
    int get_day(){return day;}
};

class employee      //Ա����
{
    string id;
    string name;
    date birth;
    string position;
public:
    //Ĭ�ϲ���Ϊnull
    employee(){id="null";name="null",position="null";}
    //�������Ĺ���
    employee(string i,string n,date b,string p)
    {
        id=i;
        name=n;
        birth=b;
        position=p;
    }
    void set_id(string i){id=i;}
    void set_name(string n){name=n;}
    void set_date(date d){birth=d;}
    void set_position(string p){position=p;}
    string get_name(){return name;}

    void init(string i,string n,date d,string p)
    {
        id=i;
        name=n;
        birth=d;
        position=p;
    }

    //��ӡ����
    void show()
    {
        cout<<"��ţ�"<<id<<" ������"<<name
        <<" �������ڣ�"<<birth.get_year()<<" ��"
        <<birth.get_month()<<" ��"<<birth.get_day()<<" ��"
        <<" ְλ��"<<position<<endl;
    }

};

//�����������ĺ���������������ͬ��
int seaech(employee em[],int n,string name)
{
    for(int i=0;i<n;i++)
    {
        if(em[i].get_name()==name)return i;
    }
    return -1;
}

//Ա����Ϣ���ĺ�����ֻ����һ��stringֵ
//���ǿ��Ը��ݲ��� k ѡ���޸��ĸ�����
void set_employee(employee & em,int k,string s)
{

        switch(k)
        {
            case 1:em.set_id(s);break;
            case 2:em.set_name(s);break;
            case 3:em.set_position(s);break;
        }

}

int main()
{
    employee em[4];
    cout<<"����δ��ʼ����"<<endl;
    em[0].show();

    cout<<"\n��ʼ������"<<endl;
    em[0].init("10001","jack",date(80,11,1),"��ͨ");
    em[1].init("10002","andy",date(75,1,9),"����");
    em[2].init("10003","alex",date(81,4,3),"����");
    em[3].init("10004","lili",date(82,10,1),"��ʦ");
    for(int i=0;i<4;i++)
    {
        em[i].show();
    }
    int ch=1;
    while(ch!=4)
    {
    cout<<"\n\n1.�޸�Ա����Ϣ   2.��ѯĳ��Ա����Ϣ    3.������ʾ����Ա����Ϣ    4.�˳�\nѡ��";
    cin>>ch;
    system("cls");
    if(ch==1)
    {
        string na;
        int sh;
        cout<<"\n������Ա������:";
        cin>>na;
        int k=seaech(em,4,na);      //�ҵ�Ҫ�޸����ݵ�Ա��
        if(k!=-1)
        {
        cout<<"\n\n1.�޸ı��   2.�޸�Ա������  3.�޸�Ա��ְλ   4.���޸���\nѡ��";
        cin>>sh;                    //ѡ��Ҫ�޸ĵ���Ϣ
        string change;
        cout<<"Ҫ�޸�Ϊ��";
        cin>>change;

        set_employee(em[k],sh,change);
        }
        else cout<<"δ�ҵ���Ա����";
    }
    if(ch==2)                   //Ա������
    {
        string na;
        cout<<"\n������Ա������:";
        cin>>na;
        int k=seaech(em,4,na);
        em[k].show();
    }
    if(ch==3)
    {
        for(int i=0;i<4;i++)
    {
        em[i].show();
    }
    }
    }
    cout<<"ллʹ�ã�";
    return 0;
}
