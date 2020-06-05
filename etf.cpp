#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

/* just for practice! (to find all totients between 1 to n)

void phi(int n)
{
    vector<int> phis(n+1);
    phis[0] = 0;
    phis[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        phis[i] = i;
    }

    for(int i = 2; i <= n; i++)
    {
        if(phi[i] == i)
        {
            for(int j = i; j <= n; j+=i)
            {
                phis[j] -= phis[j]/i;
            }
        }
    }
}

*/

//for only a number n
int phi(int n)
{
    int res = n;
    for(int i = 2; (long long)i*i <= n; i++)
    {
        if(n%i == 0)
        {
            while(n%i == 0)
                n /= i;
            res -= (res/i);
        }
    }

    if(n > 1)
    {
        res -= res/n;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int count = phi(n);
        cout << count << endl;
    }

    return 0;
}

