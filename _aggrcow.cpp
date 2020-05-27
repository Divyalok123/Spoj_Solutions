#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isValid(long* arr, int n, int c, long midval)
{
    // int start = 0;
    int i = 0;
    int j = i+1;
    int end = n-1;
    int count = 1;
    while(j <= end)
    {
        if(arr[j]-arr[i] >= midval)
        {
            count++;
            i = j;
            j = j + 1;
        }
        else
        {
            j++;
        }
        if(count == c)
        {
            return true;
        }
    }
    return false;
}

int main() {
	int t;
    cin >> t;
    while(t--)
    {
        int n, c;
        cin >> n >> c;

        if(n < c)
        {
            cout << -1 << "\n";
            continue;
        }    

        long * arr = new long[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr+n);

        long start = 0;
        long end = arr[n-1];

        long res = -1;
        while(start <= end)
        {
            long mid = start + (end-start)/2;
            if(isValid(arr, n, c, mid))
            {
                res = mid;
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
            
        }
        delete[] arr;
        cout << res << "\n";
    }
	return 0;
}
