/*************************************************************************
	> File Name: 线性表.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年01月11日 星期四 20时55分19秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int MAXSIZE=200;
template<typename ElemType>
struct SqList{
    ElemType data[MAXSIZE];
    int length;
};
template<typename ElemType>
bool GetElem(SqList<ElemType>&L,int i,ElemType*e){
    if(L.length==0||i<1||i>L.length)
        return 0;
    else
        *e=L.data[i-1];
    return 1;
}
template<typename ElemType>
bool ListInsert(SqList<ElemType>&L,int i,ElemType e){
    int k;
    if(L.length==MAXSIZE)
        return 0;
    if(i<1||i>L.length+1)
        return 0;
    if(i<=L.length)
    {
        for(k=L.length;k>=i-1;k--)
            L.data[k+1]=L.data[k];
    }
    L.data[i-1]=e;
    L.length++;
    return 1;
}
template<typename ElemType>
bool ListDelete(SqList<ElemType>&L,int i,ElemType*e){
    int k;
    if(L.length=0)
        return 0;
    if(i<1||i>L.length)
        return 0;
    *e=L.data[i-1];
    if(i<L.length){
        for(k=i;k<L.length;k++)
            L.data[k-1]=L.data[k];
    }
    L.length--;
    return 1;
}
