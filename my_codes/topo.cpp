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
int *etv,*ltv;//the earliest time of vertex;the lastest time of vertex
int *stack2;//stack2 saves the order of topo
int top2;//save the top place of the stack2
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
            stack[++top]=i;//将入度为0的顶点入栈
        }
    top2=0;
    etv=(int*)malloc(GL->numVertexes*sizeof(int));//the earliest time of the vertex
    for(int i=0;i<GL->numVertexes;i++)
        etv[i]=0;//init 0;
    stack2=(int*)malloc(GL->numVertexes*sizeof(int));//init
    while(top!=0){//如果栈不为空
        gettop=stack[top--];//pop the top of stack
        count++;//count the number of vertexs which are printed
        stack2[++top2]=gettop;//push the vertex which is poped by stack into stack2
        for(e=GL->adjList[gettop].firstedge;e;e=e->next){
            //go through edge table of the vertex
            k=e->adjvex;
            if(!(--GL->adjList[k].in)){//minus the number in-degrees of kth of the vertex
                stack[++top]=k;//if the in==0,push the kth of the vertex
            }
            if((etv[gettop]+e->weight)>etv[k])//search the earliest time of the vertex
                etv[k]=etv[gettop]+e->weight;
        }
    }
    if(count<GL->numVertexes)//if count<numVertexes,the circle has existed
        return 0;
    else
        return 1;
}
void CriticalPath(GraphAdjList GL){
    EdgeNode*e;
    int i,gettop,k,j;
    int ete,lte;//the earliest and lastest time of activities
    TopologicalSort(GL);
    ltv=(int*)malloc(GL->numVertexes*sizeof(int));//the lastest time of the event
    for(int i=0;i<GL->numVertexes;i++)
        ltv[i]=etv[GL->numVertexes-1];//init ltv
    while(top2!=0){
        gettop=stack2[top2--];
        for(e=GL->adjList[gettop].firstedge;e;e=e->next){
            k=e->adjvex;
            if(ltv[k]-e->weight<ltv[gettop])
                ltv[gettop]=ltv[k]-e->weight;
        }
    }
    for(int j=0;j<GL->numVertexes;j++){
        for(e=GL->adjList[j].firstedge;e;e=e->next){
            k=e->adjvex;
            ete=etv[j];
            lte=ltv[k]-e->weight;
            if(ete==lte)
                printf("<v%d,v%d> length:%d,",GL->adjList[j].data,GL->adjList[k].data,e->weight);
        }
    }
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
