/*
 * 3.5.2  ѧ���ɼ�����
 * ������ 320160939811
 *
 */

#include<iostream>
#include<string.h>
using namespace std;
class student
{
private://ѧ�š��������Ա𡢳������ڡ��꼶���༶��Ժϵ��רҵ��
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
		cout<<"ѧ�ţ�"<<number<<endl;
		cout<<"������";
		for(int i=0;name[i]!='\0';i++)
			cout<<name[i];
        cout<<endl<<"�Ա�";
        for(int i=0;sex[i]!='\0';i++)
			cout<<sex[i];
		cout<<endl<<"��������:"<<day<<"/"<<month<<"/"<<year<<endl;
		cout<<"�꼶��";
		for(i=0;classs[i]!='\0';i++)
			cout<<classs[i];
		cout<<endl<<"�༶��";
		for(i=0;grade[i]!='\0';i++)
			cout<<grade[i];
		cout<<endl<<"Ժϵ��";
		for(i=0;i<depart[i]!='\0';i++)
			cout<<depart[i];
		cout<<endl<<"רҵ��";
		for(i=0;major[i]!='\0';i++)
			cout<<major[i];
		cout<<endl;
	}
	void setinf()
	{
		cout<<"������ѧ����Ϣ"<<endl;
		cout<<"ѧ��:";
		cin>>number;
		cout<<"����:";
		cin>>name;
		cout<<"�Ա�:";
        cin>>sex;
        cout<<"���������գ��ո��������";
		cin>>day>>month>>year;
		cout<<"�༶:";
        cin>>classs;
		cout<<"�꼶:";
        cin>>grade;
		cout<<"Ժϵ:";
        cin>>depart;
		cout<<"רҵ:";
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
