/*************************************************************************
	> File Name: PTNode.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2017年12月20日 星期三 15时49分05秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int MTS=100;

typedef struct PTNode{
    char data;
    int parent;
}PTNode;
typedef struct{
    PTNode nodes[MTS];
    int r,n;
}PTree;
int main(){
    PTree tree;
    tree.r=-1;tree.n=9;
    int parents[1030];
    int cur=0;
    parents[0]=-1;
    for(int i=0;i<9;i++){
        cin>>tree.nodes[i].data>>tree.nodes[i].parent;
        if(tree.nodes[i].parent!=parents[cur]){
            cur++;
            parents[cur]=tree.nodes[i].parent;
        }}

    int r=0;
    for(int i=0;i<9;i++){
        if(tree.nodes[i].parent!=parents[r]){
            r++;
            cout<<endl;
        }
        cout<<tree.nodes[i].data<<" ";
    }
        
    return 0;
}
