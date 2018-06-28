/*
 * 3.1.6 星期几计算
 * 刘金明 320160939811
 */

#include <iostream>
using namespace std;
int getweek(int year,int month,int day)
{
    int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int days=(year-1)*365+(year-1)/4-(year-1)/100+(year-1)/400;
    for(int i=0;i<month-1;i++){
        if(i==1&&(( year%4==0 && year%100!=0 )||(year%400==0))){
            days=days+29;
        }
        else days=days+months[i];
    }
    int week=(days+day)%7;
    if(week==0)week=7;
    return week;
}
void err()
{
    cout<<"日期输入有误（例如月份不能大于12，非闰年不得有2 月29 日，小月不得有4 月31 日）\n";
}

int main()
{
    int year,month,day;
    char week[][7]={"","一","二","三","四","五","六","七"};
    cout<< "请输入年月日,空格隔开: ";
    cin>>year>> month>>day; //首先输入三个数： 年 月 日
    while(year!= 0 && month!=0 && day!= 0)
    {
        //具体计算语句
        int error=1;
        if(month>0&&month<=12&&day<=31&&year<=2018&&year>=0){
           if(month==2&&day==29&&!(( year%4==0 && year%100!=0 )||(year%400==0))) { err(); error=0;}
           if(day==31&&!(945%month==0||month==10||month==8||month==12)) {err();error=0;}
           if(error){
                cout<<year<<" 年"<<month<<" 月"<<day<<" 日是星期"<<week[getweek(year,month,day)];

           }

        }
        //本次循环结束前再次输入三个数据（年月 日），为下次循环计算做准备
        else err();
        cout<< "\n\n请输入年月日,空格隔开: ";
        cin>>year>> month>>day;
    }
    return 0;
}
