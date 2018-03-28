/*
 * ID:wangxuf1
 * LANG:c++
 * PROG:sort3
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXNUM=1005;
int cnt;
void swap(int list[],int i,int j){
    int temp=list[i];
    list[i]=list[j];
    list[j]=temp;
    cnt++;
}
int main(){
    freopen("sort3.in","rd",stdin);
    freopen("sort3.out","wd",stdout);
    int n;
    while(cin>>n){
        int list[1005];
        list[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&list[i]); 
            while(list[i]<list[i-1]){
                for(int j=1;j<i;j++){
                    if(list[j]=list[i]+1){
                        swap(list,i,j);
                        break;
                    }
                }
            }
        }
        cout<<cnt<<endl;
        cnt=0;
    }
    return 0;
}
