/*************************************************************************
	> File Name: ananagrams.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月20日 星期二 22时16分43秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map<string,int>cnt;
vector<string>words;
//将单词s进行"标准化"
string repr(const string&s){
    string ans=s;
    for(int i=0;i<ans.length();i++)
        ans[i]=tolower(ans[i]);//把单词中所有字母小写
    sort(ans.begin(),ans.end());//把单词排序
    return ans;
}
int main(){
    int n=0;
    string s;
    while(cin>>s){
        if(s[0]=='#')break;
        words.push_back(s);
        string r=repr(s);
        if(!cnt.count(r))cnt[r]=0;
        cnt[r]++;

    }
    vector<string>ans;
    for(int i=0;i<words.size();i++)
        if(cnt[repr(words[i])]==1)ans.push_back(words[i]);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}
