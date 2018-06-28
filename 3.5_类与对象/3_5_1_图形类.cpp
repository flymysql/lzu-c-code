/*
* 3.5.1   图形类
* 刘金明   320160939811
*/

#include<iostream>
#include<math.h>
using namespace std;

class point                         //顶点坐标类
{
public:
    int x;
    int y;
    point(){set_xy(0,0);}       //默认值为圆心
    point(int x,int y)
    {
        set_xy(x,y);
    }
    void set_xy(int a,int b)
    {
        x=a;y=b;
    }
};
double get_xy(point a,point b)      //两坐标之间的距离计算方法
{
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}

class Rec                   //矩形类
{
private:
	     double Length;
         double Width;
public:
         Rec(double Length=0,double Width=0)//构造函数
         {
			 this->Length=Length;
             this->Width=Width;
         }
         ~Rec(){}
         double Area() const//矩形面积
         {
             return Length*Width;
         }
         double Perim() const//矩形周长
         {
             return 2*(Length+Width);
         }
         void Show()//输出矩形面积和周长
         {
                   cout<<"Area is:"<<Area()<<endl;
                   cout<<"Perim is:"<<Perim()<<endl<<endl;
         }
};

const double PI=3.14159;        //定义π的值
class Circle                    //圆类
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
         double Area() const        //圆面积
         {
                   return PI*Radius*Radius;
         }
         double Perim() const       //圆周长
         {
                   return 2*PI*Radius;
         }
         void set_center(int x,int y,int r)
         {
             center.set_xy(x,y);
             this->Radius=r;
         }
         void Show()            //输出圆的面积和周长
         {
             cout<<"diameter is:"<<2*Radius<<endl;
             cout<<"Area is:"<<Area()<<endl;
             cout<<"Perim is:"<<Perim()<<endl<<endl;
         }
};
class Tri                       //三角形类
{
private:
         point A,B,C;           //三角形三个顶点
public:
         Tri(point A,point B,point C)       //构造函数
         {
			 this->A=A;
             this->B=B;
             this->C=C;
         }
         ~Tri()                      //析构函数
         {
         }
         double Area() const        //三角形面积
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
    loopa:cout<<"请输入矩形的长和宽(空格隔开):"<<endl;
    cin>>Length>>Width;
    if(Length<=0||Width<=0)
	{
		cout<<"输入的长宽不能构成一个矩形!请重新输入!"<<endl;
		goto loopa;
	}
	else
	{
		Rec Rect(Length,Width);
		Rect.Show();
		cout<<"Circle:"<<endl;
	}

    loopb:cout<<"请输入圆形的圆心与半径(输入示例:2,-3 4):"<<endl;
    cin>>x>>s>>y>>Radius;
    if(Radius<=0)
	{
		cout<<"输入的半径不能构成一个圆!请重新输入!"<<endl;
			goto loopb;
	}
	else
	{
		Circle Cir(Radius,point(x,y));
		Cir.Show();
		cout<<"Tri:"<<endl;
	}

    int x1,y1,x2,y2,x3,y3;
     loopc:cout<<"请输入三角形的三个顶点空格隔开(示例:1,1  2,2  3,3):"<<endl;
     cin>>x1>>s>>y1>>x2>>s>>y2>>x3>>s>>y3;
     a=point(x1,y1);
     b=point(x2,y2);
     c=point(x3,y3);
     int A=get_xy(a,b),B=get_xy(a,c),C=get_xy(b,c);
     if(A<=0||B<=0||C<=0||(A+B)<=C||(A+C)<=B||(B+C)<=A)//判断是否能构成三角形
	 {
		 cout<<"输入的三边值不能构成一个三角形!请重新输入!"<<endl;
		 goto loopc;
	 }
	 else
	 {
		 Tri Tri(a,b,c);
		 Tri.Show();
	 }
	 return 0;
}
