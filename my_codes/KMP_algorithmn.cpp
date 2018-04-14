/*************************************************************************
	> File Name: KMP_algorithmn.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月12日 星期四 21时48分39秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<cstring>
using namespace std;
//求模式串T的next函数修正值并存入数组nextval
void get_nextval(const char* T,int *nextval){
    int i=1,j=0;
    nextval[1]=0;
    while(i<strlen(T+1)){
        if(j==0||T[i]==T[j]){//T[i]表示后缀的单个字符,T[j]表示前缀的单个字符;
            i++;//j==0的意思是后缀从i=2开始匹配，果当前后缀字符和前缀字符匹配成功,继续匹配接下来的字符
            j++;
            /*如果当前后缀字符和前缀字符匹配成功,则如果接下来要匹配的字符失配，
             * 则回溯到j,所以nextval[i]=j,但是如果回溯到了j的字符和当前字符相等,
             *则j的字符继续失配,所以要直接回溯到j的nextval[j],即nextval[i]=nextval[j]
             *
             */
            if(T[j]!=T[i])
                nextval[i]=j;
            else
                nextval[i]=nextval[j];

        }
        else{
            j=nextval[j];//若字符匹配失败，前缀字符根据已经算出的nextval数组回溯到nextval[j]                    
        }
    }

}
//返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数返回值为0
int Index_KMP(const char*S,const char*T,const int&pos){
    int i=pos,j=1,next[255];
    get_nextval(T,next);//对串T作分析,得到next数组
    while(i<=strlen(S+1)&&j<=strlen(T+1)){
        if(j==0||S[i]==T[j])//两字符相等时继续匹配,j==0的意思是如果第一个字符也不匹配则主串和子串都往后移动一个位置
        {
            ++i;
            ++j;
        }else{//如果失配
            j=next[j];//j退回合适的位置,i值不变,即前缀重新匹配后缀
        }
    }
    if(j>strlen(T+1))//如果匹配成功,返回当前匹配对应前缀最后一个位置的后缀的位置,即i,减掉T的长度
        return i-strlen(T+1);
    else
        return 0;
}
