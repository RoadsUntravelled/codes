/*************************************************************************
	> File Name: mergesort.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月20日 星期五 18时24分04秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstring>
using namespace std;
void msort(int*,int*,int,int);
void merge(int*,int*,int,int,int);
void merge_sort(int*list,int n){
    msort(list,list,1,n);
}
void msort(int sr[],int tr1[],int s,int t){
    int m;
    int tr2[1000];
    if(s==t)
        tr1[s]=sr[s];
    else{
        m=(s+t)/2;//将sr[s..t]平分为sr[s..m],sr[m+1..t];
        msort(sr,tr2,s,m);//归并sr[s..m]为tr2[s..m]
        msort(sr,tr2,m+1,t);//归并sr[m+1..t]为tr2[m+1..t]
        merge(tr2,tr1,s,m,t);//将tr2[s..m]和tr2[m+1..t]归并到tr1[s..t]
    }
}
//将有序的sr[i..m]和sr[m+1..n]归并为有序的tr[i..n]
void merge(int sr[],int tr[],int i,int m,int n){
    int j,k,l;
    for(j=m+1,k=i;i<=m&&j<=n;k++){
        if(sr[i]<sr[j])
            tr[k]=sr[i++];
        else
            tr[k]=sr[j++];
    }
    if(i<=m)
        memcpy(tr+k,sr+i,sizeof(int)*(m+1-i));
    if(j<=n)
        memcpy(tr+k,sr+j,sizeof(int)*(n+1-j));
}
int main(){
    int list[]={0,4,5,2,9,1,6,7,3,8};
    merge_sort(list,5);
    copy(list+1,list+10,ostream_iterator<int>(cout," "));
    cout<<endl;
}
