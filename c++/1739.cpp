#include <iostream>
using namespace std;

int main()
{
    int N;  //��ţ����
    while (cin>>N)
    {
        int *a = new int [N];  //��̬һά����  �����ţ���
        int i, num1=0, num2=0, num3=0;  
        for (i = 0; i < N; ++i)
        {
            cin >> a[i];
            if (a[i] == 1)
                num1++;  //���Ϊ1 ����ţ����
            else if (a[i] == 2)
                num2++;  //���Ϊ2 ����ţ����
            else
                num3++;  //���Ϊ3 ����ţ����
        }
        int res = 0;    //��������
        for (i = 0; i < num1; i++)   //����0~��num1-1��
        {
            if (a[i] != 1)    //��Ų�Ϊ1 ����Ҫ����
                res++;
        }
        for (i = num1; i < num1+num2; i++)  //����num1~��num1+num2-1��
        {
            if (a[i] == 3)//���Ϊ3����Ҫ��������Ϊ���2���ý��������1��ͳ�ƹ�������
                res++;
        }
        cout << res << endl;  //�����������
    }   
    return 0;
}
