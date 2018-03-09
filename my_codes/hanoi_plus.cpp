/*************************************************************************
	> File Name: hanoi_plus.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月07日 星期三 22时51分50秒
 ************************************************************************/

#include<iostream>
using namespace std;
int cnt=0;
int top=1;
void move(int n,char star,char des){
    cout<<n<<" move from "<<star<<" to"<<des<<endl;
    cnt++;
}
void hanoi(int n,char star,char medium_L,char medium_R,char des){
    if(n<=0){
        return;
    }
    else if(n==top||n==1){
     move(n,star,des);
    }
    else{
        hanoi(n-2,star,medium_R,des,medium_L);
        top++;
        cout<<top<<endl;
        move(n-1,star,medium_R);
        move(n,star,des);
        top++;
        hanoi(n-2,medium_L,star,des,medium_R);
        /*top=n-2;
        hanoi(n-2,medium_L,star,medium_R,des);*/
    }
}
int main(){
    int m;
    cin>>m;
    hanoi(m,'A','B','C','D');
    cout<<cnt<<endl;
    return 0;
}
