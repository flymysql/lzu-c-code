/*
 * 3.4.4  通信录
 * 类实现
 */

#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<cmath>
using namespace std;
//联系人总数
int Num;
//建立联系人的类
class Person{
//private成员如下
private:
    char name[20];
    char sex[10];
    char phone[20];
    char email[30];
//public成员如下
public:
    char* get_name();
    char* get_sex();
    char* get_phone();
    char* get_email();
    void set_name();
    void set_sex();
    void set_phone();
    void set_email();
    void show();
    ~Person(){};
};
Person people[300];		//定义对象数组
//功能函数声明
void show_all();
void search_name();
void add();
void modify();
void del_one();
void del_all();
void data_load();
void NOsave_withdraw();
void save__withdraw();
void save_NOwithdraw();
void welcome();
void thanks_for_use();
void first_menu();
int menu();
void work();
//类内函数，返回name
char* Person::get_name(){
    return name;
}
//类内函数，返回sex
char* Person::get_sex(){
    return sex;
}
//类内函数，返回phone
char* Person::get_phone(){
    return phone;
}
//类内函数，返回email
char* Person::get_email(){
    return email;
}
//类内函数，设置name
void Person::set_name(){
    memset(name,'\0',20);
    cin>>name;
}
//类内函数，设置sex
void Person::set_sex(){
    memset(sex,'\0',10);
    cin>>sex;
}
//类内函数，，设置phone
void Person::set_phone(){
    memset(phone,'\0',20);
    cin>>phone;
}
//类内函数，，设置email
void Person::set_email(){
    memset(email,'\0',30);
    cin>>email;
}
//类内函数，打印全部私有成员
void Person::show(){
    cout<<"name:"<<name<<endl;
    cout<<"sex:"<<sex<<endl;
    cout<<"phone:"<<phone<<endl;
    cout<<"email:"<<email<<endl;
}
//打印所有联系人
void show_all(){
    int i,flag_stop=0;
    for(i=0;i<Num;i++){
        cout<<"此联系人详细信息如下"<<endl;
        people[i].show();
    }
    cout<<"此系统共有"<<Num<<"人信息。"<<endl;
    if(flag_stop==0)
        cout<<"全部信息已输出！"<<endl;
    cout<<endl;
    cout<<"请按任意键继续..."<<endl;
    getch();
}
//搜索联系人
void search_name(){
    char a[20];
    int i,flag_find=0;
    cout<<"请输入您要查询的人名："<<endl;
    cin>>a;
    for(i=0;i<Num;i++){
        if(!strcmp(people[i].get_name(),a)){
            cout<<"此联系人详细信息如下"<<endl;
            people[i].show();
            flag_find=1;
        }
    }
    if(flag_find==0){
        cout<<"对不起，没有此人！"<<endl<<endl;
    }else{
        cout<<endl;
    }
    cout<<"请按任意键继续..."<<endl;
    getch();
}
//增加一位联系人
void add(){
    cout<<"name:"<<endl;
    people[Num].set_name();
    cout<<"sex:"<<endl;
    people[Num].set_sex();
    cout<<"phone:"<<endl;
    people[Num].set_phone();
    cout<<"email:"<<endl;
    people[Num].set_email();
    cout<<"输入成功！"<<endl<<endl;
    Num++;
    cout<<"按任意键继续..."<<endl;
    getch();
}
//修改联系人
void modify(){
    char a[20],s;
    int flag_find=0,i;
    cout<<"请输入要修改的名字："<<endl;
    cin>>a;
    for(i=0;i<Num;i++){
        if(!strcmp(people[i].get_name(),a)){
            cout<<"此联系人详细信息如下"<<endl;
            people[i].show();
            cout<<"是否要修改姓名？(y/n)"<<endl;
            cin>>s;
            if(s=='y'||s=='Y'){
                cout<<"name:";
                people[i].set_name();
            }
            cout<<"是否要修改性别？(y/n)"<<endl;
            cin>>s;
            if(s=='y'||s=='Y'){
                cout<<"sex:";
                people[i].set_sex();
            }
            cout<<"是否要修改电话？(y/n)"<<endl;
            cin>>s;
            if(s=='y'||s=='Y'){
                cout<<"phone:";
                people[i].set_phone();
            }
            cout<<"是否要修改邮箱？(y/n)"<<endl;
            cin>>s;
            if(s=='y'||s=='Y'){
                cout<<"email:";
                people[i].set_email();
            }
            cout<<endl;
            flag_find=1;
        }
    }
    if(flag_find==0){
        cout<<"对不起，没有此人！"<<endl;
    }
    cout<<"按任意键继续..."<<endl;
    getch();
}
//删除一个联系人
void del_one(){
    char a[20],c;
    int flag_find=0,i,j;
    cout<<"输入要删除的名字："<<endl;
    cin>>a;
    for(i=0;i<Num;i++){
        if(!strcmp(people[i].get_name(),a)){
            cout<<"此联系人详细信息如下"<<endl;
            people[i].show();
            cout<<"是否要删除？(y/n)"<<endl;
            cin>>c;
            if(c=='Y'||c=='y'){
                for(j=i;j<Num-1;j++){
                    strcpy(people[j].get_name(),people[j+1].get_name());
                    strcpy(people[j].get_sex(),people[j+1].get_sex());
                    strcpy(people[j].get_phone(),people[j+1].get_phone());
                    strcpy(people[j].get_email(),people[j+1].get_email());
                }
                memset(people[Num-1].get_name(),'\0',20);
                memset(people[Num-1].get_sex(),'\0',10);
                memset(people[Num-1].get_phone(),'\0',20);
                memset(people[Num-1].get_email(),'\0',30);
                Num--;
            }
            flag_find=1;
            cout<<endl;
        }
    }
    if(flag_find==0){
        cout<<"对不起，没有此人！"<<endl<<endl;
    }else{
        cout<<endl;
    }
    cout<<"请按任意键继续..."<<endl;
    getch();
}
//删除全部联系人
void del_all(){
    char c;
    cout<<"是否要全部删除？(y/n)"<<endl;
    cin>>c;
    if(c=='Y'||c=='y'){
        Num=0;
        fstream outfile;
        outfile.open("address_list.dat",ios::trunc|ios::out|ios::binary);
        outfile.close();
        cout<<endl<<"删除成功！"<<endl;
    }
    cout<<"请按任意键继续..."<<endl;
    getch();
}
//载入数据
void data_load(){
    int i=0;
    fstream infile;
    infile.open("address_list.dat",ios::in|ios::binary);
    while(infile){
        infile.read(people[i].get_name(),20);
        infile.read(people[i].get_sex(),10);
        infile.read(people[i].get_phone(),20);
        infile.read(people[i].get_email(),30);
        i++;
    }
    i--;
    Num=i;  //记录联系人个数
    infile.close();
}
//不保存并退出
void NOsave_withdraw(){
    thanks_for_use();
    exit(0);
}
//保存并退出
void save_withdraw(){
    int i;
    fstream outfile;
    outfile.open("address_list.dat",ios::trunc|ios::out|ios::binary);
    for(i=0;i<Num;i++){
        outfile.write(people[i].get_name(),20);
        outfile.write(people[i].get_sex(),10);
        outfile.write(people[i].get_phone(),20);
        outfile.write(people[i].get_email(),30);
    }
    outfile.close();
    thanks_for_use();
    exit(0);
}
//保存不退出
void save_NOwithdraw(){
    int i;
    fstream outfile;
    outfile.open("address_list.dat",ios::trunc|ios::out|ios::binary);
    for(i=0;i<Num;i++){
        outfile.write(people[i].get_name(),20);
        outfile.write(people[i].get_sex(),10);
        outfile.write(people[i].get_phone(),20);
        outfile.write(people[i].get_email(),30);
    }
    outfile.close();
    cout<<"保存成功！"<<endl<<endl;
    cout<<"按任意键继续..."<<endl;
    getch();
}

void thanks_for_use(){
    system("cls");
    double x,y;
    int H=3;
    for(y=-4;y<=0;y+=0.3)
    {
        for(x=-4;x<=4;x+= 0.2)
            if(fabs(sqrt(x*x+y*y)-H*sin(2*atan(y/x)))<= 1
               ||fabs(sqrt(x*x+y*y)-H*sin(2*atan(-y/x)))<= 1)
                printf("*");
            else
                printf(" ");
        printf("\n");
    }
    for(y=-1;y<=0;y+=0.2)  {
        for(x=-4;x<=4;x+=0.2)
            if(fabs(y)-0.65*x*x>=0.2)
                printf("*");
            else
                printf(" ");
        printf("\n");
    }
    cout<<"                谢谢使用！"<<endl;
}
//主菜单页面输出
void first_menu(){
    system("cls");
    cout<<"                 主菜单                 "<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"查询F  增加A  修改M  删除D  退出W  保存S"<<endl;
    cout<<"----------------------------------------"<<endl;
}
//菜单选择
int menu(){
    char s,t;
    int choice;
    while(true){
        while(true){
            first_menu();
            cin>>s;
            switch(s){
                case 'F':
                    cout<<"a 显示全部信息"<<endl<<"b 查询某人信息"<<endl;
                    cin>>t;
                    if(t=='a'||t=='A'){
                        choice=1;
                    }else if(t=='b'||t=='B'){
                        choice=2;
                    }else{
                        choice=0;
                    }
                    break;
                case 'f':
                    cout<<"a 显示全部信息"<<endl<<"b 查询某人信息"<<endl;
                    cin>>t;
                    if(t=='a'||t=='A'){
                        choice=1;
                    }else if(t=='b'||t=='B'){
                        choice=2;
                    }else{
                        choice=0;
                    }
                    break;
                case 'A':
                    choice=3;
                    break;
                case 'a':
                    choice=3;
                    break;
                case 'M':
                    choice=4;
                    break;
                case 'm':
                    choice=4;
                    break;
                case 'D':
                    cout<<"a 删除某人信息"<<endl<<"b 全部删除"<<endl;
                    cin>>t;
                    if(t=='a'||t=='A'){
                        choice=5;
                    }else if(t=='b'||t=='B'){
                        choice=6;
                    }else{
                        choice=0;
                    }
                    break;
                case 'd':
                    cout<<"a 删除某人信息"<<endl<<"b 全部删除"<<endl;
                    cin>>t;
                    if(t=='a'||t=='A'){
                        choice=5;
                    }else if(t=='b'||t=='B'){
                        choice=6;
                    }else{
                        choice=0;
                    }
                    break;
                case 'W':
                    cout<<"a 退出不保存"<<endl<<"b 退出并保存"<<endl;
                    cin>>t;
                    if(t=='a'||t=='A'){
                        choice=7;
                    }else if(t=='b'||t=='B'){
                        choice=8;
                    }else{
                        choice=0;
                    }
                    break;
                case 'w':
                    cout<<"a 退出不保存"<<endl<<"b 退出并保存"<<endl;
                    cin>>t;
                    if(t=='a'||t=='A'){
                        choice=7;
                    }else if(t=='b'||t=='B'){
                        choice=8;
                    }else{
                        choice=0;
                    }
                    break;
                case 'S':
                    choice=9;
                    break;
                case 's':
                    choice=9;
                    break;
                default :{
                    cout<<"输入错误，请重新选择功能!"<<endl;
                    cout<<"按任意键继续..."<<endl;
                    getch();
                }
            }
            if(s=='F'||s=='f'||s=='A'||s=='a'||s=='M'||s=='m'||s=='D'||s=='d'||s=='W'||s=='w'||s=='S'||s=='s'){
                break;
            }
        }
        if(choice==0){
            cout<<"输入错误，请重新选择功能!"<<endl;
            cout<<"按任意键继续..."<<endl;
            getch();
        }else{
            break;
        }
    }
    return choice;
}
//所有功能
void work(){
    int choice;
    Num=0;
    data_load();
    while(true){
        choice=menu();
        switch(choice){
            case 1: show_all();
                break;
            case 2: search_name();
                break;
            case 3: add();
                break;
            case 4: modify();
                break;
            case 5: del_one();
                break;
            case 6: del_all();
                break;
            case 7: NOsave_withdraw();
                break;
            case 8: save_withdraw();
                break;
            case 9: save_NOwithdraw();
                break;
            default : ;
        }
    }
}
//主函数
int main()
{

    work();		//所有功能
    return 0;
}
