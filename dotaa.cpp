#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, m, d, h, count = 0;
        cin >> n >> m >> d;

        for(int i = 0; i < n; i++)
        {
            cin >> h;
            int val1 = (int)((double)((double)h/(double)d)*100000);
            int val2 = (h/d)*100000;
            if(val1 == val2) {
                count += h/d-1;
            }
            else
                count += h/d;
        }

        if(count >= m)
        {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;

    }

    return 0;
}