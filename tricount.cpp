#include <iostream>
#include <cmath>
using namespace std;
#define ull unsigned long long int
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ull n;
        cin >> n;
        ull u = n*(n+1)*(n+2)/6;
        bool f = n%2 == 0 ? 1 : 0;
        n = n/2;
        ull d = n*(n+1)*(4*n+5)/6;
        ull r = n*(n+1);
        ull a = f ? (u + d - r) : (u + d);
        cout << a << endl;
    }
    return 0;
}

/*

Upwards: n*(n+1)*(n+2)/6
Downwards: (Take half of the level -> n)
    Odd: n*(n+1)*(4*n + 5)/6
    Even: (n*(n+1)*(4*n + 5)/6) - (n*(n+1))

*/

/*

Direct formula: n*(n+2)*(2*n+1)/8;

*/