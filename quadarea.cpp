#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        long double a, b, c, d;
        cin >> a >> b >> c >> d;

        /* 
        Formula Used:
            Max Area = √(s-a)(s-b)(s-c)(s-d)
        */

        long double s = (a + b + c + d)/2;

        long double f = sqrt((s-a)*(s-b)*(s-c)*(s-d));
        cout << fixed << setprecision(2) << f << endl;    
    }
    return 0;
}