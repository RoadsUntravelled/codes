/*************************************************************************
	> File Name: hanoi.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年01月10日 星期三 22时03分52秒
 ************************************************************************/

#include<iostream>
using namespace std;
void move(int n,char src,char dest){
    cout<<n<<":"<<src<<"-->"<<dest<<endl;
}
void hanoi(int n,char src,char medium,char dest){
    if(n==1)
        move(n,src,dest);//只有一个盘子是直接将初始塔上的盘子移动到目的地
    else{
        hanoi(n-1,src,dest,medium);//先将初始塔前n-1个盘子借助目的塔移动到借用塔上
        move(n,src,dest);//将剩下的一个盘子移动到目的塔上
        hanoi(n-1,medium,src,dest);//最后将借用塔上的n-1个盘子移动到目的塔上
    }
}
int main(){
    int m;
    cout<<"Enter the number of diskes:";
    cin>>m;
    cout<<"the steps to moving "<<m<<" disked:"<<endl;
    hanoi(m,'A','B','C');
    return 0;
}
