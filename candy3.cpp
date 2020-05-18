#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define uint unsigned int
// #define endl "\n"

int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cout << endl;
        cin >> n;
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            ans %= n;
            ans += x%n;
        }
        if(ans%n == 0)
        {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}