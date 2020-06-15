#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int arr[20004];

void solve(int n, int k)
{
    sort(arr, arr + n);

    int minm = arr[k - 1] - arr[0];
    for (int i = k; i < n; i++)
    {
        int currmin = arr[i] - arr[i - k + 1];
        if (currmin < minm)
            minm = currmin;
    }

    cout << minm << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (k == 1)
        {
            cout << 0 << endl;
            continue;
        }

        solve(n, k);
    }

    return 0;
}