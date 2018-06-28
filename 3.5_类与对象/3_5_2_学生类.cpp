/*
 * 3.5.2  学生成绩管理
 * 刘金明 320160939811
 *
 */

#include<iostream>
#include<string.h>
using namespace std;
class student
{
private://学号、姓名、性别、出生日期、年级、班级、院系、专业；
	int number;
	char name[10];
	char sex[4];
	int day;int month;int year;
	char classs[12];
	char grade[12];
	char depart[12];
	char major[12];
public:
	student(){}
	student(int num,char n[10],	char s[4],int d,int m,int y,char clas[12],char gra[4],char depar[12],char maj[12])
	{
		number=num;
		strcpy(name,n);
		strcpy(sex,s);
		day=d;
		month=m;
		year=y;
		strcpy(classs,clas);
		strcpy(grade,gra);
		strcpy(depart,depar);
		strcpy(major,maj);
	}
	void show()
	{
	    int i=0;
		cout<<"学号："<<number<<endl;
		cout<<"姓名：";
		for(int i=0;name[i]!='\0';i++)
			cout<<name[i];
        cout<<endl<<"性别：";
        for(int i=0;sex[i]!='\0';i++)
			cout<<sex[i];
		cout<<endl<<"出生日期:"<<day<<"/"<<month<<"/"<<year<<endl;
		cout<<"年级：";
		for(i=0;classs[i]!='\0';i++)
			cout<<classs[i];
		cout<<endl<<"班级：";
		for(i=0;grade[i]!='\0';i++)
			cout<<grade[i];
		cout<<endl<<"院系：";
		for(i=0;i<depart[i]!='\0';i++)
			cout<<depart[i];
		cout<<endl<<"专业：";
		for(i=0;major[i]!='\0';i++)
			cout<<major[i];
		cout<<endl;
	}
	void setinf()
	{
		cout<<"请输入学生信息"<<endl;
		cout<<"学号:";
		cin>>number;
		cout<<"姓名:";
		cin>>name;
		cout<<"性别:";
        cin>>sex;
        cout<<"出生年月日（空格隔开）：";
		cin>>day>>month>>year;
		cout<<"班级:";
        cin>>classs;
		cout<<"年级:";
        cin>>grade;
		cout<<"院系:";
        cin>>depart;
		cout<<"专业:";
        cin>>major;
	}
};
int main()
{
	student s1;
	s1.setinf();
	s1.show();
	return 0;
}
