#include<iostream>
using namespace std;
const int MAX_TREE_SIZE=100;
typedef struct CTNode{
    int child;
    struct CTNode*next;
}*ChildPtr;
typedef struct{
    char data;
    ChildPtr firstchild;
    int parent;
}CTBox;
typedef struct{
    CTBox nodes[MAX_TREE_SIZE];
    int r,n;
}CTree;
int main(){

}
