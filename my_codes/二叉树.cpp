/*************************************************************************
	> File Name: 二叉树.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2017年12月20日 星期三 11时03分29秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void POT(BiTree T){
    if(T){
    cout<<T->data;//输出结点的值
    POT(T->lchild);//一直遍历左子树，如果结点有值，输出结点的值
    POT(T->rchild);//之后返回遍历右子树，如果结点有值，输出结点的值
    }
    return;
}
void InorderTraverse(BiTree T){
    if(T==NULL)//如果没有左子树，返回
        return;
    InorderTraverse(T->lchild);//一直遍历左子树
    cout<<T->data;//输出结点（左子树的根）的值
    InorderTraverse(T->rchild);//之后向右子树延伸一步
}
void PostOrderTraverse(BiTree T){
    if(T==NULL)//如果子树没有，返回
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    cout<<T->data;//如果左右子树都没有值，输出根结点的值
}
void inordertraverse(BiTree T){
    stack<BiTree>S;S.push(T);
    while(!S.empty()){
        while(S.top())S.push(S.top()->lchild);
        S.pop();//空指针退栈
        if(!S.empty()){
            BiTree p=S.top();
            S.pop();
            //if(!p->data)exit(0);
            cout<<p->data;
            S.push(p->rchild);
        }
    }
}
void CreateBiTree(BiTree&T){
    char ch;
    scanf("%c",&ch);
    if(ch==' '){
        T=NULL;
        cout<<"error"<<endl;
    }
    else{
        if(!(T=(BiTNode*)malloc(sizeof(BiTNode))))exit(0);
        T->data=ch;
        cout<<"请输入左结点:";
        CreateBiTree(T->lchild);
        cout<<"请输入右结点:";
        CreateBiTree(T->rchild);
    }
}
int main(){
    //BiTree tree=(BiTree)malloc(sizeof(BiTNode));
    BiTree createtree;
    /*BiTree root=tree;
    root->data='-';
    root->lchild=(BiTree)malloc(sizeof(BiTNode));root->rchild=(BiTree)malloc(sizeof(BiTNode));
    BiTree lc=root->lchild,rc=root->rchild;
    lc->data='+';
    rc->data='/';
    rc->rchild=(BiTree)malloc(sizeof(BiTNode));
    rc->rchild->data='f';
    rc->lchild=(BiTree)malloc(sizeof(BiTNode));
    rc->lchild->data='e';
    root=lc;
    root->lchild=(BiTree)malloc(sizeof(BiTNode));
    lc=root->lchild;
    lc->data='a';
    root->rchild=(BiTree)malloc(sizeof(BiTNode));
    rc=root->rchild;
    rc->data='*';
    root=rc;
    root->lchild=(BiTree)malloc(sizeof(BiTNode));
    lc=root->lchild;
    lc->data='b';
    root->rchild=(BiTree)malloc(sizeof(BiTNode));
    rc=root->rchild;
    rc->data='-';
    root=rc;
    root->lchild=(BiTree)malloc(sizeof(BiTNode));
    lc=root->lchild;
    lc->data='c';
    root->rchild=(BiTree)malloc(sizeof(BiTNode));
    rc=root->rchild;
    rc->data='d';*/
    CreateBiTree(createtree);
    /*cout<<"前序遍历:";
    POT(createtree);
    cout<<endl;
    cout<<"中序遍历:";
    inordertraverse(createtree);
    cout<<endl;
    cout<<"后序遍历:";
    PostOrderTraverse(createtree);
    cout<<endl;*/
    return 0;
}
