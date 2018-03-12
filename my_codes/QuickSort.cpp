/*************************************************************************
	> File Name: QuickSort.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月11日 星期日 16时47分48秒
 ************************************************************************/

#include<iostream>
#include"Self_Def_Func.cpp"
using namespace std;
const int length=10;
void Qsort(int *,int,int);
int Partition(int *,int,int);
void QuickSort(int *list){
    Qsort(list,1,length);
}
void Qsort(int *list,int low,int high){
    int pivot;
    if(low<high){
        pivot=Partition(list,low,high);
        Qsort(list,low,pivot-1);
        Qsort(list,pivot+1,high);
    }
}
int Partition(int *list,int low,int high){
    int pivotkey;
    pivotkey=list[low];
    while(low<high){
        while(low<high&&list[high]>=pivotkey)
            high--;
        list[low]=list[high];
        while(low<high&&list[low]<=pivotkey)
            low++;
        list[high]=list[low];
    }
    list[low]=pivotkey;
    return low;
}
