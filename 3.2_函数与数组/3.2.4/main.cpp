#include <iostream>
using namespace std;

void mux(int a[][3],int b[][3],int c[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}
void print(int a[3][3])
{
    for(int i=0;i<3;i++)
    {
        cout<<" | ";
        for(int j=0;j<3;j++)cout<<a[i][j]<<" ";
        cout<<"|\n";
    }
}
int main() {
    int a[3][3]={0},b[3][3]={0},c[3][3]={0};
    cout<<"请输入一个3X3的矩阵a，每行三个数空格隔开，回车换行\n";
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>a[i][j];
    cout<<"\n请输入一个3X3的矩阵b，每行三个数空格隔开，回车换行\n";
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>b[i][j];
    print(a);
    cout<<"     X\n";
    print(b);
    cout<<"     ||\n";
    mux(a,b,c);
    print(c);
    return 0;
}
