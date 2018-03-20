/*************************************************************************
	> File Name: the_blocks_problem.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月20日 星期二 20时04分19秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int maxn=30;
int n;
vector<int>pile[maxn];//每个pile[i]是一个vector
//找木块a所在的pile和height,以引用的形式返回调用者
void find_block(int a,int&p,int&h){
    for(p=0;p<n;p++)
        for(h=0;h<pile[p].size();h++)
            if(pile[p][h]==a)return;
}
//把第p堆高度为h的木块上方的所有木块移回原位
void clear_above(int p,int h){
    for(int i=h+1;i<pile[p].size();i++){
        int b=pile[p][i];
        pile[b].push_back(b);//把木块b放回原位
    }
    pile[p].resize(h+1);//pile只应保留下标为0~h的元素
}
//把第p堆高度为h及上方的木块整体移动到p2堆的顶部
void pile_onto(int p,int h,int p2){
    for(int i=h;i<pile[p].size();i++)
        pile[p2].push_back(pile[p][i]);
    pile[p].resize(h);
}
void print(){
    for(int i=0;i<n;i++){
        printf("%d:",i);
        for(int j=0;j<pile[i].size();j++)printf("%d",pile[i][j]);
        printf("\n");
    }
}
int main(){
    int a,b;
    cin>>n;
    string s1,s2;
    for(int i=0;i<n;i++)pile[i].push_back(i);
    while(cin>>s1>>a>>s2>>b){
        int pa,pb,ha,hb;
    }
    return 0;
}
