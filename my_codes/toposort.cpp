/*************************************************************************
	> File Name: toposort.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月20日 星期五 21时04分26秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
int n,m;
struct Node{
    int in,out;
    int* adj=new int[n]();
    ~Node(){delete []adj;}
};
int main(){
    while(cin>>n>>m){
        Node*node=new Node[n+1]();
        int num1,num2;
        for(int i=1;i<=m;i++){
            cin>>num1>>num2;
            int out=++node[num1].out;
            node[num1].adj[out]=num2;
            node[num2].in++;
        }
        bool*vis=new bool[n+1]();
        int cnt=n;
        while(cnt){
            int minum=n+1;
            for(int i=n;i>=1;--i)
            if(!vis[i]&&node[i].in==0){
                if(cnt!=1)
                cout<<i<<" ";
                else
                cout<<i<<endl;
                vis[i]=true;
                cnt--;
                for(int j=1;j<=node[i].out;j++){
                    int temp=node[i].adj[j];
                    node[temp].in--;
                }
                break;
            }
                    
        }
        delete []node;
        delete []vis;
    }
    return 0;
}
