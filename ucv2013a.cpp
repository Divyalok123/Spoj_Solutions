#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

#define MOD 1000000007
#define ll long long

ll modulo(ll n)
{
    if(n < 0) n += MOD; 
    return n%MOD; 
}

ll power(ll n, ll m) {
    ll ans = 1;
    n %= MOD;
    while(m)
    {
        if(m&1)
        {
            ans = modulo(ans*n);
        }
        m >>= 1;
        n = modulo(n*n);
    }

    return ans;
}

ll find_gcd(ll a, ll b, ll& x, ll& y)
{
    ll x1, y1;
    if(a == 0)
    {
        x = 0; y = 1;
        return b;
    }

    ll temp = find_gcd(b%a, a, x1, y1);
    x = y1 - x1 * (b/a);
    y = x1;
    return temp;
}

ll inverse(ll n)
{
    ll x, y;
    ll gcd = find_gcd(n, MOD, x, y);
    return x < 0 ? x + MOD : x;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, l;
    cin >> n >> l;

    while(n != 0)
    {   
        ll ans = power(n, l);
        ans--;
        ans = modulo(ans*n);
        ans = modulo(ans*inverse(n-1));
        cout << ans << endl;
        cin >> n >> l;
    }

    return 0;
}