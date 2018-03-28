/*************************************************************************
	> File Name: hanoi.java
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年03月25日 星期日 19时05分31秒
 ************************************************************************/
import java.util.Scanner;
public class hanoi{
    static int count=0;//统计移动次数(可不需要,因为最少次数已经与n的值对应的记录在数组B中,即B[n])
    public static void main(String[]args){
        int n;//盘子数
        int []A=new int[65];//数组A:用来记录未加第四个柱子时候的移动次数情况
        int []B=new int[65];//数组B:用来记录加了第四个柱子的情况
        A[1]=1;//即三个柱子时,当i=1的时候,表示移动一个盘子,只需要移动一次
        for(int i=2;i<65;i++){//从i=2开始
            A[i]=2*A[i-1]+1;//f(n)=2f(n-1)+1
        }
        int count4;//记录四根柱子时,移动的总次数
        int[]C=new int[65];//数组C:用来记录当前i下找到的j值
        for(int i=1;i<=64;i++){
            B[i]=100000000;//A[i];//假设没加第四个柱子的结果次数为min的初值
            for(int j=1;j<=i;j++){
                count4=2*B[i-j]+A[j];//j个移动到第四个柱子,然后把剩下的i-j个在第四个柱子不能用的情况下,移到第三个柱子
                if(B[i]>count4){
                    B[i]=count4;//将min赋给B[i],即4跟柱子时,i个盘子从a->d的次数
                    C[i]=j;//找到了当前i下的j值
                }
            }
        }
        Scanner scanner=new Scanner(System.in);
        while(true){
            System.out.print("请输入一个n值(应为1-64之间的整数,输入0结束程序)");
            n=scanner.nextInt();
            if(n==0){
                System.out.println("ByeBye");
                break;
            }
            if(n>64||n<1){
                System.out.println("输入的n有误,请重新输入");
                continue;
            }
        char a='a',b='b',c='c',d='d';
        Hanoi(n,a,b,c,d,C);//把n个盘子从a柱移动到b柱
        System.out.println("共移动了:"+B[n]+"次");
        System.out.println("共移动了:"+count+"次");//与B[n]的值是一样的
        count=0;
        }
    }

public static void Hanoi(int n,char a,char b,char c,char d,int C[]){
    if(n<=0)return;
    if(n==1){
        move(n,a,d);
        return;
    }
    if(n>0){
        int j=C[n];//j个盘子使用四个柱子的移动方式
        Hanoi(n-j,a,c,d,b,C);//把j个盘子移动到d柱子上
        hanoi_basic_3(j,a,c,d);//把n-j个盘子移动到b柱子上(使用三个柱子的移动方式)
        Hanoi(n-j,b,a,c,d,C);//把j个盘子移动到b柱子上
    }
}
public static void hanoi_basic_3(int n,char a,char b,char c){
    if(n<=0)return ;
    if(n==1){
        move(n,a,c);
        return;
    }
    if(n>0){
        hanoi_basic_3(n-1,a,c,b);//把n-1个盘子移动到c柱子上
        move(n,a,c);//把a移动到c
        hanoi_basic_3(n-1,b,a,c);//把第n个盘子移动到c柱子上
    }
}
public static void move(int n,char a,char c){
    System.out.println(a+"->"+c);
    count++;
}
}
