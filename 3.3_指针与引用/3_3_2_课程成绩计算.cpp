/*
*3.3.2 学生成绩计算
*刘金明  320160939811
*/

#include <iostream>
#include <stdlib.h>
using namespace std;
#define stu 5           //定义学生人数
#define cls 5           //定义课程数
int avercourse( int sco[][cls],int n );
void averscore ( int sco[][cls] ,int avsco[stu] ,int num[stu]);
int main()
{
    int sco[stu][cls]={{71,82,63,94,55},{52,63,94,55,76},{82,83,64,95,76},{62,63,54,55,56},{92,93,94,95,96}};
    int num[stu]={20160901, 20160902, 20160903, 20160904, 20160905},avsco[stu]={0};
   /*  for(int i=0;i<stu;i++)
    {
        cout<<"第 "<<i<<" 个学生学号：";
        cin>>num[i];
        cout<<"\n五门学科成绩：";
        for(int j=0;j<cls;j++)cin>>sco[i][j];
        cout<<endl;
    }
    */
    int ch=0;
    while(ch!=3)
    {
        cout<<"共录入5名学生的五个学科成绩,按下面数字选择操作！"<<endl;
        cout<<"\n1.输出每个学生的成绩信息    2.输出某个学科的平均分    3.退出\n\n选择：";
        cin>>ch;
        if(ch==1) averscore(sco,avsco,num);
        if(ch==2)
        {
            int n=0;
            cout<<"\n请输入要查询的学科(数字1~5)：";
            cin>>n;
            cout<<"\n学科"<<n<<"的平均分为："<<avercourse(sco,n)<<endl;
        }
        if(ch==3) break;
        //cout<<"输入 4 继续操作
        int sh=0;
        cout<<"\n\n1.继续      2.退出"<<endl;
        cin>>sh;
        if(sh==1) system("cls");
        else break;

    }


    return 0;
}

void averscore ( int sco[][cls] ,int avsco[stu] ,int num[stu])
{
    for(int i=0;i<stu;i++)
    {
        int all=0;
        cout<<"学生学号:"<<num[i]<<"\n成绩：";
        for(int j=0;j<cls;j++)
        {
            cout<<sco[i][j]<<"  ";
            all=all+sco[i][j];
        }
        cout<<"平均分："<<all/cls<<endl<<endl;
    }

}

int avercourse( int sco[][cls],int n )
{
    int all=0;
    for(int i=0;i<cls;i++)all=all+sco[i][n];
    return all/stu;
}
