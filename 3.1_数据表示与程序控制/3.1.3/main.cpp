#include <iostream>
using namespace std;
#define pi 3.14159
int main() {
    double radius,high;
    double volume;
    cout<<"please input two numbers:"<<endl;
    cin>>radius>>high;
    volume=pi*radius*radius*high;
    cout<<"radius:"<<radius<<"   high:"<<high<<endl;
    cout<<"the volume is:"<<volume<<endl;

    return 0;
}