/*************************************************************************
	> File Name: team_queue.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月21日 星期三 11时19分53秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<map>
using namespace std;
/*
 * enqueue x:编号为x的人进入长队
 * dequeue:长队的队首出队
 * stop:停止模拟
 */
 const int maxn=1000+10;
 int main(){
     int t,kase=0;
     while(cin>>t&&t){
         cout<<"Scenario #"<<++kase<<endl;
         map<int,int>team;
         for(int i=0;i<t;i++){
             int n,x;
             cin>>n;
             while(n--){
                 cin>>x;
                 team[x]=i;
             }
         }
         queue<int>q,q2[maxn];//q是团体的队列,而q2[i]是团队i成员的队列
         for(;;){
             int x;
             char cmd[10];
             cin>>cmd;
             if(cmd[0]=='S')break;
             else if(cmd[0]=='D'){
                 int t=q.front();
                 cout<<q2[t].front();q2[t].pop();
                 if(q2[t].empty())q.pop();//团体t全体出队列
             }
             else if(cmd[0]=='E'){
                 cin>>x;
                 int t=team[x];
                 if(q2[t].empty())q.push(t);//团体t进入队列
                 q2[t].push(x);
             }
             for(queue<int>::iterator it=q.begin();it!=q.end();it++){
                 for(queue<int>::iterator temp=q2[*it].begin();temp!=q2[*it].end();temp++)
                    coutt<<*temp<<" ";
             }
             cout<<endl;
         }
         cout<<endl;
     }
     return 0;
 }
