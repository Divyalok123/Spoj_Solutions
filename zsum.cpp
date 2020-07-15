#include <iostream>
#include <cmath>
using namespace std;
#define MOD 10000007
#define ll long long

ll m(ll n) {
    return n % MOD;
}

ll power(ll n, ll k) {
    n = m(n);
    ll res = 1;
    while(k) {
        if(k&1) {
            res = m(res*n);
        }

        k >>= 1;
        n = m(n*n);
    }

    return res;
}

ll solve(ll n, ll k) {
    int p1 = m(2*power(n-1, k));
    int p2 = m(power(n, k));
    int p3 = m(power(n, n));
    int p4 = m(2*power(n-1, n-1));

    // cout << "p1: " << p1 << endl;
    // cout << "p2: " << p2 << endl;
    // cout << "p3: " << p3 << endl;
    // cout << "p4: " << p4 << endl;

    return m(p1 + p2 + p3 + p4);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    ll n, k;
    cin >> n >> k;

    while(n) {
        cout << solve(n, k) << endl;
        cin >> n >> k;
    }

    return 0;
}