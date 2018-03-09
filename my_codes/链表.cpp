/*************************************************************************
	> File Name: 链表.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年01月11日 星期四 21时40分52秒
 ************************************************************************/

#include<iostream>
using namespace std;
template<class ElemType>
struct Node{
    ElemType data;
    struct Node*next;
};
template<typename ElemType>
using LinkList=Node<ElemType>*;
template<typename ElemType>
bool GetElem(LinkList<ElemType> L,int i,ElemType*e){
    int j;
    LinkList<ElemType> p;
    p=L->next;
    j=1;
    while(p&&j<i){
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return 0;
    *e=p->data;
    return 1;
}
template<typename ElemType>
bool ListInsert(LinkList<ElemType>*L,int i,ElemType e){
    int j;
    LinkList<ElemType>p,s;
    p=*L;
    j=1;
    while(p&&j<i){
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return 0;
    s=(LinkList<ElemType>)malloc(sizeof(Node<ElemType>) );
    s->data=e;
    s->next=p->next;
    p->next=s;
    return 1;
}
template<typename ElemType>
bool ListDelete(LinkList<ElemType>*L,int i,ElemType*e){
    int j;
    LinkList<ElemType>p,q;
    p=*L;
    j=1;
    while(p->next&&j<i){
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i)
        return 0;
    q=p->next;
    p->next=q->next;
    *e=q->data;
    free(q);
    return 1;
}
template<typename ElemType>
void CreateListTail(LinkList<ElemType>*L,int n){
    LinkList<ElemType>p,r;
    int i;
    srand(time(0));
    *L=(LinkList<ElemType>)malloc(sizeof(Node<ElemType>));
    r=*L;
    for(i=0;i<n;i++){
        p=(Node<ElemType>*)malloc(sizeof(Node<ElemType>));
        p->data=rand()%100+1;
        r->next=p;
        r=p;
    }
    r->next=NULL;
}
template<typename ElemType>
bool ClearList(LinkList<ElemType>*L){
    LinkList<ElemType>p,q;
    p=(*L)->next;
    while(p){
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
    return true;
}
