/*************************************************************************
	> File Name: sccanf.c
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月21日 星期三 13时27分13秒
 ************************************************************************/

#include<stdio.h>
int main ()
{
  char sentence []="Rudolph is 15 12 years old";
  char str [20];
  int i;
  char ext [20];
  sscanf (sentence,"%s %*s %d %*s %s",str,&i,ext);
  printf ("%s -> %d\n",str,i);
  printf("extra:%s\n",ext);
  
  return 0;
}
