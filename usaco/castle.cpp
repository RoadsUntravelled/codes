/*
ID:wangxuf1
LANG:C++
PROG:castle
*/
#include<iostream>
#include<set>
#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<algorithm>
using namespace std;
int castle[65][65];
struct place{
    int first,second,line;
    bool operator<(const struct place&right)const{
        if(this->first<right.first)
            return true;
        else if(this->first==right.first&&this->second<right.second)
            return true;
        else
            return false;
    }
};
struct Rooms{
    set<int>squares;
    int length;
};
set<place>walls;
void vis(Rooms &room,int x,int y){
    room.length+=1;
    room.squares.insert(castle[x][y]);
    int temp=castle[x][y];
    castle[x][y]=0;
    if(!walls.count({temp,castle[x+1][y]})&&castle[x+1][y])vis(room,x+1,y);
    if(!walls.count({temp,castle[x-1][y]})&&castle[x-1][y])vis(room,x-1,y);
    if(!walls.count({temp,castle[x][y+1]})&&castle[x][y+1])vis(room,x,y+1);
    if(!walls.count({temp,castle[x][y-1]})&&castle[x][y-1])vis(room,x,y-1);
    return ;
}
int M,N;
bool cmp(Rooms a,Rooms b){
    return a.length<b.length;
}
int main(){
    freopen("castle.in","rd",stdin);
    freopen("castle.out","wd",stdout);
    while(cin>>M>>N){
        int num=1;
        int ceil;
        walls.clear();
        memset(castle,0,sizeof(int)*65*65);
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++){
                castle[i][j]=num;
                cin>>ceil;
                if(ceil==1) walls.insert({num,num-1,i});
                else if(ceil==2)walls.insert({num,num-M,i});
                else if(ceil==3)walls.insert({num,num-1,i}),walls.insert({num,num-M,i});
                else if(ceil==4){
                    if(num%M)walls.insert({num,num+1,i});
                }
                else if(ceil==5){
                    walls.insert({num,num-1,i});
                    if(num%M)walls.insert({num,num+1,i});
                }
                else if(ceil==6){
                    walls.insert({num,num-M,i});
                    if(num%M)
                    walls.insert({num,num+1,i});
                }
                else if(ceil==7){
                    walls.insert({num,num-1,i});
                    walls.insert({num,num-M,i});
                    if(num%M)
                    walls.insert({num,num+1,i});
                }
                else if(ceil==8){
                    walls.insert({num,num+M,i});
                }
                else if(ceil==9){
                    walls.insert({num,num-1,i});
                    walls.insert({num,num+M,i});
                }
                else if(ceil==10){
                    walls.insert({num,num+M,i});
                    walls.insert({num,num-M,i});
                }
                else if(ceil==11){
                    walls.insert({num,num-1,i});
                    walls.insert({num,num+M,i});
                    walls.insert({num,num-M,i});
                }
                else if(ceil==12){
                    walls.insert({num,num+M,i});
                    if(num%M)
                    walls.insert({num,num+1,i});
                }
                else if(ceil==13){
                    walls.insert({num,num+M,i});
                    if(num%M)
                    walls.insert({num,num+1,i});
                    walls.insert({num,num-1,i});
                }
                else if(ceil==14){
                    walls.insert({num,num-M,i});
                    walls.insert({num,num+M,i});
                    if(num%M)
                    walls.insert({num,num+1,i});
                }
                else if(ceil==15){
                    walls.insert({num,num-M,i});
                    walls.insert({num,num+M,i});
                    if(num%M)
                    walls.insert({num,num+1,i});
                    walls.insert({num,num-1,i});
                }
                num++;
        }

        Rooms room[2555];
        int cnt=1;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++)
            {
                if(castle[i][j]!=0){
                    room[cnt].length=0;
                    vis(room[cnt],i,j);
                    cnt++;

                }       
            } 
        cout<<cnt-1<<endl;
        sort(room+1,room+cnt,cmp);
        cout<<room[cnt-1].length<<endl;
        int max_length=0;
        set<place>::iterator stad;
        for(set<place>::iterator it=walls.begin();it!=walls.end();it++)
            if(it->first>0&&it->first<=M*N&&it->second>0&&it->second<=M*N&&it->first<it->second){
            int temp_length=0;
            for(int i=1;i<cnt;i++){
                if(room[i].squares.count(it->first)||room[i].squares.count(it->second)){
                    temp_length+=room[i].length;
                }   
            }
            if(temp_length>max_length){
                max_length=temp_length;
                stad=it;
            }
                else if(temp_length==max_length){
                    if((it->line>stad->line&&it->first<=stad->first+M*(it->line-stad->line)&&it->first!=stad->second)||(it->first==stad->first))            
                        stad=it;
                }
            }       
        cout<<max_length<<endl;
        cnt=0;
        for(int i=1;i<=N;i++){
            int j;
            for(j=1;j<=M;j++){
                cnt++;
            if(cnt==stad->first){
                if(stad->second-cnt==M)cout<<i+1<<" "<<j<<" N"<<endl;
                else cout<<i<<" "<<j<<" E"<<endl;
                break;
            }
            }
            if(j<=M)
                  break;
        }
    }
    return 0;
}
