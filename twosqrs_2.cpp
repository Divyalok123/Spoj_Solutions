#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

/* --- Fermats theorem --- */

bool check(ll n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        int count = 0;
        if(n%i == 0)
        {
            while(n%i == 0)
            {
                    count++;
                n /= i;
            }
            if(i%4 == 3 && count %2 == 1)
            {
                return false;
            }
        }
    }
    return n%4 != 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;

        ll sqr = floor(sqrt(n));
        if(sqr*sqr == n) 
        {
            cout << "Yes" << endl;
            continue;
        }

        if(check(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;  
}