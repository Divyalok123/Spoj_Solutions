#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 1e8
int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    int* arr = new int[n+1];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);
    int count = 0;
    int val;
    for(int i = 0; i < n-1; i++)
    {
        if(binary_search(arr+i+1, arr+n, arr[i]+k))
        {
            count++;
        }
    }

    // int i = 0, j = 1;
    // while(j < n)
    // {
    //     if(arr[j]-arr[i] == k)
    //     {
    //         count++;
    //         j++;
    //     }
    //     else if(arr[j]-arr[i] > k)
    //         i++;
    //     else
    //         j++;
    // }

    delete[] arr;
    cout << count << endl;
    return 0;
}