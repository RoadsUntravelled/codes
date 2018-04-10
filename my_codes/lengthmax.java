/*************************************************************************
	> File Name: lengthmax.java
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月10日 星期二 10时11分20秒
 ************************************************************************/
import java.util.Scanner;
public class lengthmax{
    public static String child(String obj,int n){
        int []len=new int[n];
        int []next=new int[n];
        int node=0,minum=0;
        java.util.Arrays.fill(len,1);
        for(int i=0;i<n;i++)
            next[i]=i;
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
                if(obj.charAt(i)>obj.charAt(j)&&(len[j]+1)>len[i]){
                    len[i]=len[j]+1;
                    next[i]=j;
                } 
        for(int i=0;i<n;i++)
            if(len[i]>minum){
                minum=len[i];
                node=i;
            }
        String res="";
        int i=node;
        for(;i!=next[i];i=next[i]){
            res+=obj.charAt(i);
        }
        res+=obj.charAt(i);
        res=new StringBuffer(res).reverse().toString();
        return res;
    }
    public static void main(String[]args){
        String test;
        Scanner scan=new Scanner(System.in);
        test=scan.next();
        String maxchild=child(test,test.length());
        System.out.println(maxchild);
    }
}

