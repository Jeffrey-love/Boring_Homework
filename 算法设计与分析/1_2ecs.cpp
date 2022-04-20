#include <iostream>
#define OVERFLOW -1
#define ERROR 0
#define OK 1

using namespace std;
typedef int TElemType;
typedef int Status;

typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status CreateBiTree(BiTree &T){
    TElemType t;
	cout << "input: ";
    cin >> t;
    if(t == 0)
        T = NULL;
    else{
        T = new BiTNode;
        if(!T)
            exit(OVERFLOW);
        T->data = t;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}//CreateBiTree

Status findmax(BiTree &node){
	if (node == 0)
		return false;
    int left = findmax(node->lchild);
    int right = findmax(node->rchild);
    int sum = node->data + left + right;
    int max1 = max(max1, sum);
	return node->data + max(left, right);
}

Status maxPath(BiTree &T){
    if(T->data == 0)
        return 0;
	int final1 = findmax(T);
	cout << "max path:" << final1;
	return OK;
}

int main(){
    BiTree T;
    cout << "input BiTree:" << endl;
    CreateBiTree(T);
	maxPath(T);
	return 0;
}
