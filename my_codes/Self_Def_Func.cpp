/*************************************************************************
	> File Name: Self_Def_func.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月11日 星期日 15时37分43秒
 ************************************************************************/
#include<iostream>
using namespace std;
template<class type>
void swap(type*list,int i,int j){
    type temp=list[i];
    list[i]=list[j];
    list[j]=temp;
}
template<class type>
void out_put_list(type*list,int length){
    for(int i=0;i<length;i++)
        cout<<list[i]<<" ";
    cout<<endl;
}
