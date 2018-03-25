/*************************************************************************
	> File Name: typedef.c
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月24日 星期六 21时28分15秒
 ************************************************************************/

#include<stdio.h>

typedef char *pStr;
int main(){
char string[4]="abc";
const char *p1=string;//指向字符型常量的指针
const pStr p2=string;
printf("%s",++p1);
//p2++;
    return 0;
}
