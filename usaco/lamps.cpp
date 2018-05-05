/*
ID:wangxuf1
PROG:lamps
LANG:C++14
*/
#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<set>
#include<string>
#include<cstdio>
using namespace std;
int n;
int c;
void press_button1(string&s){
    for(int i=0;i<n;i++)
        if(s[i]=='1')
            s[i]='0';
        else
            s[i]='1';
}
void press_button2(string&s){
    for(int i=1;i<n;i+=2)
        if(s[i]=='1')
            s[i]='0';
        else
            s[i]='1';
}
void press_button3(string&s){
    for(int i=0;i<n;i+=2)
        if(s[i]=='1')
            s[i]='0';
        else
            s[i]='1';
}
void press_button4(string&s){
    for(int i=0;i<n;i+=3)
        if(s[i]=='1')
            s[i]='0';
        else
            s[i]='1';
}
void press(int i,string&s){
    switch(i){
        case 1:
            press_button1(s);
            break;
        case 2:
            press_button2(s);
            break;
        case 3:
            press_button3(s);
            break;
        case 4:
            press_button4(s);
            break;
    }
        
}
set<string>res;
int on_values[100]={0};
int off_values[100]={0};
void flip(int tot,int flip_num){
    if(flip_num==c){
        string s("");
        s.resize(n);
        for(int i=0;i<n;i++)
            s[i]='1';
        while(tot){
            press(tot%10,s);
            tot/=10;
        }
        //cout<<"before:"<<s<<endl;
        bool flag1=true,flag2=true;
        for(int i=0;on_values[i]!=0;i++)
        if(s[on_values[i]-1]!='1'){
            flag1=false;
            break;
        }
        for(int i=0;off_values[i]!=0;i++)
        if(s[off_values[i]-1]!='0'){
            flag2=false;
            break;
        }
        if(flag1&&flag2)
            res.insert(s);
        return;
    }
    for(int i=1;i<=4;i++)
        flip(tot*10+i,flip_num+1);
}
int main(){
    freopen("lamps.out","w",stdout);
    freopen("lamps.in","r",stdin);
    cin>>n;
    cin>>c;
    int on_value,off_value;
    int i=0;
    while(cin>>on_value&&on_value!=-1)on_values[i++]=on_value;
    i=0;
    while(cin>>off_value&&off_value!=-1)off_values[i++]=off_value;
    if(c>=4)
        c=4;
    flip(0,0);
    int cnt=res.size();
    if(cnt!=0){
    for(set<string>::iterator it=res.begin();it!=res.end();++it)
        cout<<*it<<endl;
    }else{
        //cout<<res.size()<<endl;
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
