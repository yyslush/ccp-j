#include<cstdio>  
#include<cstring>  
using namespace std;

long up[10000],down[10000],ck[10000];  
int main()  
{  
    long a,n,m,x,flag,i,j;  
    scanf("%ld %ld %ld %ld",&a,&n,&m,&x);  
    memset(ck,0,sizeof(ck));  
    up[1]=a;  flag=0;//up��ʾ�ϳ�����   down��ʾ�³�����   ck��ʾ�˿�����  
    down[1]=0; ck[1]=a;  
    for(i=0;i<=m;i++)  
    {  
       up[2]=i,down[2]=i,ck[2]=ck[1];//�˿����ǵ����ģ��������m�������Եڶ�վ�³�����ֻ����0��m֮��  
       for(j=3;j<n;j++)  
       {  
           up[j]=up[j-1]+up[j-2];  
           down[j]=up[j-1];  
           ck[j]=ck[j-1]+up[j-2];  
       }  
       if(ck[n-1]==m){  printf("%ld\n",ck[x]); flag=1;  break;  }  //���n-1վ����������m����  
       
    }  
    if(!flag)  printf("No answer.\n");   
    return 0;  
}  
