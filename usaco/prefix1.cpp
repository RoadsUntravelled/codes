/*
ID:wangxuf1
PROG:prefix
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include<string> 
#include<cstdio>
using namespace std;
char assemble[210][15];
string str;
int main() {
    //freopen("prefix.in","r",stdin);
    //freopen("prefix.out","w",stdout);
    //ifstream fin ("prefix.in");
    int count=0,Max=0;
    while(cin>>assemble[count]&&assemble[count++][0]!='.');
    getchar();
    str="";
    string s;
    while(getline(cin,s)&&s!="")
      str+=s;
    for(int i=0;i<str.length();i++)
    {
       for(int j=0;j<count;j++)
       {
         if(i+strlen(assemble[j])<=str.length())
         {
           bool judge=true;
           for(int k=0;k<strlen(assemble[j]);k++)
                if(str[i+k]!=assemble[j][k])
                    {
                     judge=false;break;
                     }
         if(judge)
           if(Max<i+strlen(assemble[j]))
         Max=i+strlen(assemble[j]);
         }
       }
       if(i+1>Max){
        //cout<<i<<endl;
        break;
        } 
        cout<<i<<"max:"<<Max<<endl;
    }
    cout<<Max<<endl;
    return 0;
}
