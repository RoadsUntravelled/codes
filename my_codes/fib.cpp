/*************************************************************************
	> File Name: fib.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月30日 星期五 15时24分20秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int fn1=1,fn2=1;
    int fn=1;
    int n;
    cin>>n;
    for(int i=3;i<=n;i++){
        fn=(fn1+fn2)%10007;
        int temp=fn2%10007;
        fn2=fn;
        fn1=temp;
    }
    cout<<fn<<endl;
    return 0;
}
