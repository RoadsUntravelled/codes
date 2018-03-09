/*************************************************************************
	> File Name: sleep.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2017年12月31日 星期日 16时49分37秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int sum=0;
        int a;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            sum+=a;
        }
        if(sum>=25)
        cout<<"YES";
        else
        cout<<"NO"<<endl;
    }
    return 0;
}
