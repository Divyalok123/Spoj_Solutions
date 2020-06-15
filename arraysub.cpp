#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>
#include <deque>
using namespace std;
vector<int> ans, arr;
int n, k;

//brute force
// void solve(int* arr, int n, int k)
// {
//     for (int i = 0; i < n - k + 1; i++)
//     {
//         int max = INT_MIN;
//         for (int j = i; j < i + k; j++)
//         {
//             if (max < arr[j])
//                 max = arr[j];
//         }
//         ans.push_back(max);
//     }

//     for (int i = 0; i < n - k + 1; i++)
//     {
//         cout << ans[i] << " ";
//     }
//     cout << endl;
// }

//using segment trees
// vector<int> seg;

// void build(int v, int l, int r){
//     if(l == r)
//         seg[v] = arr[l];
//     else
//     {
//         int mid = l + (r-l)/2;
//         build(2*v+1, l, mid);
//         build(2*v+2, mid+1, r);
//         seg[v] = max(seg[2*v+1], seg[2*v+2]);
//     }
// }

// int query(int v, int l, int r, int ql, int qr)
// {
//     if(ql > qr)
//         return INT_MIN;
//     if(l == ql && r == qr)
//         return seg[v];
//     int mid = l + (r-l)/2;
//     int left = query(2*v+1, l, mid, ql, min(qr, mid));
//     int right = query(2*v+2, mid+1, r, max(mid+1, ql), qr);
//     return max(left, right);    
// }

//using deque (best solution)
deque<int> d;
void dq() {
    for(int i = 0; i < k; i++)
    {
        while(!d.empty() && arr[i] >= arr[d.back()])
            d.pop_back();
        d.push_back(i);
    }

    for(int i = k; i < n; i++)
    {
        ans.push_back(arr[d.front()]);
        while(!d.empty() && arr[i] >= arr[d.back()])
            d.pop_back();
        d.push_back(i);
        while(!d.empty() && d.front() <= i-k)
            d.pop_front();
    }
    ans.push_back(arr[d.front()]);

    for(int i = 0; i < n-k+1; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    arr.assign(n+1, 0);
    // seg.assign(4*n+1, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    // build(0, 0, n-1);

    // solve(arr, n, k); //brute
    //segment
    /* 
    for(int i = 0; i < n-k+1; i++)
    {
        ans.push_back(query(0, 0, n-1, i, i+k-1));
    }

    for(int i = 0; i < n-k+1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl; */

    //deque
    dq();
    return 0;
}