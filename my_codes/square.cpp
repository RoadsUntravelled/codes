/*************************************************************************
	> File Name: square.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月18日 星期三 19时31分43秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
int main(){
    int t;
    while(cin>>t){
    for(int i=0;i<t;i++){
        int n;
        char s[1010];
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        s[0]=s[n+1]='X';
        int cnt=0;
        bool vis[1010]={false};
        for(int i=1;i<=n;)
            if(s[i]=='.'&&s[i-1]=='.'&&s[i+1]=='.')
            {
                vis[i]=vis[i-1]=vis[i+1]=true;
                cnt++;
                i+=3;
            }else{
                i++;
            }
        for(int i=1;i<=n;)
        if(!vis[i]&&!vis[i+1]&&s[i]=='.'&&s[i+1]=='.'){
            vis[i]=vis[i+1]=true;
            i+=2;
            cnt++;
        }else{
            i++;
        }
        for(int i=1;i<=n;)
        if(s[i]=='X'&&!vis[i-1]&&!vis[i+1]&&s[i-1]=='.'&&s[i+1]=='.'){
            vis[i-1]=vis[i+1]=true;
            cnt++;
            i+=3;
        }else{
            i++;
        }
        for(int i=1;i<=n;i++)
            if(!vis[i]&&s[i]=='.')
                cnt++;
        cout<<cnt<<endl;
    }
    }
    return 0;
}
