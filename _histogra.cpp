#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <climits>
using namespace std;
#define ll long long

int n;
ll arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    while(n != 0)
    {
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        
        cin >> n;
    }

    return 0;
}