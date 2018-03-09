/*************************************************************************
	> File Name: AK.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2017年12月31日 星期日 17时11分27秒
 ************************************************************************/

#include<iostream>
using namespace std;
struct ptime{
    char problem;
    string result;
    int time;
    int error=0;
};
int main(){
    int n;
    while(cin>>n){
    int cnt=0,sum=0;
    ptime li[10000];
    char p;
    string rs;
    int t;
    for(int i=0;i<n;i++)
    {
        cin>>p>>rs>>t;
        int j=1;
        for(j=1;j<=cnt;j++)
        {
            if(li[j].problem==p)
            {
                if(li[j].result=="AC")
                break;
                else if(rs=="AC")
                li[j].result=rs,li[j].time=t;
                else
                li[j].error++;
                break;
            }
        }
        if(j==cnt+1){
        cnt++;
        li[cnt].problem=p;li[cnt].result=rs;li[cnt].time=t;
            if(rs=="WA")
            li[cnt].error++;
    }
    }
    /*for(int i=1;i<=cnt;i++)
    cout<<li[i].problem<<" "<<li[i].result<<" "<<li[i].time<<" "<<li[i].error<<endl;*/
    for(int i=1;i<=cnt;i++)
    if(li[i].result=="AC"){
    sum+=li[i].time;
    sum+=li[i].error*20;}
    cout<<sum<<endl;}
    return 0;
}
