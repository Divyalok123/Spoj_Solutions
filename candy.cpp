#include <iostream>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n";

bool isPossible(int n, int sum)
{
    int val = sum/n;
    return val*n == sum;
}

int main() {
    fast
    int n;
    cin >> n;
    while(n != -1)
    {
        int* arr = new int[n];
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        if(!isPossible(n, sum))
        {
            cout << "-1" << endl;
        }
        else
        {
            int dist = sum/n;
            int ans = 0;
            for(int i = 0; i < n; i++)
            {
                int diff = arr[i] - dist;
                ans += diff > 0 ? diff : 0; 
            }

            cout << ans << endl;
        }
        delete[] arr;
        cin >> n;
    }

    return 0;
}