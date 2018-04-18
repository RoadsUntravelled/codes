/*************************************************************************
	> File Name: brightcode.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月18日 星期三 14时40分23秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<bitset>
using namespace std;
int main(){
    int n,m;
    string str1,str2;
    while(cin>>n>>m){
        bitset<8>b(n);
        str1=b.to_string();
        int len1=str1.length();
        for(int i=0;i<len1;i++){
            if(str1[i]=='0')printf(" ");
            else printf("*");
        }
        bitset<8>c(m);
        str2=c.to_string();
        int len2=str2.length();
        for(int i=0;i<len2;i++)
            if(str2[i]=='0')printf(" ");
            else printf("*");
        printf("\n");
    }
}
