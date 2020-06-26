#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

/* -- Willson's algo -- */

ll power(ll n, ll m, ll p)
{
    ll ans = 1;
    n %= p;

    while(m)
    {
        if(m&1)
            ans = (ans*n)%p;
        m >>= 1;
        n = (n*n)%p;
    }
    return ans;
}

ll inverse(ll n, ll p)
{
    return power(n, p-2, p);
}

void solve(ll n, ll p) {
    if(n >= p)
    {
        cout << 0 << endl;
        return;
    }

    ll res = p-1;
    for(int i = n+1; i < p; i++)
    {
        res = (res*inverse(i, p))%p;
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n, p;
        cin >> n >> p;

        solve(n, p);
    }
    return 0;
}