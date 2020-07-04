#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        // vector<long long> v;
        long long a;
        long long sum = 0;
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            res += i*(a) - sum;
            sum += a;
        }
        cout  << res << endl;
        
    }

    return 0;
}