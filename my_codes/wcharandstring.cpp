/*************************************************************************
	> File Name: wcharandstring.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月10日 星期二 21时02分28秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<locale>
#include<string>
using namespace std;
int main(){
    locale loc(".936");
    wcout.imbue(loc);
    wchar_t c=L'人';
    wstring s=L"这是一个中文字符串";
    //cout<<s.length()<<endl;
    wcout<<s<<endl;
    //cout<<wstring::npos<<endl;
    cout<<s.find_first_of(L'中');
    if(s.find_first_of(L'中')==wstring::npos)
        cout<<"Not found"<<endl;
    return 0;
}
