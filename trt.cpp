#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int dp[2002][2002];

int solve(int *arr, int i, int j, int count)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int a = arr[i] * count + solve(arr, i + 1, j, count + 1);
    int b = arr[j] * count + solve(arr, i, j - 1, count + 1);

    dp[i][j] = max(a, b);
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int arr[2002];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = solve(arr, 0, n - 1, 1);
    cout << ans << endl;

    return 0;
}