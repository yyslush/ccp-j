#include<iostream>
using namespace std;
int n,k,ans=0;
int a[7];
void dfs(int j)//�ֵ���j��
{
    if(n==0)return;//����n����
    if(j==k)//�ֵ����һ��
    {
        if(n>=a[j-1])ans++;//���һ�ݵ�ֵ��С��ǰһ�ݵ�ֵ�������������ַ�+1
        return;
    }
    for(int i=a[j-1];i<=n/(k-j+1);i++)//��j�ݵ����½�
    {
        a[j]=i;//��j�ݵ�ֵ
        n-=i;
        dfs(j+1);//�ֵ�j+1��
        n+=i;
    }
}
int main()
{
    cin>>n>>k;
    a[0]=1;//��ʼ������ʹa[1]���½�Ϊ1
    dfs(1);
    cout<<ans<<endl;
    return 0;
}

