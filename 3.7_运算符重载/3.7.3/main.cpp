#include <iostream>
#include <string.h>
using namespace std;

class student
{
private:
	char name[10];
	int deg1,deg2,deg3;
public:
    student(){deg1=deg2=deg3=0;}
    student(char na[],int d1,int d2,int d3)
    {
        strcpy(name,na);
        deg1=d1;
        deg2=d2;
        deg3=d3;
    }
    friend student operator+(const student s1,const student s2);
   // friend void avg(student &s,int n);
    int get_deg1(){return deg1;}
    int get_deg2(){return deg2;}
    int get_deg3(){return deg3;}
    void set_deg(int a,int b,int c)
    {
        deg1=a;
        deg2=b;
        deg3=c;
    }
    void set_name(char *n)
    {
        for(int i=0;*(n+i)!='\0';i++)name[i]=*(n+i);
    }

}
student operator+ (const student s1,const student s2)
{
    student a;
    int d1=s1.get_deg1()+s2.get_deg1();
    int d2=s1.get_deg2()+s2.get_deg2();
    int d3=s1.get_deg3()+s2.get_deg3();
    a.set_deg(d1,d2,d3);
    a.set_name("new_stu");
    return a;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
