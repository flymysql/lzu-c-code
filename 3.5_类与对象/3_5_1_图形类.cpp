/*
* 3.5.1   ͼ����
* ������   320160939811
*/

#include<iostream>
#include<math.h>
using namespace std;

class point                         //����������
{
public:
    int x;
    int y;
    point(){set_xy(0,0);}       //Ĭ��ֵΪԲ��
    point(int x,int y)
    {
        set_xy(x,y);
    }
    void set_xy(int a,int b)
    {
        x=a;y=b;
    }
};
double get_xy(point a,point b)      //������֮��ľ�����㷽��
{
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}

class Rec                   //������
{
private:
	     double Length;
         double Width;
public:
         Rec(double Length=0,double Width=0)//���캯��
         {
			 this->Length=Length;
             this->Width=Width;
         }
         ~Rec(){}
         double Area() const//�������
         {
             return Length*Width;
         }
         double Perim() const//�����ܳ�
         {
             return 2*(Length+Width);
         }
         void Show()//�������������ܳ�
         {
                   cout<<"Area is:"<<Area()<<endl;
                   cout<<"Perim is:"<<Perim()<<endl<<endl;
         }
};

const double PI=3.14159;        //����е�ֵ
class Circle                    //Բ��
{
private:
         double Radius;
         point center;
public:
         Circle(double Radius=0,point cent=point(0,0))
         {
                   this->Radius=Radius;
                   this->center=cent;
         }
         ~Circle(){}
         double Area() const        //Բ���
         {
                   return PI*Radius*Radius;
         }
         double Perim() const       //Բ�ܳ�
         {
                   return 2*PI*Radius;
         }
         void set_center(int x,int y,int r)
         {
             center.set_xy(x,y);
             this->Radius=r;
         }
         void Show()            //���Բ��������ܳ�
         {
             cout<<"diameter is:"<<2*Radius<<endl;
             cout<<"Area is:"<<Area()<<endl;
             cout<<"Perim is:"<<Perim()<<endl<<endl;
         }
};
class Tri                       //��������
{
private:
         point A,B,C;           //��������������
public:
         Tri(point A,point B,point C)       //���캯��
         {
			 this->A=A;
             this->B=B;
             this->C=C;
         }
         ~Tri()                      //��������
         {
         }
         double Area() const        //���������
         {
             double a=get_xy(A,B),b=get_xy(A,C),c=get_xy(B,C);
			 double P;
             P=(a+b+c)/2;
             return sqrt(P*(P-a)*(P-b)*(P-c));
         }
         double Perim() const
         {
             double a=get_xy(A,B),b=get_xy(A,C),c=get_xy(B,C);
             return (a+b+c);
         }
         void Show()
         {
             cout<<"Area is:"<<Area()<<endl;
             cout<<"Perim is:"<<Perim()<<endl<<endl;
         }
};


int main()
{
	double Length,Width,Radius;
	char s;
	int x,y;
	point a,b,c;
    cout<<"Rec:"<<endl;
    loopa:cout<<"��������εĳ��Ϳ�(�ո����):"<<endl;
    cin>>Length>>Width;
    if(Length<=0||Width<=0)
	{
		cout<<"����ĳ����ܹ���һ������!����������!"<<endl;
		goto loopa;
	}
	else
	{
		Rec Rect(Length,Width);
		Rect.Show();
		cout<<"Circle:"<<endl;
	}

    loopb:cout<<"������Բ�ε�Բ����뾶(����ʾ��:2,-3 4):"<<endl;
    cin>>x>>s>>y>>Radius;
    if(Radius<=0)
	{
		cout<<"����İ뾶���ܹ���һ��Բ!����������!"<<endl;
			goto loopb;
	}
	else
	{
		Circle Cir(Radius,point(x,y));
		Cir.Show();
		cout<<"Tri:"<<endl;
	}

    int x1,y1,x2,y2,x3,y3;
     loopc:cout<<"�����������ε���������ո����(ʾ��:1,1  2,2  3,3):"<<endl;
     cin>>x1>>s>>y1>>x2>>s>>y2>>x3>>s>>y3;
     a=point(x1,y1);
     b=point(x2,y2);
     c=point(x3,y3);
     int A=get_xy(a,b),B=get_xy(a,c),C=get_xy(b,c);
     if(A<=0||B<=0||C<=0||(A+B)<=C||(A+C)<=B||(B+C)<=A)//�ж��Ƿ��ܹ���������
	 {
		 cout<<"���������ֵ���ܹ���һ��������!����������!"<<endl;
		 goto loopc;
	 }
	 else
	 {
		 Tri Tri(a,b,c);
		 Tri.Show();
	 }
	 return 0;
}
