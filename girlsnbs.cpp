#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int g, b;
    cin >> g >> b;
    while(g != -1 && b != -1)
    {
        int minone = min(g, b);
        int maxone = max(g, b);

        if(minone == 0 && maxone == 0) cout << 0 << endl;
        else if(minone == maxone) cout << 1 << endl;
        else 
        {
            int ans = ceil((double)(maxone)/(double)(minone + 1));
            cout << ans << endl;
        }
        cin >> g >> b;
    }

    return 0;
}