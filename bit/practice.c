#include <iostream>

using namespace std;

int getbit(int n, int x)
{
    int mask = 1 << n;
    return x & mask;
}

void setBit(int n, int &x)
{
    // x = 101
    // m = 10;
    int mask = 1 << n;
    x = x | mask;
}
void clearBit(int n, int &x)
{
    // 101001
    // 001000 ~ => 110111 &;
    int m = ~(1 << n);
    x = x & m;
}

void updateBit(int n, int &x)
{
    int b = getbit(n, x);
    if (b == 1)
        clearBit(n, x);
    else
        setBit(n, x);
}

void setMWithNFrom(int &M, int N, int i, int j)
{
    // M = 1000000000
    // N =    10101
    N = N << i;
    for (int k = 2; k = 6; k++)
        clearBit(k, M);
    M = M | N;
}

int countBits(int n)
{
    int t = 0;
    while (n > 0)
    {
        if (n & 1 == 1)
            t++;
        n = n >> 1;
    }
    return t;
}

bool isSquareOf2(int n) {
    int n1 = n -1;
    return n & n1 == 0 
}

int power(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int n, x;
    cout << "Enter n" << endl;
    cin >> n;
    cout << "Enter x" << endl;
    cin >> x;
    // if (x & 1) cout<<"Odd"<<endl;
    // else cout<<"Even"<<endl;
    // cleatBit(n,x);
    cout << "n=" << n << " x=" << x << "power " << power(x, n) << endl;

    return 0;
}