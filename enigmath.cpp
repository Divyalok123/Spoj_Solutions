#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

long long gcd(long long a, long long b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        long long a, b;
        cin >> a >> b;
        long long div = gcd(a, b);
        long long x = b/div;
        long long y = a/div;
        cout << x << " " << y << endl;
    }

    return 0;
}