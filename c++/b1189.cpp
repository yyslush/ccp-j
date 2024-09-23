#include<iostream>
using namespace std;

int Ackerman(int m, int n);

int main()
{
    int m, n;  
    cin >> m >> n;   
    cout << Ackerman(m, n) << endl;
    return 0;
}

int Ackerman(int m, int n)
{
    if (m == 0)
        return n + 1;
    else
    {
        if (m > 0 && n == 0)
            return Ackerman(m - 1, 1);
        else
            if (m > 0 && n > 0)
                return Ackerman(m - 1,Ackerman(m, n - 1));
    }
}
