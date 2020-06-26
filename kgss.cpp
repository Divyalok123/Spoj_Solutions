#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
#define ll long long
#define MIN -1e9
ll arr[100005];

class large {
public:
    ll largest;
    ll slargest;

    large() {}

    large(int a, int b) {
        this->largest = a;
        this->slargest = b;
    }
};

large seg[400005];

large compare(large a, large b)
{
    large ans;
    int a_large = a.largest, b_large = b.largest, a_slarge = a.slargest, b_slarge = b.slargest;
    
    if(a_large > b_large)
    {
        ans.largest = a_large;
        ans.slargest = max(a_slarge, b_large);
    }
    else
    {
        ans.largest = b_large;
        ans.slargest = max(b_slarge, a_large);
    }
    return ans;
}

void build(int v, int l, int r)
{
    if(l == r)
    {
        large temp(arr[l], MIN);
        seg[v] = temp;
        return;
    }

    int m = l + (r-l)/2;
    build(2*v+1, l, m);
    build(2*v+2, m+1, r);
    seg[v] = compare(seg[2*v+1], seg[2*v+2]);       
}

void update(int v, int l, int r, int pos, ll val)
{
    if(l == r)
    {
        arr[pos] = val;
        large temp(val, MIN);
        seg[v] = temp;
        return;
    }
    int m = l + (r-l)/2;
    if(pos <= m)
    {
        update(2*v+1, l, m, pos, val);
    }
    else
    {
        update(2*v+2, m+1, r, pos, val);
    }
    seg[v] = compare(seg[2*v+1], seg[2*v+2]);
}

large query(int v, int l, int r, int ql, int qr)
{
    if(ql > qr)
    {
        large temp(MIN, MIN);
        return temp;
    }
    
    if(l == ql && r == qr)
    {
        return seg[v];
    }
    int m = l + (r-l)/2;
    large ans1 = query(2*v+1, l, m, ql, min(qr, m));
    large ans2 = query(2*v+2, m+1, r, max(ql, m+1), qr);
    return compare(ans1, ans2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, 0, n-1);
    int q;
    cin >> q;
    while(q--)
    {
        char a;
        cin >> a;
        if(a == 'Q')
        {
            int s, e;
            cin >> s >> e;
            large ans = query(0, 0, n-1, s-1, e-1);
            cout << ans.largest + ans.slargest << endl;
        }
        else if(a == 'U')
        {
            int pos; ll value;
            cin >> pos >> value;
            update(0, 0, n-1, pos-1, value);
        }
    }

    return 0;
}