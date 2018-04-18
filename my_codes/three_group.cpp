/*************************************************************************
	> File Name: three_group.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月15日 星期日 08时22分07秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
int main(){
    int N;
    while(cin>>N){
    int *a=new int[N+1],*b=new int[N+1],*c=new int[N+1];
    for(int i=1;i<=N;i++)
        cin>>a[i];
    for(int i=1;i<=N;i++)
        cin>>b[i];
    for(int i=1;i<=N;i++)
        cin>>c[i];
    sort(a+1,a+N+1);
    sort(b+1,b+N+1);
    sort(c+1,c+N+1);
    a[0]=b[0]=c[0]=0;
    long long tot=0;
    for(int i=1;i<=N;i++){
        int x=(lower_bound(a+1,a+N+1,b[i])-a)-1;
        int y=N-((upper_bound(c+1,c+N+1,b[i])-c)-1);
        tot+=x*y;
    }
    printf("%lld\n",tot);
    }
    return 0;
}
