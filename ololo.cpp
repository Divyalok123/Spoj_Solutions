#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    if(n == 0) return 0;
    int x;
    cin >> x;
    long long res = (long long)x;
    while(--n)
    {
        cin >> x;
        res ^= x;
    }

    cout << res << endl;

    return 0;
}