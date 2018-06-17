/*
 * 虚函数与多态
 * 3.8.2  教师员工类
 * 刘金明  320160939811
 */

#include <iostream>
#include <string>
using  namespace std;

class teacher      //½ÌÊ¦»ùÀà
{
protected:
    string name;
    int age;
    string sex;
    string address;
    string phone;
    string title;
public:
    teacher()   //Ä¬ÈÏ²ÎÊý
    {
        name="null";
        age=0;
        sex="null";
        address="null";
        phone="null";
        title="null";
    }
    //´ø²ÎÊý¹¹Ôì
    teacher(string n,int o,string s,string add,string ph,string ti)
    {
        name=n;
        age=o;
        sex=s;
        address=add;
        phone=ph;
        title=ti;
    }
    void diplay()   //´òÓ¡º¯Êý
    {
        cout<<"ÐÕÃû£º"<<name<<" ÄêÁä£º"<<age<<" ÐÔ±ð£º" <<sex
            <<" µØÖ·£º"<<address<<" µç»°£º"<<phone<<" Ö°³Æ£º"<<title;
    }
};

class cader     //¸É²¿Àà
{
protected:
    string name;
    int age;
    string sex;
    string address;
    string phone;
    string post;
public:
    cader()     //Ä¬ÈÏ²ÎÊý
    {
        name="null";
        age=0;
        sex="null";
        address="null";
        phone="null";
        post="null";
    }
    //´ø²ÎÊý¹¹Ôì·½·¨
    cader(string n,int o,string s,string add,string ph,string ti)
    {
        name=n;
        age=o;
        sex=s;
        address=add;
        phone=ph;
        post=ti;
    }
    void diplay()       //´òÓ¡º¯Êý
    {
        cout<<"ÐÕÃû£º"<<name<<" ÄêÁä£º"<<age<<" ÐÔ±ð£º" <<sex
            <<" µØÖ·£º"<<address<<" µç»°£º"<<phone<<" Ö°Îñ£º"<<post;
    }
};

//½ÌÊ¦¸É²¿Àà£¬¶àÖØ¼Ì³Ð
class teacher_cader:public teacher,public cader
{
protected:
    float wages;
public:
    //Ä¬ÈÏ²ÎÊý¹¹Ôì
    teacher_cader():teacher(),cader(){}
    //´ø²ÎÊýµÄ¹¹Ôì
    teacher_cader(string n,int o,string s,string add,string ph,string ti, string po,float w):
            teacher(n, o, s, add, ph,ti), cader(n, o, s, add, ph,po), wages(w){}
    void show()
    {
        teacher::diplay();
        cout << " Ö°Îñ£º" <<cader::post<<endl;
    }

};

int main()
{
    teacher_cader t[3];         //¶ÔÏóÊý×é
    cout<<"Ä¬ÈÏ²ÎÊýµÄ¹¹Ôì£º"<<endl;
    t[0].show();
    cout<<"\n´ø²ÎÊýµÄ¹¹Ôì£º"<<endl;
    t[0]=teacher_cader("zhang",20,"male","bulid 305-503","6081202","tutor£¨Öú½Ì£©","ÆÕÍ¨Ö°¹¤",20000);
    t[1]=teacher_cader("chen",38,"male","bulid A 307-603","6081772","associate professor£¨¸±½ÌÊÚ£©","¸±Ôº³¤",30423);
    t[2]=teacher_cader("fan",30,"female","Build 2A-202","6088099","lectuer£¨½²Ê¦£©","½ÌÑÐÊÒÖ÷ÈÎ",34723);

    for(int i=0;i<3;i++)t[i].show();
    return 0;
}