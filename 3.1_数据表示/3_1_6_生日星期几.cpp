/*
 * 3.1.6 ���ڼ�����
 * ������ 320160939811
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
    cout<<"�����������������·ݲ��ܴ���12�������겻����2 ��29 �գ�С�²�����4 ��31 �գ�\n";
}

int main()
{
    int year,month,day;
    char week[][7]={"","һ","��","��","��","��","��","��"};
    cout<< "������������,�ո����: ";
    cin>>year>> month>>day; //���������������� �� �� ��
    while(year!= 0 && month!=0 && day!= 0)
    {
        //����������
        int error=1;
        if(month>0&&month<=12&&day<=31&&year<=2018&&year>=0){
           if(month==2&&day==29&&!(( year%4==0 && year%100!=0 )||(year%400==0))) { err(); error=0;}
           if(day==31&&!(945%month==0||month==10||month==8||month==12)) {err();error=0;}
           if(error){
                cout<<year<<" ��"<<month<<" ��"<<day<<" ��������"<<week[getweek(year,month,day)];

           }

        }
        //����ѭ������ǰ�ٴ������������ݣ����� �գ���Ϊ�´�ѭ��������׼��
        else err();
        cout<< "\n\n������������,�ո����: ";
        cin>>year>> month>>day;
    }
    return 0;
}
