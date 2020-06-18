#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int

ll arr[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    int i = 1;
    while(t--)
    {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        ll life = 1;
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            if(sum < 0)
            {
                life += -1*(sum);
                sum = 0;
            }
            arr[i] = sum;
        }

        cout << "Scenario #" << i << ": " << life << '\n';
        i++;
    }

    return 0;
}