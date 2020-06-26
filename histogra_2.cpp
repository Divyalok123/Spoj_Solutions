#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
#define ll long long

int n;
ll arr[100005];
int seg[400010];

// void update(int v, int s, int e, int pos, ll val)
// {
//     if(s == e)
//     {
//         seg[v] = val;
//         arr[pos] = val;
//         return;
//     }

//     int m = s + (e-s)/2;
//     if(pos <= m)
//         update(2*v+1, s, m, pos, val);
//     else
//         update(2*v+2, m+1, e, pos, val);
//     seg[v] = min(seg[2*v+1], seg[2*v+2]);
// }

void build(int v, int s, int e)
{
    if(s == e)
    {
        seg[v] = s;
        return;
    }
    int m = s + (e-s)/2;
    build(2*v+1, s, m);
    build(2*v+2, m+1, e);
    seg[v] = arr[seg[2*v+1]] > arr[seg[2*v+2]] ? seg[2*v+2] : seg[2*v+1];
}

int query(int v, int s, int e, int l, int r)
{
    if(l > r)
        return -1;
    
    if(s == l && r == e)
        return seg[v];

    int m = s + (e-s)/2;
    int val1 = query(2*v+1, s, m, l, min(r, m));
    int val2 = query(2*v+2, m+1, e, max(l, m+1), r);
    if(val1 == -1) return val2;
    if(val2 == -1) return val1;
    return arr[val1] > arr[val2] ? val2 : val1;
}

ll area(int i, int j)
{
    if(i > j)   
        return 0;

    int ind = query(0, 0, n-1, i, j);
    ll val1 = (j-i+1)*arr[ind];
    ll val2 = max(area(i, ind-1), area(ind+1, j));
    return max(val1, val2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    while(n)
    {
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        memset(seg, 0, sizeof(seg));

        build(0, 0, n-1);

        cout << area(0, n-1) << endl;

        cin >> n;
    }

    return 0;
}