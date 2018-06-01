/*
 * 3.4.4  ͨ��¼
 * ��ʵ��
 */

#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<cmath>
using namespace std;
//��ϵ������
int Num;
//������ϵ�˵���
class Person{
//private��Ա����
private:
    char name[20];
    char sex[10];
    char phone[20];
    char email[30];
//public��Ա����
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
Person people[300];		//�����������
//���ܺ�������
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
//���ں���������name
char* Person::get_name(){
    return name;
}
//���ں���������sex
char* Person::get_sex(){
    return sex;
}
//���ں���������phone
char* Person::get_phone(){
    return phone;
}
//���ں���������email
char* Person::get_email(){
    return email;
}
//���ں���������name
void Person::set_name(){
    memset(name,'\0',20);
    cin>>name;
}
//���ں���������sex
void Person::set_sex(){
    memset(sex,'\0',10);
    cin>>sex;
}
//���ں�����������phone
void Person::set_phone(){
    memset(phone,'\0',20);
    cin>>phone;
}
//���ں�����������email
void Person::set_email(){
    memset(email,'\0',30);
    cin>>email;
}
//���ں�������ӡȫ��˽�г�Ա
void Person::show(){
    cout<<"name:"<<name<<endl;
    cout<<"sex:"<<sex<<endl;
    cout<<"phone:"<<phone<<endl;
    cout<<"email:"<<email<<endl;
}
//��ӡ������ϵ��
void show_all(){
    int i,flag_stop=0;
    for(i=0;i<Num;i++){
        cout<<"����ϵ����ϸ��Ϣ����"<<endl;
        people[i].show();
    }
    cout<<"��ϵͳ����"<<Num<<"����Ϣ��"<<endl;
    if(flag_stop==0)
        cout<<"ȫ����Ϣ�������"<<endl;
    cout<<endl;
    cout<<"�밴���������..."<<endl;
    getch();
}
//������ϵ��
void search_name(){
    char a[20];
    int i,flag_find=0;
    cout<<"��������Ҫ��ѯ��������"<<endl;
    cin>>a;
    for(i=0;i<Num;i++){
        if(!strcmp(people[i].get_name(),a)){
            cout<<"����ϵ����ϸ��Ϣ����"<<endl;
            people[i].show();
            flag_find=1;
        }
    }
    if(flag_find==0){
        cout<<"�Բ���û�д��ˣ�"<<endl<<endl;
    }else{
        cout<<endl;
    }
    cout<<"�밴���������..."<<endl;
    getch();
}
//����һλ��ϵ��
void add(){
    cout<<"name:"<<endl;
    people[Num].set_name();
    cout<<"sex:"<<endl;
    people[Num].set_sex();
    cout<<"phone:"<<endl;
    people[Num].set_phone();
    cout<<"email:"<<endl;
    people[Num].set_email();
    cout<<"����ɹ���"<<endl<<endl;
    Num++;
    cout<<"�����������..."<<endl;
    getch();
}
//�޸���ϵ��
void modify(){
    char a[20],s;
    int flag_find=0,i;
    cout<<"������Ҫ�޸ĵ����֣�"<<endl;
    cin>>a;
    for(i=0;i<Num;i++){
        if(!strcmp(people[i].get_name(),a)){
            cout<<"����ϵ����ϸ��Ϣ����"<<endl;
            people[i].show();
            cout<<"�Ƿ�Ҫ�޸�������(y/n)"<<endl;
            cin>>s;
            if(s=='y'||s=='Y'){
                cout<<"name:";
                people[i].set_name();
            }
            cout<<"�Ƿ�Ҫ�޸��Ա�(y/n)"<<endl;
            cin>>s;
            if(s=='y'||s=='Y'){
                cout<<"sex:";
                people[i].set_sex();
            }
            cout<<"�Ƿ�Ҫ�޸ĵ绰��(y/n)"<<endl;
            cin>>s;
            if(s=='y'||s=='Y'){
                cout<<"phone:";
                people[i].set_phone();
            }
            cout<<"�Ƿ�Ҫ�޸����䣿(y/n)"<<endl;
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
        cout<<"�Բ���û�д��ˣ�"<<endl;
    }
    cout<<"�����������..."<<endl;
    getch();
}
//ɾ��һ����ϵ��
void del_one(){
    char a[20],c;
    int flag_find=0,i,j;
    cout<<"����Ҫɾ�������֣�"<<endl;
    cin>>a;
    for(i=0;i<Num;i++){
        if(!strcmp(people[i].get_name(),a)){
            cout<<"����ϵ����ϸ��Ϣ����"<<endl;
            people[i].show();
            cout<<"�Ƿ�Ҫɾ����(y/n)"<<endl;
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
        cout<<"�Բ���û�д��ˣ�"<<endl<<endl;
    }else{
        cout<<endl;
    }
    cout<<"�밴���������..."<<endl;
    getch();
}
//ɾ��ȫ����ϵ��
void del_all(){
    char c;
    cout<<"�Ƿ�Ҫȫ��ɾ����(y/n)"<<endl;
    cin>>c;
    if(c=='Y'||c=='y'){
        Num=0;
        fstream outfile;
        outfile.open("address_list.dat",ios::trunc|ios::out|ios::binary);
        outfile.close();
        cout<<endl<<"ɾ���ɹ���"<<endl;
    }
    cout<<"�밴���������..."<<endl;
    getch();
}
//��������
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
    Num=i;  //��¼��ϵ�˸���
    infile.close();
}
//�����沢�˳�
void NOsave_withdraw(){
    thanks_for_use();
    exit(0);
}
//���沢�˳�
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
//���治�˳�
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
    cout<<"����ɹ���"<<endl<<endl;
    cout<<"�����������..."<<endl;
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
    cout<<"                ллʹ�ã�"<<endl;
}
//���˵�ҳ�����
void first_menu(){
    system("cls");
    cout<<"                 ���˵�                 "<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"��ѯF  ����A  �޸�M  ɾ��D  �˳�W  ����S"<<endl;
    cout<<"----------------------------------------"<<endl;
}
//�˵�ѡ��
int menu(){
    char s,t;
    int choice;
    while(true){
        while(true){
            first_menu();
            cin>>s;
            switch(s){
                case 'F':
                    cout<<"a ��ʾȫ����Ϣ"<<endl<<"b ��ѯĳ����Ϣ"<<endl;
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
                    cout<<"a ��ʾȫ����Ϣ"<<endl<<"b ��ѯĳ����Ϣ"<<endl;
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
                    cout<<"a ɾ��ĳ����Ϣ"<<endl<<"b ȫ��ɾ��"<<endl;
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
                    cout<<"a ɾ��ĳ����Ϣ"<<endl<<"b ȫ��ɾ��"<<endl;
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
                    cout<<"a �˳�������"<<endl<<"b �˳�������"<<endl;
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
                    cout<<"a �˳�������"<<endl<<"b �˳�������"<<endl;
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
                    cout<<"�������������ѡ����!"<<endl;
                    cout<<"�����������..."<<endl;
                    getch();
                }
            }
            if(s=='F'||s=='f'||s=='A'||s=='a'||s=='M'||s=='m'||s=='D'||s=='d'||s=='W'||s=='w'||s=='S'||s=='s'){
                break;
            }
        }
        if(choice==0){
            cout<<"�������������ѡ����!"<<endl;
            cout<<"�����������..."<<endl;
            getch();
        }else{
            break;
        }
    }
    return choice;
}
//���й���
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
//������
int main()
{

    work();		//���й���
    return 0;
}
