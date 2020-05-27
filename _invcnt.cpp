#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define uint unsigned int
#define endl "\n"
#define setbits(x) __builtin_popcountll(x) // returns no. of set bits (for GCC compiler.. Much faster) 
typedef priority_queue<int> maxheap;
typedef priority_queue<int, vector<int>, greater<int>> minheap; 

int main() {
    fast;
    int t;
    cin >> t;
    while(t--)
    {
        cout << endl;
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    return 0;
}

//Using Merge sort
/*
ll merge(int* arr, int l, int mid, int r, int* temp)
{
    int i = l; 
    int j = mid+1; 
    int k = l;
    ll inverse_count = 0;
    while(i <= mid && j <= r)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inverse_count += (ll)(mid-i+1);
        }
        
    }

    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while(j <= r)
    {
        temp[k++] = arr[j++];
    }

    for(int i = l; i <= r; i++)
    {
        arr[i] = temp[i];
    }

    return inverse_count;
}

ll mergeSort(int* arr, int l, int r, int* temp)
{
    ll inverse_count = 0;
    if(l < r)
    {
        int mid = l + (r-l)/2;
        inverse_count += mergeSort(arr, l, mid, temp);
        inverse_count += mergeSort(arr, mid+1, r, temp);

        inverse_count += merge(arr, l, mid, r, temp);
    }
    return inverse_count;
}

 */