/*************************************************************************
	> File Name: systime.c
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月06日 星期五 22时22分23秒
 ************************************************************************/

#include<stdio.h>
#include<time.h>
int main(){
    struct tm*sysDate;
    struct tm*sysTime;
    time_t nowTime;
    time(&nowTime);
    sysTime=localtime(&nowTime);
    printf("系统日期：%d-%d-%d\n",1900+sysTime->tm_year,sysTime->tm_mon+1,sysTime->tm_mday);
    printf("系统时间：%d:%d:%d\n",sysTime->tm_hour,sysTime->tm_min,sysTime->tm_sec);
    return 0;

}
