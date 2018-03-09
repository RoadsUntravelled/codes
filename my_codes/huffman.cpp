/*************************************************************************
	> File Name: huffman.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2017年12月20日 星期三 16时26分48秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef struct{
    unsigned int weight;
    unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char* *HuffmanCode;
void Select(HuffmanTree HT,int n,int&s1,int&s2){
    int i;
    int min=0;
    for(i=1;i<=n;++i)
    {
        if(HT[i].parent==0)
        {
            if(min==0){min=HT[i].weight;min++;s1=i;}
            if(HT[i].weight<min){min=HT[i].weight;s1=i;}
        }
    }
    min=0;
    for(i=1;i<=n;++i)
    {
        if((HT[i].parent==0)&&(i!=s1))
        {
            if(min==0){min=HT[i].weight;min++;s2=i;}
            if(HT[i].weight<min){min=HT[i].weight;s2=i;}
        }
    }
    if(s2<s1)  //保证s1的下标值小与s2实现左右子树的大小对称
    {
        s1=s1+s2;
        s2=s1-s2;
        s1=s1-s2;
    } 
}
void HuffmanCoding(HuffmanTree&HT,HuffmanCode&HC,unsigned int*w,int n){
    if(n<=1)return;
    int m=n*2-1;
    HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
    HuffmanTree p;
    int i;
    for(p=HT+1,i=1;i<=n;i++,++p,++w)*p={*w,0,0,0};
    for(;i<=m;i++,p++)*p={0,0,0,0};
    for(i=n+1;i<=m;i++){//建赫夫曼树
        int s1,s2;
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;HT[s2].parent=i;
        HT[i].lchild=s1;HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
    for(int i=1;i<=m;i++){
        cout<<HT[i].weight<<" "<<HT[i].parent<<" "<<HT[i].lchild<<" "<<HT[i].rchild<<endl;
    }
    HC=(HuffmanCode)malloc((n+1)*sizeof(char *));//分配n个字符编码的头指针向量
    int q=m;
    int cdlen=0;
     char*cd;//分配求编码的工作空间
    cd=(char*)malloc(n*sizeof(char));
    for(int i=1;i<=m;i++)HT[i].weight=0;//遍历赫夫曼树时作结点状态标志
    while(q){
        if(HT[q].weight==0){//向左
            HT[q].weight=1;
            if(HT[q].lchild!=0){
                q=HT[q].lchild;
                cd[cdlen++]='0';
            }
            else if(HT[q].rchild==0){//登记叶子结点的字符编码
                HC[q]=(char*)malloc((cdlen+1)*sizeof(char));
                cd[cdlen]='\0';strcpy(HC[q],cd);//复制编码串
                //cout<<HC[q]<<endl;
            }
        }else if(HT[q].weight==1){//向右
            HT[q].weight=2;
            if(HT[q].rchild!=0){q=HT[q].rchild;cd[cdlen++]='1';}
        }else{
            HT[q].weight=0;q=HT[q].parent;--cdlen;
        }
    }
}
int main(){
    unsigned int w[]={5,29,7,8,14,23,3,11};
    HuffmanTree HT;
    HuffmanCode HC;
    HuffmanCoding(HT,HC,w,8); 
    cout<<endl;
    for(int i=1;i<=8;i++)
    cout<<HC[i]<<endl;
    cout<<endl;
    for(int i=1;i<=15;i++)
        cout<<i<<"."<<HT[i].weight<<" "<<HT[i].parent<<" "<<HT[i].lchild<<" "<<HT[i].rchild<<endl;
    return 0;
}
