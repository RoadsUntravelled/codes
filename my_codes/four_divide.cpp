/*************************************************************************
	> File Name: four_divide.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月12日 星期一 18时53分23秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
int num[700010]={0};
/*bool cal(int N){
    int tot=0;
    for(int i=2;i<sqrt(N);i++){
        if(N%i==0&&num[i]==1)
            return false;
        if(N%i==0)
            tot++;
        if(tot>=2)
            return false;
    }
    if(tot==1)
        return true;
}*/
int main(){
    int j;
    num[2]=num[3]=0;
    for(int i=2;i<=sqrt(700000);i++){
        for(j=i+1;j<700000/i;j++)
            num[i*j]+=2;
    }
    /*for(int i=2;i<=700;i++)
    if(num[i]==2){
        cout<<i<<" ";
    }*/
    int a,b;
    while(cin>>a>>b){
        int cnt=0;
        for(int i=a;i<=b;i++)
        if(sqrt(i)!=int(sqrt(i))&&num[i]==2){
            
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
