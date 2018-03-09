/*************************************************************************
	> File Name: 数据结构课设.cpp
	> Author: 魍魉楼主
	> Mail: wangxufeng1997@outlook.com
	> Created Time: 2018年01月03日 星期三 10时44分16秒
 ************************************************************************/

#include<iostream>
#include<ctime>
#include<iomanip>
#include<cstdlib>
using namespace std;
const int MAXSIZE=10010;
template<class KeyType,class InfoType>
struct RedType{
    KeyType key;
    InfoType otherinfo;
    inline bool operator <(const RedType&L);
    inline bool operator >(const RedType&L);
};
template<class KeyType,class InfoType>
bool RedType<KeyType,InfoType>::operator  <(const RedType&L){
    return key<L.key;
}
template<class KeyType,class InfoType>
bool RedType<KeyType,InfoType>::operator >(const RedType&L){
    return key>L.key;
}
template<class KeyType,class InfoType>
struct SqList{
RedType<KeyType,InfoType>r[MAXSIZE+1];
int length;
int move;
int compare;
};
template<class KeyType,class InfoType>
void swap(SqList<KeyType,InfoType>*L,int i,int j){
RedType<KeyType,InfoType> temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
    L->move+=3;
}
template<class KeyType,class InfoType>
void BubbleSort(SqList<KeyType,InfoType>*L){
    int i,j;
    bool flag=true;
    for(i=1;i<L->length&&flag;i++){
        flag=false;
        for(j=L->length-1;j>=i;j--){
            if(L->r[j].key>L->r[j+1].key){
                swap(L,j,j+1);
                flag=true;
            }
            L->compare++;
        }
    }
}
template<class KeyType,class InfoType>
void SelectSort(SqList<KeyType,InfoType>*L){
    int i,j,m;
    KeyType t;
    for(i=1;i<L->length;i++){
        m=i;
        for(j=i+1;j<=L->length;j++){
            if(L->r[j].key<L->r[m].key){
                m=j;
            }
            L->compare++;
        }

        if(m!=i){
            swap(L,i,m);
        }
    }
}
template<class KeyType,class InfoType>
void InsertSort(SqList<KeyType,InfoType>*L){
    int i,j;
    for(i=2;i<=L->length;i++){
        if(L->r[i].key<L->r[i-1].key){
            L->r[0]=L->r[i];
            L->move++;
            for(j=i-1;L->r[j].key>L->r[0].key;j--)
                L->r[j+1]=L->r[j],L->compare++,L->move++;
            L->r[j+1]=L->r[0];
            L->move++;
        }
        L->compare++;
    }
}
template<class KeyType,class InfoType>
void BoxSort(SqList<KeyType,InfoType>*L,SqList<KeyType,InfoType>Box[]){
    for(int i=1;i<=L->length;i++){
        Box[L->r[i].key%10].r[Box[L->r[i].key%10].length++].key=L->r[i].key;
        L->move++;
    }
    for(int i=0;i<10;i++){
        InsertSort(&Box[i]);
        L->move+=Box[i].move;
        L->compare+=Box[i].compare;

    }       
}
template<class KeyType,class InfoType>
void HeapAdjust(SqList<KeyType,InfoType>*L,int s,int m){
    int temp,j;
    temp=L->r[s].key;
    for(j=2*s;j<=m;j*=2){
        if(j<m){
            L->compare++;
            if(L->r[j]<L->r[j+1])
            ++j;
        }
        L->compare++;
        if(temp>=L->r[j].key)
            break;
        L->r[s]=L->r[j];
        L->move++;
        s=j;
    }
    L->r[s].key=temp;
    L->move++;
}
template<class KeyType,class InfoType>
void HeapSort(SqList<KeyType,InfoType>*L){
    int i;
    for(i=L->length/2;i>0;i--)
        HeapAdjust(L,i,L->length);
    for(i=L->length;i>1;i--){
        swap(L,1,i);
        HeapAdjust(L,1,i-1);
    }
}
template<class KeyType,class InfoType>
int Partition(SqList<KeyType,InfoType>*L,int low,int high){
    int pivotkey;
    pivotkey=L->r[low].key;
    while(low<high){
        while(low<high&&L->r[high].key>=pivotkey)
            high--,L->compare++;
        swap(L,low,high);
        while(low<high&&L->r[low].key<=pivotkey)
            low++,L->compare++;
        swap(L,low,high);
    }
    return low;
}
template<class KeyType,class InfoType>
void Qsort(SqList<KeyType,InfoType>*L,int low,int high){
    int pivot;
        if(low<high){
            pivot=Partition(L,low,high);
            Qsort(L,low,pivot-1);
            Qsort(L,pivot+1,high);
        }
}
template<class KeyType,class InfoType>
void QuickSort(SqList<KeyType,InfoType>*L){
    Qsort(L,1,L->length);
}
template<class KeyType,class InfoType>
void Merge(SqList<KeyType,InfoType>*L,RedType<KeyType,InfoType> SR[],RedType<KeyType,InfoType> TR[],int i,int m,int n){
    int j,k,l;
    for(j=m+1,k=i;i<=m&&j<=n;k++){
        if(SR[i]<SR[j])
            TR[k]=SR[i++];
        else
            TR[k]=SR[j++];
        L->move++;
        L->compare++;
    }
    if(i<=m){
        for(l=0;l<=m-i;l++)
            TR[k+1]=SR[i+1],L->move++;
    }
    if(j<=n){
        for(l=0;l<=n-j;l++)
            TR[k+1]=SR[j+1],L->move++;
    }
}
template<class KeyType,class InfoType>
void MSort(SqList<KeyType,InfoType>*L,RedType<KeyType,InfoType> SR[],RedType<KeyType,InfoType> TR1[],int s,int t){
    int m;
    RedType<KeyType,InfoType> TR2[MAXSIZE+1];
    if(s==t){
        TR1[s]=SR[s];
        L->move++;
    }
    else{
        m=(s+t)/2;
        MSort(L,SR,TR2,s,m);
        MSort(L,SR,TR2,m+1,t);
        Merge(L,TR2,TR1,s,m,t);
    }
}
template<class KeyType,class InfoType>
void MergeSort(SqList<KeyType,InfoType>*L){
    MSort(L,L->r,L->r,1,L->length);
}
int main(){
    int n;
    cout<<setw(40)<<"请输入比较组数:";
    cin>>n;
    for(int i=0;i<n;i++){
        int len;
        int dis=1000000;
        cout<<setw(50)<<"请输入表长(不超过10000):";
        cin>>len;
        srand((int)time(NULL));
        SqList<int,int>L[8];
        for(int i=1;i<=7;i++)
            L[i].length=L[i].move=L[i].compare=0;
        for(int i=0;i<len;i++){
            int m=rand()%dis;
            int n=rand()/m;
            for(int j=1;j<=7;j++)
                L[j].r[++L[j].length].key=n;
        }
        cout<<setw(37)<<"随机生成表为:"<<endl;
        cout<<setw(50);
        for(int i=1;i<=L[1].length;i++){
            if((i-1)%10==0&&i!=1)
                cout<<endl,setw(50);
            cout<<setw(6)<<L[1].r[i].key<<" ";
        }
        cout<<endl<<endl;
        BubbleSort(&L[1]);
        InsertSort(&L[2]);
        SelectSort(&L[3]);
        SqList<int,int>Box[11];
        for(int i=0;i<11;i++)
            Box[i].length=Box[i].compare=Box[i].move=0;
        BoxSort(&L[4],Box);
        HeapSort(&L[5]);
        QuickSort(&L[6]);
        MergeSort(&L[7]);
        cout<<setw(27)<<"冒泡排序"<<setw(14)<<"直接排序"<<setw(14)<<"选择排序"<<setw(14)<<"箱子排序"<<setw(12)<<"堆排序"<<setw(14)<<"快速排序"<<setw(14)<<"归并排序"<<endl;
        cout<<"关键字比较次数:";
        for(int i=1;i<=7;i++)
            cout<<setw(8)<<L[i].compare<<" ";
        cout<<endl;
        cout<<"关键字移动次数:";
        for(int i=1;i<=7;i++)
            cout<<setw(8)<<L[i].move<<" ";
        cout<<endl;
        system("pause");
        system("clear");
    }
    return 0;
}
