#include<iostream>  
#include<cstring>   
using namespace std;  
int main()  
{  
    int n;  
    int a=0,b=0,w=0,m=0;  
    char c='0';  
    char st[1000];  
    cin>>n;  
    cin>>st;  
    memcpy(st+n,st,n);  
    int i;  
    for(i=0;i<=2*n;i++)  
    {  
        if(st[i]=='w')  
        {  
            b++;  
            w++;//��¼����w����Ŀ  
        }  
        else if(st[i]==c)  
        {  
            b++;//��¼ǰһ��b/r��������Ŀ  
            w=0;  
        }  
        else//��ʱ�ҵ�һ���������ʼͳ����Ŀ  
        {  
            m=max(a+b,m);//�ҳ�����  
            a=b-w;  
            b=w+1;  
            w=0;  
            c=st[i];//��ʱ������Ҫ�Ƚϵ��µ�b/r  
        }  
    }  
    m=max(m,a+b);  
    m=min(m,n);  
    cout<<m;  
    return 0;  
}  

