#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cctype>
#include<vector>
#include<map>
using namespace std;
const int maxn=80;
int n,a[maxn],maxv,tot,vis[maxn],k,len;
bool cmp(int a,int b)
{
    return a>b;
}
bool run(int i,int rest,int p)//��i�ѻ���rest�ĳ��ȵ�len,��i���иղ�ѡ�˵�p�� 
{
    if(i>k)//��k�� 
    {
        return 1;
    }
    int fail=0; 
    for(int x=p+1;x<=n;x++)//�ӵ�p+1����ʼѡ
    if(!vis[x])
    { 
        if(a[x]==a[fail]) continue;//ע��continue��return
        if(rest>a[x]) 
        {
            vis[x]=1;
            bool w=run(i,rest-a[x],x);
            vis[x]=0;
            if(!w) fail=x;
            if(w) return 1;
        }
        else if(rest==a[x])
        {
            vis[x]=1;
            bool w=run(i+1,len,0);
            vis[x]=0;
            return w;
        }
        if(p==0) return 0; 
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        maxv=max(maxv,a[i]);
        tot+=a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(len=maxv;len<=tot;len++)
    if(tot%len==0)
    {
        k=tot/len;
        if(run(1,len,0)) 
        {
            printf("%d",len);
            break;
        }
    }
    return 0;
}

