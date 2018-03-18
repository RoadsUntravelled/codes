
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_NUM=10;
void move(char *list,char value,int star,int end){
    if(star<end){
    for(int i=end;i>star;i--){
        list[i]=list[i-1];
    }
    list[star]=value;
    }
    else{
        for(int i=end;i<star;i++){
            list[i]=list[i+1];
        }
        list[star]=value;
    }
}
void all_range(char*list,int star,int end){
    if(star==end){
        for(int i=1;i<=end;i++)
            cout<<list[i];
        cout<<endl;
    }
    else
    {   
        all_range(list,star+1,end);
        for(int i=star+1;i<=end;i++){
           //all_range(list,star+1,end);
            int temp=list[i];
            move(list,temp,star,i);
            all_range(list,star+1,end);
            move(list,temp,i,star);
           /*for(int i=1;i<=end;i++)
                cout<<list[i]<<" ";
            cout<<endl;*/
            }   
    }
}
int main(){
    int n;
    while(cin>>n){
        char list[MAX_NUM];
        for(int i=1;i<=n;i++)
            list[i]=i+'0';
        all_range(list,1,n);
    }
    return 0;
}
/*这道题关键在于移动*/
