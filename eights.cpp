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
#define endl "\n"

ll solve(ll k)
{
    return (192 + (k-1)*250);
}

// void checker() //Found the pattern 192 + 250*n
// {
//     int i = 0;
//     int k = 192;
//     cout << k << endl;
//     k++;
//     while(i < 10)
//     {
//         if((k*k*k)%1000 == 888)
//         {
//             cout << k << endl;
//             i++;
//         }
//         k++;
//     }
// }

int main() {
    fast;
    checker();
    int t;
    cin >> t;
    while(t--)
    {
        ll k;
        cin >> k;
        ll ans = solve(k);
        cout << ans << endl;
    }
    return 0;
}