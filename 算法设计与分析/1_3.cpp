#include<iostream>
#include<cstdlib>
#define OK 1
#define ERROR 0
using namespace std;
typedef int Status;

typedef struct  LNode{
    int   data;     //数据域
    struct LNode  *next;    //指针域
}LNode, *LinkList;

//新建一个头结点
Status InitList(LinkList &L){
    L = new LNode;
    L->next = NULL;
    return OK;
}

//尾插法新建链表
void CreateList(LinkList &L, int n){
    LinkList r = L;
    for(int i = 1;i <= n; ++i){
        LinkList p=new LNode;
        cin>>r->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

//逆序操作
LinkList fun(LinkList &node_a, LinkList &node_b, LinkList &node_c){
	if(node_b){
		LinkList node_t = node_c;
		node_b->next = node_a;
		fun(node_b,node_t,node_t->next);
	}
	else{
		return node_a->next;
	}
}

//输出操作
void Display(LinkList &L,int n){
    LinkList p = L;
    for(int i=0;i<n;i++){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    LinkList L;
    InitList(L);
    int n;
    cout<<"input sum: " ;
    cin >> n;
    cout<<"imput "<<n<<" numbers："<<endl;
        CreateList(L,n);
    cout<<"Before："<<endl;
        Display(L,n);
    LinkList p=L->next;
    L = fun(L, L->next, p->next);
    cout<<"After："<<endl;
    Display(L,n);
}
