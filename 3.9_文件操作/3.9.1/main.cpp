/*************************************************************************
    > File Name: main.cpp
    > Author: 刘金明
    > id: 320160939811
    > Created Time: 2018/6/16 20:58:37
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
using namespace std;

char turn(char t,int a);		//字符转换函数
void input();					//输入函数
void read();					//输出函数

int main()
{
	input();
	read();
    return 0;
}

void read()				//二进制文件读取
{
	char f[20];
	cout<<"\n\nplease input the file name:";
	cin>>f;
	char s;
	fstream instuf;
	instuf.open(f,ios::in|ios::binary);		//打开二进制文件
	if(!instuf)
	{
		cerr<<"file could not be open!"<<endl;
		//abort();
	}
    else
    {
        cout<<"the words of the file is:\n"<<endl;
        do
        {
            if(instuf.read( (char *)&s,sizeof(char)))		//读取一个记录
            cout<<turn(s,0);						//将读取的记录解码并输出
        }
        while(instuf);
    }
	instuf.close();							//关闭文件
}

void input()				//二进制输入文件
{
	ofstream outstuf("file.dat",ios::binary);	//默认打开或创建当前文件夹的file.dat文件
	if(!outstuf)
	{
		cerr<<"file could not be open!"<<endl;
		//abort();
	}
	else
    {
	cout<<"\nplease input the words:"<<endl;
    char s;
	while(true)
	{
		s=turn(getchar(),1);					//字符输入并加密
		if(s!='#') outstuf.write((char*)&s,sizeof(char));
		else break;
	}
	outstuf.close();
    char f[20],ch;
    cout<<"\nthe file path is \"3.9.1\\file.dat\" would you like to save a new path? (y/n):";
    cin>>ch;
    if(ch=='y'||ch=='Y')			//用户选择保存的路径和名字
    {
        cout<<"please input the new path or name:";
        cin>>f;
        if(rename("file.dat",f)==0) cout<<"successful save!";
        else cout<<"sorry! the path or name is wrong!!";
    }
    }

}

char turn(char t,int a)				//字符转换函数，参数 a 代表解码还是加密
{
	int th,h=0;
	if('A'<=t&&t<='Z')th=t-64;		      	//将字母转换成1~26的数字，方便+4或-4后的取模
	else if('a'<=t&&t<='z'){th=t-96; h=32;}		//h的值用来保存字母大小写格式
	else return t;							//如果该字符不是字母，则直接返回

	if(a==1)		//a 的值为1 进行加密
    {
        th=(th+4)%26;	//th 值+4后模26，保证都在26个字母的范围
        if(th==0)th=26;
        return (char)(th+64+h);			//+h保证字母大小写格式正确
    }
	else		//a值不为1，进行解码
	{
		if(th>4) return (char)(th+60+h);
		else return (char)(86+th+h);		//对于前4个字母的解码
	}
}


