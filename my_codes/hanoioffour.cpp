/*************************************************************************
	> File Name: hanoioffour.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月25日 星期日 22时17分55秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define Max 30	
#define INT_MAX 100000000
int K[Max+1] = {0};	
int step = 0;	

void Hanoi_Four( int n, char a, char b, char c, char d );	
void Hanoi_Three( int n, char a, char b, char c );	
void Move( char x, char y );	

void Move(int n, char x, char y )
{
    printf("%d:%c --> %c\n",n, x, y);	//打印路径，x-->y
}

void Hanoi_Three( int n, char a, char b, char c )
{
	if( n <= 0 )
		return ;	
	
	step++;		//步骤+1
	
	if( n == 1 )
	{
		Move(n, a, c );	//将a柱上的一个盘子直接移动到c柱
		return ;	
	}
	else
	{
		Hanoi_Three( n-1, a, c, b);		//将a上n-1个盘子以c为缓存，全部转移到 b 柱上
		Move(n, a, c );					//将A上留下的第n个盘子，直接转移到 C  柱上
		Hanoi_Three( n-1, b, a, c);		//将b上的n-1个盘子，以a为缓存，全部转移到 c 柱上
	}
}

void Hanoi_Four( int n, char a, char b, char c, char d )
{
	if( n <= 0 )
		return ;	
	
	if( n == 1 )
	{
		step++;	
		Move(n, a, d );	
		return ;	
	}
	else
	{
		int kn = K[n];	
		//printf("kn = %d\n", K[n]);	
		Hanoi_Four( n-kn, a, c, d, b );		//用4柱汉诺塔算法把A柱上部分的n- kn个碟子通过C柱和D柱移到B柱上
		Hanoi_Three( kn, a, c, d );			//用3柱汉诺塔经典算法把A柱上剩余的kn个碟子通过C柱移到D柱上。
		Hanoi_Four( n-kn, b, a, c, d );		//用4柱汉诺塔算法把B柱上的n-r个碟子通过A柱和C柱移到D柱上
	}
}

void Init_K(void )
{
	int i, k;	
	int temp;	
    int m[Max+1] = {0};		
	
	for( i = 1; i <= Max; i++ )
	{
		m[i] = INT_MAX;		
		for( k = 1; k <= i; k++ )
		{
			temp = 2*m[i-k] + pow(2,k) - 1;	
			if( temp < m[i] )
			{
				m[i] = temp;	
				K[i] = k;	
				printf("K[%d] = %d, m[i] = %d\n", i, k, temp );	
			}
		}
	}
}

int main()
{
	int n;	
	Init_K();	

	printf("Please enter the number of the Plates: \n");
	while( scanf("%d", &n) != EOF )
	{
		step = 0;	
		Hanoi_Four( n, 'A', 'B', 'C', 'D' );	
		//Hanoi_Three( n, 'A', 'B', 'C' );	
		printf("**************************\nTotal Step: %d\n", step );	

		printf("Please enter the number of the Plates: \n");
	}
	
	return 0;	
}
