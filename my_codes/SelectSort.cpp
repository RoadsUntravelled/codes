/*************************************************************************
	> File Name: SelectSort.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月11日 星期日 15时34分45秒
 ************************************************************************/

#include<iostream>
#include"Self_Def_Func.cpp"
using namespace std;
int main(){
    int list[]={5,4,3,2,4,5,6};
    int cnt=0;
    for(int i=0;i<6;i++)
    {
        int min=i;
        for(int j=i+1;j<7;j++)
            if(list[min]<list[j])
            {
            min=j;
            }
        if(i!=min){
            swap(list,min,i);
            out_put_list(list,7);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

