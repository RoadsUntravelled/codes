/*************************************************************************
	> File Name: topo.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年04月14日 星期六 13时24分01秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;
const int MAXVEX=65565;
struct EdgeNode{//边表结点
    int adjvex;//邻接点域，存储该顶点对应的下标
    int weight;//存储权值
    struct EdgeNode*next;//链域，指向下一个邻接点
};
typedef struct VertexNode{//顶点表结点
    int in;//顶点入度数
    int data;//顶点域，存储顶点信息
    EdgeNode*firstedge;//边表头指针
}VertexNode,AdjList[MAXVEX];
typedef struct{
    AdjList adjList;//顶点表
    int numVertexes,numEdges;//图中当前顶点数和边数
}graphAdjList,*GraphAdjList;
bool TopologicalSort(GraphAdjList GL){
    EdgeNode*e;
    int i,k,gettop;
    int top=0;//栈指针栈顶
    int count=0;//统计输出顶点的个数
    int*stack;//建栈存储入度为0的顶点
    stack=(int*)malloc(GL->numVertexes*sizeof(int));
    for(int i=0;i<GL->numVertexes;i++)
        if(GL->adjList[i].in==0){
            cout<<"data:"<<GL->adjList[i].data<<" ";
            stack[++top]=i;//将入度为0的顶点入栈
        }
    cout<<endl;
    while(top!=0){//如果栈不为空
        gettop=stack[top--];//pop the top of stack
        printf("%d->",GL->adjList[gettop].data);//print the vertex which it poped
        count++;//count the number of vertexs which are printed
        for(e=GL->adjList[gettop].firstedge;e;e=e->next){
            //go through edge table of the vertex
            k=e->adjvex;
            if(!(--GL->adjList[k].in)){//minus the number in-degrees of kth of the vertex
                stack[++top]=k;//if the in==0,push the kth of the vertex
                cout<<"this data:"<<GL->adjList[k].data<<endl;
            }   
        }
    }
    if(count<GL->numVertexes)//if count<numVertexes,the circle has existed
        return 0;
    else
        return 1;
}
int main(){
    graphAdjList topo;
    topo.numVertexes=14;
    topo.numEdges=20;
    for(int i=0;i<topo.numVertexes;i++){
        cin>>topo.adjList[i].in>>topo.adjList[i].data;
        EdgeNode*e=(EdgeNode*)malloc(sizeof(EdgeNode));
        cin>>e->adjvex;
        if(e->adjvex!=-1){
            topo.adjList[i].firstedge=e;
            EdgeNode*p=(EdgeNode*)malloc(sizeof(EdgeNode));
            cin>>p->adjvex;
            while(p->adjvex!=-1){
                //cout<<" now:"<<p->adjvex<<endl;
                e->next=p;
                e=p;
                p=(EdgeNode*)malloc(sizeof(EdgeNode));
                cin>>p->adjvex;
                //cout<<" now:"<<p->adjvex<<endl;
            }
            e->next=NULL;
        }
        else{
            topo.adjList[i].firstedge=NULL;
        }
        cout<<"in:"<<topo.adjList[i].in<<" data:"<<topo.adjList[i].data<<",";
        EdgeNode*iter=topo.adjList[i].firstedge;
        while(iter){
            cout<<iter->adjvex<<" ";
            iter=iter->next;
        }
        cout<<endl;
    }
    TopologicalSort(&topo);
    return 0;
}
