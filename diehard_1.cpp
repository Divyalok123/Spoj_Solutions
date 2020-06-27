#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

/* ---- DP ---- */

int dp[1300][1300];

int solve(int h, int a, int count, char p)
{
    if (h <= 0 || a <= 0)
        return count;
    if (dp[h][a] != -1)
        return dp[h][a];
    int ans = 0;
    if (p == 'A')
        ans = max(solve(h - 20, a + 5, count + 1, 'F'), solve(h - 5, a - 10, count + 1, 'W'));
    else
        ans = solve(h + 3, a + 2, count + 1, 'A');
    dp[h][a] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int h, a;
        cin >> h >> a;
        memset(dp, -1, sizeof(dp));
        int ans = solve(h + 3, a + 2, 0, 'A');
        cout << ans << endl;
    }
    return 0;
}