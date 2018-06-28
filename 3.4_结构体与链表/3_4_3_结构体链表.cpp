/*
 * 3.4.3  结构体链表
 * 刘金明 320160939811
 */
#include <iostream>
using namespace std;
typedef struct node
{
    int elem;
    node *next;
}nod;//定义链表类型

void print(nod *head)
{
    nod *pNode = head; //让一个指针pNode 指向链表头
    cout<<"\nLink elements:";
    while (pNode != NULL)
    {
        cout<<pNode->elem<<" ";// 输出节点存储的数据，也可以是访问pNode 所指节点
        pNode=pNode->next; //让pNode 指向下一个节点。
    }

}
int main() {
    cout<<"Please input integers to build the link(0 TO END):"<<endl;
    int k;
    nod *head=NULL,*tail=NULL;
    cin>>k;
    while(k!=0)
    {
        nod *pNode = new nod;
        if (pNode == NULL) //判断分配是否成功
        {
            cout << "Memory insufficient!";
            break;
        }

        pNode->elem = k; //节点赋存放值
        pNode->next = NULL; //节点赋值为NULL
        if (head == NULL) //如果是第一个节点，链表为空
        {
            head = tail = pNode; //第一个节点既是头也是尾。
        }
        else
        {
            tail->next = pNode; //尾节点的指针指向新节点，即将新节点加到链表中
            tail = pNode; //新节点加入到链表尾后，让尾指针指向该节点。
        }
        cin>>k;
    }
    print(head);
}