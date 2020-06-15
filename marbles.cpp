#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define ll unsigned long long int

// ll solve(ll n, ll k)
// {
//     if(n < k)
//         return 0;
//     if(n == k)
//         return 1;
//     if(k == 1)
//         return n; 

//     k = min(k, n-k);
//     ll dp[n+1][k+1];

//     for(int i = 0; i <= n; i++)
//     {
//         for(int j = 0; j <= k; j++)
//         {
//             if(j == 0 || j == i)
//                 dp[i][j] = 1;
//             else
//             {
//                 dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
//             }
//         }
//     }
//     return dp[n][k];
// }

ll solve(ll n, ll k)
{
    ll num = 1, den = 1;

    k = min(k, n-k);

    if(k!=0)
    {
        while(k)
        {
            num *= (n/k);
            den *= (k);

            n--;
            k--;

            ll todivide = __gcd(num, den);

            num /= todivide;
            den /= todivide;
        }
        
        return num;
    }
    else return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; 
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;

        ll ans = solve(n-1, k-1);
        cout << ans << endl;
    }
    return 0;
}