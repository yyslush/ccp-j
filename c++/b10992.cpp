#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include<cmath>
using namespace std;
inline void keep_window_open(){ char ch; cin >> ch; }
int main()
{
    cout << "How many primes do you want to find out?";
    int n, upper_limit, i, multiple, k;
    cin >> n;
    upper_limit = 3 * n*(log(n) + log(log(n)) - 1); //����Rosser�������������Rosser������n�㹻��ʱ����Ч���Ϻã����Գ�3������
    vector<int>primes;
    for (i = 0; i <= n; ++i)
        primes.push_back(1);   //����Ԫ��ֵ��Ϊ1����Ԫ������Ϊ����������Ԫ����Ϊ0����Ԫ������������������ʼʱ������������Ϊ������
    primes[0] = 0;
    primes[1] = 0;      ////0,1����������   
    for (i = 2; i <= sqrt(n); ++i)
    {
        if (primes[i] == 1)
        {
            for (multiple = 2; i*multiple <= n; ++multiple)
                primes[i*multiple] = 0;
        }
    }
    for (k = 2; k <= n + 1; ++k)
    {
        if (primes[k] == 1)
            cout << k << endl;
    }
}
