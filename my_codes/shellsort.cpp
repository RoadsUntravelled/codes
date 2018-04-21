/*************************************************************************
	> File Name: shellsort.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月20日 星期五 16时53分38秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
void shellsort(int*list,int n){
    int i,j;
    int increment=n;
    do{
        increment=increment/3+1;
        for(i=increment+1;i<=n;i++){
            if(list[i]<list[i-increment]){
                list[0]=list[i];
                for(j=i-increment;j>0&&list[0]<list[j];j-=increment)
                    list[j+increment]=list[j];
                list[j+increment]=list[0];
            }
        }
    }while(increment>1);
}
int main(){
    int list[10]={0,3,5,6,8,9,10,11,5,3};
    shellsort(list,9);
    copy(list+1,list+10,ostream_iterator<int>(cout," "));
    cout<<endl;
    return 0;
}
