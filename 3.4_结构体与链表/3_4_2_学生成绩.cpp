/*
 * 3.4.2   学生成绩管理，结构体实现
 * 刘金明  320160939811
 */

#include <iostream>
using namespace std;
#define stu 2      //define学生人数，便于修改

struct student  //学生结构
{
    string name;
    double id;
    string cls;
    float score[3];
    float aver_score;
};

//实现所有学生的数据输入
void input(student (&a)[stu])
{
    cout<<"please input the "<<stu<<" stdents` information:";
    for(int i=0;i<stu;i++)
    {
        cout<<"\n\nNo."<<i+1<<endl;
        cout<<"id:";
        cin>>a[i].id;
        cout<<"class:";
        cin>>a[i].cls;
        cout<<"name:";
        cin>>a[i].name;
        cout<<"mathe score:";
        cin>>a[i].score[0];
        cout<<"C score:";
        cin>>a[i].score[1];
        cout<<"C++ score:";
        cin>>a[i].score[2];
    }
}

int aver( student &a)     //每个学生平均分计算
{
    a.aver_score=(a.score[0]+a.score[1]+a.score[2])/3;
    return a.aver_score;
}

//学生数组，最高平均分计算，返回最高的数组下标
int high(student a[stu])
{
    int high=0;
    for(int i=0;i<stu;i++)
    {

        if(aver(a[i])>high)
        {
            high=i;
        }
    }
    return high;
}
int main() {
    student st[stu];
    input(st);
    int h=high(st);
    for(int i=0;i<stu;i++)
    {
        cout<<"student "<<i+1<<"`s aver score:"<<aver(st[i])<<endl;
    }
    cout<<"\nthe highest score:"
        <<"\nid"<<st[h].id
        <<"\nclass:"<<st[h].cls
        <<"\nname"<<st[h].name
        <<"\nmathe score:"<<st[h].score[0]
        <<"\nC score:"<<st[h].score[1]
        <<"\nC++ score:"<<st[h].score[2]
        <<"\naver score:"<<aver(st[h]);
    return 0;
}
