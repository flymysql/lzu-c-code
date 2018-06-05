/*
* 3.8.1   图形类
 * 在3.6.1的基础上稍作修改
* 刘金明   320160939811
*/

#include<iostream>
using namespace std;
#include<math.h>
class Shape//抽象类，公共基类
{
public:
    virtual double Area()const=0;//计算各对象面积
    virtual double Perim()const=0;//计算各对象周长
    virtual void Show()=0;//输出各对象面积和周长
};
class Rec:public Shape//矩形类
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
    ~Rec()
    {
    }
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
const double PI=3.14159;
class Circle:public Shape//圆类
{
private:
    double Radius;
public:
    Circle(double Radius=0)
    {
        this->Radius=Radius;
    }
    ~Circle()
    {
    }
    double Area() const//圆面积
    {
        return PI*Radius*Radius;
    }
    double Perim() const//圆周长
    {
        return 2*PI*Radius;
    }
    void Show()//输出圆的面积和周长
    {
        cout<<"Area is:"<<Area()<<endl;
        cout<<"Perim is:"<<Perim()<<endl<<endl;
    }
};
class Tri:public Shape//三角形类
{
private:
    double A,B,C;//三角形三边
public:
    Tri(double A=0,double B=0,double C=0)//构造函数
    {
        this->A=A;
        this->B=B;
        this->C=C;
    }
    ~Tri()//析构函数
    {
    }
    double Area() const//三角形面积
    {
        double P;
        P=(A+B+C)/2;
        return sqrt(P*(P-A)*(P-B)*(P-C));
    }
    double Perim() const
    {
        return (A+B+C);
    }
    void Show()
    {
        cout<<"Area is:"<<Area()<<endl;
        cout<<"Perim is:"<<Perim()<<endl<<endl;
    }
};


int main()
{
    double Length,Width,Radius,A,B,C;
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

    loopb:cout<<"请输入圆形的半径:"<<endl;
    cin>>Radius;
    if(Radius<=0)
    {
        cout<<"输入的半径不能构成一个圆!请重新输入!"<<endl;
        goto loopb;
    }
    else
    {
        Circle Cir(Radius);
        Cir.Show();
        cout<<"Tri:"<<endl;
    }


    loopc:cout<<"请输入三角形的三边(空格隔开):"<<endl;
    cin>>A>>B>>C;
    if(A<=0||B<=0||C<=0||(A+B)<=C||(A+C)<=B||(B+C)<=A)//判断是否能构成三角形
    {
        cout<<"输入的三边值不能构成一个三角形!请重新输入!"<<endl;
        goto loopc;
    }
    else
    {
        Tri Tri(A,B,C);
        Tri.Show();
    }
    return 0;
}
