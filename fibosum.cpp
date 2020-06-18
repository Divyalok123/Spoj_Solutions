#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define ll long long int

ll modulo(ll n)
{
    return (n % MOD + MOD) % MOD;
}

ll multiply(ll a, ll b)
{
    ll ans = 0;
    while (b)
    {
        if (b & 1)
            ans = modulo(ans + a);
        b >>= 1;
        a = modulo(a * 2);
    }
    return ans;
}

void multiply(ll matrix[2][2], ll matrix2[2][2])
{
    ll x = multiply(matrix[0][0], matrix2[0][0]) + multiply(matrix[0][1], matrix2[1][0]);
    ll y = multiply(matrix[0][0], matrix2[0][1]) + multiply(matrix[0][1], matrix2[1][1]);
    ll z = multiply(matrix[1][0], matrix2[0][0]) + multiply(matrix[1][1], matrix2[1][0]);
    ll m = multiply(matrix[1][0], matrix2[0][1]) + multiply(matrix[1][1], matrix2[1][1]);

    matrix[0][0] = modulo(x);
    matrix[0][1] = modulo(y);
    matrix[1][0] = modulo(z);
    matrix[1][1] = modulo(m);
}

void power(ll matrix[2][2], ll n)
{
    if (n == 0 || n == 1)
        return;
    ll mymatrix[2][2] = {{1, 1}, {1, 0}};

    power(matrix, n / 2);
    multiply(matrix, matrix);

    if (n%2 == 1)
        multiply(matrix, mymatrix);
}

ll fibo(ll n)
{
    ll mat[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
    {
        return 0;
    }

    power(mat, n-1);
    return mat[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << (fibo(m+2) - fibo(n+1) + MOD)%MOD << endl;
    }
    return 0;
}

