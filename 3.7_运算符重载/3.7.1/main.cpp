/*
 * String类的运算符重载
 * 刘金明：320160939811
 */
#include <iostream>
using namespace std;
class String
{
private:
    char *str;
public:
    //两种构造方法
    String(){str=NULL;}
    String(char *s){str=s;}
    //重载运算符
    friend bool operator>(const String &a,const String &b);
    friend bool operator<(const String &a,const String &b);
    friend bool operator==(const String &a,const String &b);
    char* get_str(){ return str;}
};
//三种比较运算符
bool operator==(const String &a,const String &b)
{
    int i=0;
    while(*(a.str+i)!='\0')
    {
        if(*(a.str+i)!=*(b.str+i))return false;
        i++;
    }
    if(*(a.str+i)=='\0'&&*(b.str+i)=='\0')return true;
    else return false;

}
bool operator<(const String &a,const String &b)
{
    int i=0;
    while(*(a.str+i)!='\0')
    {
        if(*(a.str+i)>*(b.str+i))return false;
        if(*(a.str+i)<*(b.str+i)) return true;
        if(*(b.str+i)=='\0')return false;
        i++;
    }
    if(*(a.str+i)=='\0'&&*(b.str+i)!='\0')return true;
    else return false;
}
bool operator>(const String &a,const String &b)
{
    int i=0;
    while(*(a.str+i)!='\0')
    {
        if(*(a.str+i)<*(b.str+i))return false;
        if(*(a.str+i)>*(b.str+i)) return true;
        if(*(b.str+i)=='\0')return true;
        i++;
    }
    return false;

}

//测试函数
void test(String a,String b)
{
    char cal;
    if(a>b)cal='>';
    if(a<b)cal='<';
    if(a==b)cal='=';
    int i=0;
    while (*(a.get_str()+i)!='\0'){cout<<*(a.get_str()+i);i++;}
    cout<<cal;i=0;
    while (*(b.get_str()+i)!='\0'){cout<<*(b.get_str()+i);i++;}
    cout<<endl;
}
int main() {
    String m,n;
    m="China",n="china";
    test(m,n);
    m="National",n="Computer";
    test(m,n);
    m="Examination",n="Rank";
    test(m,n);
    m="swust",n="swust";
    test(m,n);
    return 0;
}