#include <bits/stdc++.h>
using namespace std ;

const int maxn = 6010, zhf = 0x7f7f7f7f ;
int f[maxn], a[1010], b[1010];

int main()
{
    int k,m,n,sum ;
    scanf("%d",&n) ; m=sum=0;
    for(int i=1;i<=n;i++)
	{
        scanf("%d%d",a+i,b+i);
        m+= max(a[i],b[i]) ; // ��¼����ĺ����Ŀ���ֵ
        sum+=a[i] + b[i] ; // ��¼�ܺ�
    }
    memset(f,zhf, sizeof(f)); // ��ʼ��
    f[0]=0 ; // �߽�
    for(int i=1;i<=n;i ++) 
        for(int j=m;j>=0;j--)
		{
            int ans=zhf; // ���ȼ���������
            if (j>=a[i]) // ��Ȼ���п�����������
                ans=f[j-a[i]];
            if (j>=b[i])
                ans=min(ans,f[j-b[i]]+1);
            f[j]=ans ;
            // ע�⣬����ͨ01������ͬ���ǣ�������Ҫǿ��ѡ��ת���ǲ�ת
        }
    for(int i=sum>>1;i;i--)
	{
        k=min(f[i],f[sum-i]);//�ҳ���С
        if(k<zhf) 
		{
            printf("%d\n",k);
            return 0 ;
        }
    }
    return 0 ;
}
