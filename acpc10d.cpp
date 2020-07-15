#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long
ll memo[100000][3];

ll solve(vector<vector<ll>> &arr, int n, int i, int j, int prev)
{
    if(i == n-1)
    {
        if(prev == 0 || prev == 1) return min(arr[i][1], arr[i][0] + arr[i][1]);
        else return arr[i][1];
    }

    if (memo[i][j] != -1)
        return memo[i][j];

    ll ans = -1;
    if (j == 0) {
        ans = min(solve(arr, n, i+1, j+1, 0), min(solve(arr, n, i+1, j, 0), solve(arr, n, i, j+1, 0)));
    }
    else if(j == 1) {
        ans = min(solve(arr, n, i+1, j-1, 1), min(solve(arr, n, i+1, j, 1), min(solve(arr, n, i, j+1, 1), solve(arr, n, i+1, j+1, 1))));
    }
    else if(j == 2) {
        ans = min(solve(arr, n, i+1, j, 2), solve(arr, n, i+1, j-1, 2));
    }

    memo[i][j] = arr[i][j] + ans;
    return memo[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, c = 1;
    cin >> n;
    while (n)
    {
        vector<vector<ll>> v(n, vector<ll>(3, 0));
        for (int i = 0; i < n; i++)
        {
            cin >> v[i][0] >> v[i][1] >> v[i][2];
        }

        memset(memo, -1, sizeof(memo));
        ll ans = solve(v, n, 0, 1, 0);

            cout << c << ". " << ans << endl;
        c++;
        cin >> n;
    }

    return 0;
}