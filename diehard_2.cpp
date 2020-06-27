#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

/* --- Greedy --- */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int h, a;
        cin >> h >> a;
    
        int ans = 0;
        bool flag = false;// at air if false and others if true
        while(h > 0 && a > 0)
        {
            if(!flag)
            {
                ans++;
                h += 3;
                a += 2;
                flag = true;
            }
            else
            {
                if(h > 20 && a <= 10)
                {
                    h -= 20;
                    a += 5;
                }
                else if(h > 5 && a > 10)
                {
                    h -= 5;
                    a -= 10;
                }
                else
                {
                    break;
                }
                flag = false;
                ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}