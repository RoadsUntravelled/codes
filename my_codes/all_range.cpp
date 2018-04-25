
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iterator>
using namespace std;
const int MAX_NUM=100;
int n;
void swap(int list[][2],int para1,int para2){
    list[list[para2][1]][0]=list[para2][0];
    list[list[para2][0]][1]=list[para2][1];
    list[para2][1]=para1;
    list[para2][0]=list[para1][0];
    list[list[para1][0]][1]=para2;
    list[para1][0]=para2;
}
void reset(int list[][2],int para1,int para2,int next[]){
}
void all_range(int list[][2],int star,int end){
}
int main(){
    while(cin>>n){
        int(*list)[2]=new int[n+2][2]();
        for(int i=1;i<=n;i++){
            list[i][1]=i+1;
            list[i][0]=i-1;
        }
        list[0][1]=1;
        list[n][1]=0;
        //all_range(list,1,n+1);
        swap(list,0,1);
        for(int i=0;i<=n;i++)
            cout<<list[i][0];
        cout<<endl;
        for(int i=0;i<=n;i++)
            cout<<list[i][1];
        cout<<endl;
        swap(list,1,2);
        for(int i=0;i<=n;i++)
            cout<<list[i][1];
        cout<<endl;
        delete[]list;
    }
    return 0;
}
/*这道题关键在于移动*/
