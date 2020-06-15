#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll unsigned long long int

ll multiply(ll a, ll b, ll m)
{
    ll res = 0;
    a %= m;
    while(b)
    {
        if(b&1) res = (res+a)%m;
        a = (a*2)%m;
        b >>= 1;
    }
    return res%m;
}

ll modular(ll x, ll y, ll m)
{
    ll res = 1;
    while(y){
        if(y&1)
            res = multiply(res, x, m)%m;
        y >>= 1;
        x = multiply(x, x, m)%m;
    }

    return (res)%m;
}

//using miller-rabin (deterministic)
bool composite(ll n, ll a, ll d, ll r)
{
    ll x = modular(a, d, n);
    if(x == 1 || x == n-1)
        return false;

    for(ll s = 0; s < r; s++)
    {
        x = multiply(x, x, n);
        if(x == n-1)
            return false;
    }

    return true;
}

bool miller(ll n)
{
    if(n < 4)
        return n == 2 || n == 3;

    if(n%2 == 0 || n%3 == 0) return false;
    
    ll r = 0;
    ll d = n-1;
    while((d&1) == 0)
    {
        d >>= 1;
        r++;
    }

    for(ll a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if(n == a) return true;
        if(composite(n, a, d, r))
            return false;
    }

    return true;
}

//using fermat little
bool fermat(ll n)
{
    if(n < 4)
        return n == 2 || n == 3;

    for(int i = 0; i < 25; i++)
    {
        ll randnum = 2 + rand()%(n-3);
        if(modular(randnum, n-1, n) != 1)
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;

        bool ans = miller(n);
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return  0;
}