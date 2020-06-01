#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define ull unsigned long long

void solve(ull n)
{
    ull ans = n*(3*n+1)/2;
    cout << ans%(1000007) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ull n;
        cin >> n;
        solve(n);
    }

    return 0;
}