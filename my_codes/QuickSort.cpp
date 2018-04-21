/*************************************************************************
	> File Name: QuickSort.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月11日 星期日 16时47分48秒
 ************************************************************************/

#include<iostream>
#include<iterator>
#include"Self_Def_Func.cpp"
using namespace std;
const int length=10;
void Qsort(int *,int,int);
int Partition(int *,int,int);
void QuickSort(int *list,int length){
    Qsort(list,1,length);
}
void Qsort(int *list,int low,int high){
    int pivot;
    while(low<high){
        pivot=Partition(list,low,high);
        Qsort(list,low,pivot-1);
        //Qsort(list,pivot+1,high);
        low=pivot+1;
    }
}
int Partition(int *list,int low,int high){
    int lo=low,hi=high;
    cout<<"before:",copy(list+low,list+high+1,ostream_iterator<int>(cout," "));cout<<endl;
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
    cout<<"after :",copy(list+lo,list+hi+1,ostream_iterator<int>(cout," ")),cout<<endl;
    return low;
}
int main(){
    int list[]={0,2,5,1,9,6,3,7,8,4};
    QuickSort(list,9);
    copy(list+1,list+10,ostream_iterator<int>(cout," "));
    cout<<endl;
}
