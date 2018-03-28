/*
ID:wangxuf1
PROG:sort3
LANG:C++
 */
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<iostream>
#define X first
#define Y second
#define MP make_pair
#define LL long long
#define pb push_back
#define DEBUG(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const int MAXN=1001;
int n,a[MAXN],ans=0,b[MAXN];
int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memcpy(b,a,sizeof(a));
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==b[i])continue;
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]==b[j]&&a[j]==b[i])
            {
                ans++;
                swap(a[i],a[j]);
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(b[i]==1&&a[i]!=1)
            ans+=2;
    printf("%d\n",ans);
}
