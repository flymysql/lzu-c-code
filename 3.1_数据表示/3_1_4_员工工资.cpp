#include <iostream>

using namespace std;

int main()
{
    int hours,wage;
    cout<<"Please input employee’s work time and wage_per_hour:";
    cin>>hours>>wage;
    if(hours>0&&wage>0&&hours<168)   //判断数据合理性
    {
        if(hours<=40)wage*=hours;      //分情况计算
        else if(hours>40&&hours<60)wage=40*wage+(hours-40)*1.5*wage;
        else wage=40*wage+30*wage+(hours-60)*wage*3;
        cout<<"The employee’s wage :"<<wage;
    }
    else {
    cout<<"\nyour number is wrong,input the real number"<<endl;
    main();        //输入数字逻辑不正确时，重新使用该函数
    }
    return 0;
}
