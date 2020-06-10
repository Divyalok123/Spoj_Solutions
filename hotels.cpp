#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    long long* arr = new long long[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int i = 0;
    long long sum = 0;
    while(i < n && arr[i] + sum <= m)
    {
        sum += arr[i];
        i++;
    }

    if(sum == m || i == n)
    {
        cout << sum << endl;
        return 0;
    }

    long long max = sum;
    int j = 0;
    while(i < n )
    {
        if(i < n) sum += arr[i];
        while(sum > m) {
            sum -= arr[j]; 
            j++;
        }
        i++;
        if(sum > max && sum <= m)
            max = sum;
    }

    cout << max << endl;
    return 0;
}