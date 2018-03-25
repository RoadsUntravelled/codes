/*************************************************************************
	> File Name: parameter.c
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月24日 星期六 21时44分34秒
 ************************************************************************/

#include<stdio.h>
int main(int num,char *argv[]){
    printf("%d\n",num);
    for(int i=0;i<num;i++)
    printf("%c\n",argv[i][i]);
    return 0;
}
