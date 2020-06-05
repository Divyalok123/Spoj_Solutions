#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
#define ll long long

void solve(ll *arr, int n, int cas)
{
    cout << "Case " << cas << ": ";
    ll *dp = new ll[n];
    dp[0] = 0;

    if (n == 0)
    {
        cout << 0 << endl;
        cout << endl;
        return;
    }

    if (n == 1)
    {
        cout << arr[0] << endl;
        return;
    }

    dp[0] = arr[0];
    dp[1] = max(arr[1], arr[0]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
    }
    cout << dp[n - 1] << endl;
    delete[] dp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int cas = 1;
    while (t--)
    {
        int n;
        cin >> n;
        ll *arr = new ll[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        solve(arr, n, cas);
        cas++;
        delete[] arr;
    }
    return 0;
}