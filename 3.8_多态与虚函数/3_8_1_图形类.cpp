/*
* 3.8.1   ͼ����
 * ��3.6.1�Ļ����������޸�
* ������   320160939811
*/

#include<iostream>
using namespace std;
#include<math.h>
class Shape//�����࣬��������
{
public:
    virtual double Area()const=0;//������������
    virtual double Perim()const=0;//����������ܳ�
    virtual void Show()=0;//���������������ܳ�
};
class Rec:public Shape//������
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
    ~Rec()
    {
    }
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
const double PI=3.14159;
class Circle:public Shape//Բ��
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
    double Area() const//Բ���
    {
        return PI*Radius*Radius;
    }
    double Perim() const//Բ�ܳ�
    {
        return 2*PI*Radius;
    }
    void Show()//���Բ��������ܳ�
    {
        cout<<"Area is:"<<Area()<<endl;
        cout<<"Perim is:"<<Perim()<<endl<<endl;
    }
};
class Tri:public Shape//��������
{
private:
    double A,B,C;//����������
public:
    Tri(double A=0,double B=0,double C=0)//���캯��
    {
        this->A=A;
        this->B=B;
        this->C=C;
    }
    ~Tri()//��������
    {
    }
    double Area() const//���������
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

    loopb:cout<<"������Բ�εİ뾶:"<<endl;
    cin>>Radius;
    if(Radius<=0)
    {
        cout<<"����İ뾶���ܹ���һ��Բ!����������!"<<endl;
        goto loopb;
    }
    else
    {
        Circle Cir(Radius);
        Cir.Show();
        cout<<"Tri:"<<endl;
    }


    loopc:cout<<"�����������ε�����(�ո����):"<<endl;
    cin>>A>>B>>C;
    if(A<=0||B<=0||C<=0||(A+B)<=C||(A+C)<=B||(B+C)<=A)//�ж��Ƿ��ܹ���������
    {
        cout<<"���������ֵ���ܹ���һ��������!����������!"<<endl;
        goto loopc;
    }
    else
    {
        Tri Tri(A,B,C);
        Tri.Show();
    }
    return 0;
}
