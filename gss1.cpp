#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <stdexcept>
#include <stack>
#include <queue>
#include <vector>
#include <list>

using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define endl "\n"
#define setbits(x) __builtin_popcountll(x) // returns no. of set bits (for GCC compiler.. Much faster) 
typedef priority_queue<int> maxheap;
typedef priority_queue<int, vector<int>, greater<int>> minheap; 
#define maxim 1e17

class store{
public:
    ll maxsubsum;
    ll maxpresum;
    ll maxsuffsum;
    ll totalsum;
    store()
    {
        maxsubsum = maxpresum = maxsuffsum = totalsum = -maxim;
    }
};

store merge(store x, store y)
{
    store res;
    res.maxsubsum = max(max(x.maxsubsum, y.maxsubsum), x.maxsuffsum + y.maxpresum);
    res.maxpresum = max(x.maxpresum, x.totalsum + y.maxpresum);
    res.maxsuffsum = max(y.maxsuffsum, y.totalsum + x.maxsuffsum);
    res.totalsum = x.totalsum + y.totalsum;
    return res;
}

store tree[200100];
void buildTree(ll* arr, int v, int start, int end)
{
    if(start == end)
    {
        store x;
        x.maxsubsum = arr[start];
        x.maxsuffsum = arr[start];
        x.totalsum = arr[start];
        x.maxpresum = arr[start];
        tree[v] = x;
    }
    else
    {
        int mid = start + (end-start)/2;
        buildTree(arr, 2*v, start, mid);
        buildTree(arr, 2*v+1, mid+1, end);
        store x = merge(tree[2*v], tree[2*v+1]);
        tree[v] = x;
    }
}

store query(ll*arr, int v, int start, int end, int l, int r)
{
    if(l <= start && r >= end)
    {
        return tree[v];
    }

    if(l > r)
    {
        store x;
        return x;
    }

    int mid = start + (end-start)/2;
    store left = query(arr, 2*v, start, mid, l, min(r, mid));
    store right = query(arr, 2*v+1, mid+1, end, max(mid+1, l), r);
    return merge(left, right);
}

int main()
{
    fast;
    int n;
    cin >> n;
    ll * arr = new ll[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    buildTree(arr, 1, 0, n-1);

    int m;
    cin >> m;
    while(m--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        store ans = query(arr, 1, 0, n-1, l, r);
        cout << ans.maxsubsum << endl;
    }
    
    return 0;   
}