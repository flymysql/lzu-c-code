/*
 * 3.4.1  日期结构体
 * 计算年月日 是星期几
 * 刘金明 320160939911
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

struct data
{
    int year;
    int month;
    int day;
};
int getweek(int year,int month,int day)
{
    //储存每月天数的数组
    int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    //总天数计算
    int days=(year-1)*365+(year-1)/4-(year-1)/100+(year-1)/400;
        for(int i=0;i<month-1;i++){
        if(i==1&&(( year%4==0 && year%100!=0 )||(year%400==0))){
            days=days+29;
        }
        else days=days+months[i];
    }
    //返回星期几
    int week=(days+day)%7;
    if(week==0)week=7;
    return week;
}

//日期错误提示函数
void err()
{
    cout<<"\n错误日期，请检查是否合理(比如2月29是否年，31日是否小月)\n";
}
int main()
{
    data today;
    data *t=&today;
    cout<<"please input the data:year month day\ninput:";
    cin>>t->year>>t->month>>t->day;
    //字符数组存储星期的汉字表示（第一个元素为空因为从星期一开始）
    char week[][7]={"","一","二","三","四","五","六","日"};
    while(t->year!= 0 && t->month!=0 && t->day!= 0)
    {
        int error=1;    //表示日期是否错误的变量
        if(t->month>0&&t->month<=12&&t->day<=31&&t->year<=2018&&t->year>=0){
            if(t->month==2&&t->day==29&&!(( t->year%4==0 && t->year%100!=0 )||(t->year%400==0)))
            {
                err(); error=0;
            }
            if(t->day==31&&!(945%t->month==0||t->month==10||t->month==8||t->month==12))
            {
                err();error=0;
            }
            if(error)
            {
                cout<<t->year<<" 年"<<t->month<<" 月"<<t->day
                    <<" 日是星期"<<week[getweek(t->year,t->month,t->day)];
            }
        }
        else err();
        cout<< "\n\nplease enter year month day:\ninput(0 0 0 exit): ";
        cin>>t->year>> t->month>>t->day;
        //system("cls");  //清屏函数，可用，看习惯
    }
    return 0;
}