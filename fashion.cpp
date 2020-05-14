#include <iostream>
#include <algorithm>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n";

int main() {
    fast
    int t;
    cin >> t;
    while(t--)
    {
        int n; 
        cin >> n;
        int* men = new int[n];
        int* women = new int[n];

        for(int i = 0; i < n; i++)
        {
            cin >> men[i];
        }

        for(int i = 0; i < n; i++)
        {
            cin >> women[i];
        }

        sort(men, men+n);
        sort(women, women+n);

        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += (long long)(men[i]*women[i]);
        }

        cout << ans << endl;

    }
	return 0;
}