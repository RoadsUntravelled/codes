/*************************************************************************
	> File Name: 数组.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年01月13日 星期六 14时49分34秒
 ************************************************************************/

#include<iostream>
#include<cstdarg>
using namespace std;
const int MAX_ARRAY_DIM=8;//假设数组维数的最大值为8
struct Array{
    int *base;//数组元素基址,由initarray分配
    int dim;
    int*bounds;//数组维界基址,由initarray分配
    int*constants;//数组映像函数常量基址,由initarray分配
};
bool InitArray(Array&A,int dim,...){
    if(dim<1||dim>MAX_ARRAY_DIM)return 0;
    A.dim=dim;
    A.bounds=(int*)malloc(dim*sizeof(int));
    if(!A.bounds)exit(0);
    int elemtotal=1;
    va_list ap;
    va_start(ap,dim);
    for(int i=0;i<dim;i++){
        A.bounds[i]=va_arg(ap,int);
        if(A.bounds[i]<0)return 0;
        elemtotal*=A.bounds[i];
    }
}
