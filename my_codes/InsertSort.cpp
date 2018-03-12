/*************************************************************************
	> File Name: InsertSort.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月11日 星期日 16时02分27秒
 ************************************************************************/

#include<iostream>
#include"Self_Def_Func.cpp"
using namespace std;
int main(){
    int j;
    int list[]={5,4,2,6,8};
    for(int i=2;i<5;i++){
        if(list[i]>list[i-1]){
            int temp=list[i];
            for(j=i-1;list[j]<temp;j--)
                list[j+1]=list[j];
            list[j+1]=temp;
            out_put_list(list,5);
        }
    }
    return 0;
}

