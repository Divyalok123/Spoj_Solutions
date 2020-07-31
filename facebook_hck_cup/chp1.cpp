#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define ll long long
int t, n, m;
vector<ll> c;
vector<ll> memo;
ll solve(int i, int g, ll cost)
{
    if (i == n - 1) {
        return cost;
    }

    if(g < 0 && c[i] == 0)
        return LLONG_MAX;

    ll ans = LLONG_MAX;
    if (g == 0) {
        if(c[i] != 0)
            ans = solve(i+1, m-1, cost+c[i]);
    }
    else {
        if(i == 0 || c[i] == 0)
            ans = solve(i+1, g-1, cost);
        else
            ans = min(solve(i+1, g-1, cost), solve(i+1, m-1, cost + c[i]));
    }
    return ans;
}

int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> m;
        c.resize(n);
        memo.assign(n, -1);
        for (int j = 0; j < n; j++)
            cin >> c[j];
        ll ans = solve(0, m, 0);
        if (ans == LLONG_MAX)
            ans = -1;
        cout << "Case #" << i << ": " << ans << endl;
        c.clear();
    }

    return 0;
}