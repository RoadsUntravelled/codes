
/*************************************************************************
	> File Name: AVLTree.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月17日 星期二 17时08分46秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
typedef struct BiTNode{
    int data;
    int bf;//结点的平衡因子
    struct  BiTNode*lchild,*rchild;
}BiTNode,*BiTree;
//对以p为根的二叉排序树作右旋处理
void R_Rotate(BiTree*p){
    BiTree L;
    L=(*p)->lchild;
    (*p)->lchild=L->rchild;
    L->rchild=(*p);
    (*p)=L;
}
//左旋处理
void L_Rotate(BiTree*p){
    BiTree R;
    R=(*p)->rchild;
    (*p)->rchild=R->lchild;
    R->lchild=(*p);
    *p=R;
}
const int LH=+1;
const int EH=0;
const int RH=-1;
//对以指针T所指结点为根的二叉树作左平衡旋转处理
//本算法结束时，指针T指向新的根结点
void LeftBalance(BiTree*T){
    BiTree L,Lr;
    L=(*T)->lchild;//L指向T的左子树根结点
    switch(L->bf){//检查T的左子树的平衡度，并作相应平衡处理
        case LH://新结点插入在T的左孩子的左子树上，要作单右旋处理
            (*T)->bf=L->bf=EH;
            R_Rotate(T);
            break;
        case RH://新结点插入在T的左孩子的右子树上，要作双旋处理
            Lr=L->rchild;
            switch(Lr->bf){
                case LH:(*T)->bf=RH;
                    L->bf=EH;
                    break;
                case EH:(*T)->bf=L->bf=EH;
                    break;
                case RH:(*T)->bf=EH;
                    L->bf=LH;
                    break;
            }
            Lr->bf=EH;
            L_Rotate(&(*T)->lchild);//对T的左子树作左旋转平衡处理
            R_Rotate(T);//对T作右旋平衡处理
    }
}
void RightBalance(BiTree*T){
    BiTree R,Rl;
    R=(*T)->rchild;
    switch(R->bf){//检查T的右子树平衡度，并作相应平衡处理
        case LH://新结点插入在T的右孩子的左子树上，要作单右旋处理
            (*T)->bf=R->bf=EH;
            R_Rotate(T);
            break;
        case RH://新结点插入在T的左孩子的右子树上，要作双旋处理
            Rl=R->rchild;
            switch(Rl->bf){
                case LH:(*T)->bf=RH;
                    R->bf=EH;
                    break;
                case EH:(*T)->bf=R->bf=EH;
                    break;
                case RH:(*T)->bf=EH;
                    R->bf=LH;
                    break;
            }
            Rl->bf=EH;
            L_Rotate(&(*T)->lchild);//对T的左子树作左旋转平衡处理
            R_Rotate(T);//对T作右旋平衡处理
    }
}
bool insert_avl(BiTree*T,int e,bool*taller){
    if(!*T){
        *T=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=e;
        (*T)->lchild=(*T)->rchild=NULL;
        (*T)->bf=EH;
        *taller=true;
        cout<<"sucess!insert:"<<e<<endl;
    }else{
        if(e==(*T)->data){
            *taller=false;
            return false;
        }
        if(e<(*T)->data){
            if(!insert_avl(&(*T)->lchild,e,taller))
                return false;
            if(taller){
                switch((*T)->bf){
                    case LH:
                        cout<<"LeftBalance"<<endl;
                        LeftBalance(T);
                        *taller=false;
                        break;
                    case EH:
                        (*T)->bf=LH;
                        *taller=true;
                        break;
                    case RH:
                        (*T)->bf=EH;
                        *taller=false;
                        break;
                }
            }
        }
        else{
            if(!insert_avl(&(*T)->rchild,e,taller))
            return false;
            if(*taller){
                switch((*T)->bf){
                    case LH:
                        (*T)->bf=EH;
                        *taller=false;
                        break;
                    case EH:
                        (*T)->bf=RH;
                        *taller=true;
                        break;
                    case RH:
                        cout<<"RightBalance"<<endl;
                        RightBalance(T);
                        *taller=false;
                        break;
                }
            }
        }
    }
    return true;
}
int main(){
    int a[10]={3,0,1,4,5,6,7,10,9,8};
    int i;
    BiTree T=NULL;
    bool taller;
    for(i=0;i<10;i++)
        insert_avl(&T,a[i],&taller);
    return 0;
}
