#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

ll squares[1000001];

void get()
{
    for(int i = 0; i <= 1000000; i++)
    {
        squares[i] = (ll)i*i;
    }
}

bool check(ll n)
{
    int i = 0, j = (int)ceil(sqrt(n));

    while(i <= j)
    {
        if(squares[i] + squares[j] == n)
            return true;
        else if(squares[i] + squares[j] < n)
            i++;
        else
            j--;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    get();
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