/*
*3.3.2 ѧ���ɼ�����
*������  320160939811
*/

#include <iostream>
#include <stdlib.h>
using namespace std;
#define stu 5           //����ѧ������
#define cls 5           //����γ���
int avercourse( int sco[][cls],int n );
void averscore ( int sco[][cls] ,int avsco[stu] ,int num[stu]);
int main()
{
    int sco[stu][cls]={{71,82,63,94,55},{52,63,94,55,76},{82,83,64,95,76},{62,63,54,55,56},{92,93,94,95,96}};
    int num[stu]={20160901, 20160902, 20160903, 20160904, 20160905},avsco[stu]={0};
   /*  for(int i=0;i<stu;i++)
    {
        cout<<"�� "<<i<<" ��ѧ��ѧ�ţ�";
        cin>>num[i];
        cout<<"\n����ѧ�Ƴɼ���";
        for(int j=0;j<cls;j++)cin>>sco[i][j];
        cout<<endl;
    }
    */
    int ch=0;
    while(ch!=3)
    {
        cout<<"��¼��5��ѧ�������ѧ�Ƴɼ�,����������ѡ�������"<<endl;
        cout<<"\n1.���ÿ��ѧ���ĳɼ���Ϣ    2.���ĳ��ѧ�Ƶ�ƽ����    3.�˳�\n\nѡ��";
        cin>>ch;
        if(ch==1) averscore(sco,avsco,num);
        if(ch==2)
        {
            int n=0;
            cout<<"\n������Ҫ��ѯ��ѧ��(����1~5)��";
            cin>>n;
            cout<<"\nѧ��"<<n<<"��ƽ����Ϊ��"<<avercourse(sco,n)<<endl;
        }
        if(ch==3) break;
        //cout<<"���� 4 ��������
        int sh=0;
        cout<<"\n\n1.����      2.�˳�"<<endl;
        cin>>sh;
        if(sh==1) system("cls");
        else break;

    }


    return 0;
}

void averscore ( int sco[][cls] ,int avsco[stu] ,int num[stu])
{
    for(int i=0;i<stu;i++)
    {
        int all=0;
        cout<<"ѧ��ѧ��:"<<num[i]<<"\n�ɼ���";
        for(int j=0;j<cls;j++)
        {
            cout<<sco[i][j]<<"  ";
            all=all+sco[i][j];
        }
        cout<<"ƽ���֣�"<<all/cls<<endl<<endl;
    }

}

int avercourse( int sco[][cls],int n )
{
    int all=0;
    for(int i=0;i<cls;i++)all=all+sco[i][n];
    return all/stu;
}
