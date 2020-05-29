// #include <iostream>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// bool isValid(long* arr, int n, int c, long midval)
// {
//     // int start = 0;
//     int i = 0;
//     int j = i+1;
//     int end = n-1;
//     int count = 1;
//     while(j <= end)
//     {
//         if(arr[j]-arr[i] >= midval)
//         {
//             count++;
//             i = j;
//             j = j + 1;
//         }
//         else
//         {
//             j++;
//         }
//         if(count == c)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
// 	int t;
//     cin >> t;
//     while(t--)
//     {
//         int n, c;
//         cin >> n >> c;

//         if(n < c)
//         {
//             cout << -1 << "\n";
//             continue;
//         }

//         long * arr = new long[n];
//         for(int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }

//         sort(arr, arr+n);

//         long start = 0;
//         long end = arr[n-1];

//         long res = -1;
//         while(start <= end)
//         {
//             long mid = start + (end-start)/2;
//             if(isValid(arr, n, c, mid))
//             {
//                 res = mid;
//                 start = mid+1;
//             }
//             else
//             {
//                 end = mid-1;
//             }

//         }
//         delete[] arr;
//         cout << res << "\n";
//     }
// 	return 0;
// }

#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

bool ispossible(int* arr, int n, int c, int val)
{
    int i = 0; //first cow is placed
    int j = i+1;
    int end = n-1;
    int count = 1;
    while(j <= end)
    {
        if(arr[j] - arr[i] >= val)
        {
            i = j;
            j++;
            count++;
        }
        else
        {
            j++;
        }

        if(count == c)
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, c;
        cin >> n >> c;
        int* arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr+n);

        int i = 0;
        int j = arr[n-1];

        int res;
        while(i <= j)
        {
            int mid = i + (j-i)/2;
            if(ispossible(arr, n, c, mid))
            {
                res = mid;
                i = mid+1;
            }
            else
                j = mid-1;
        }
        delete[] arr;
        cout << res << endl;
    }

    return 0;
}

