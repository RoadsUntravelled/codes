/*************************************************************************
	> File Name: 线索二叉树.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2017年12月21日 星期四 18时52分52秒
 ************************************************************************/

#include<iostream>
using namespace std;
typedef enum{link,thread} tag;
typedef struct BiThrNode{
    char data;
    struct BiThrNode*lchild,*rchild;
    tag Ltag;
    tag Rtag;
}BiThrNode,*BiThrTree;
BiThrTree pre;
void InThreading(BiThrTree p){
    if(p){
        InThreading(p->lchild);//递归左子树线索化;
        if(!p->lchild){
            p->Ltag=thread;//前驱线索
            p->lchild=pre;//左孩子指向指针前驱
        }
        if(!p->rchild)//前驱没有右孩子
        {
            pre->Rtag=thread;//后继线索
            pre->rchild=p;
        }
        pre=p;//保持pre指向p的前驱
        InThreading(p->rchild);//递归右子树线索化
    }
}
/*T指向头结点，头结点左链lchild 指向根结点，头结点右链rchild指向中序遍历的
 * 最后一个结点。中序遍历二叉线索链表表示的二叉树T*/
bool InorderTraverse_Thr(BiThrTree T){
    BiThrTree p;
    p=T->lchild;//p指向根结点
    while(p!=T){//空树或遍历结束时，p==T
        while(p->Ltag==link)
            p=p->lchild;
       printf("%c",p->data);//显示结点数据，可以更改为其他对结点操
        while(p->Rtag==thread&&p->rchild!=T){
            p=p->rchild;
            printf("%c",p->data);
        }
        p=p->rchild;//p进至其右子树根
    }
    return 1;
}
