#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
#define MIN -999999
int n, arr[50005];

class store
{
public:
    int prefix;
    int suffix;
    int total;
    int sub;

    store() { prefix = suffix = total = sub = MIN; }
    store(int p, int s, int t, int sub)
    {
        this->prefix = p;
        this->suffix = s;
        this->total = t;
        this->sub = sub;
    }
};

store merge(store a, store b)
{
    store ans;
    ans.prefix = max(a.prefix, a.total + b.prefix);
    ans.suffix = max(b.suffix, b.total + a.suffix);
    ans.total = a.total + b.total;
    ans.sub = max(a.sub, max(b.sub, a.suffix + b.prefix));
    return ans;
}

store seg[200005];

void build(int v, int l, int r)
{
    if (l == r)
    {
        store s(arr[l], arr[l], arr[l], arr[l]);
        seg[v] = s;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
}

void update(int v, int l, int r, int pos, int val)
{
    if (l == r)
    {
        store s(val, val, val, val);
        seg[v] = s;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2 * v, l, mid, pos, val);
    else
        update(2 * v + 1, mid+1, r, pos, val);

    seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
}

store query(int v, int l, int r, int ql, int qr)
{
    if(ql >  qr)
    {
        store s;
        return s;
    }
    if (ql == l && qr == r)
        return seg[v];

    int mid = (l + r) / 2;
    store left = query(2 * v, l, mid, ql, min(qr, mid));
    store right = query(2 * v + 1, mid + 1, r, max(ql, mid+1), qr);
    return merge(left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);
    int m;
    cin >> m;
    while (m--)
    {
        int a, x, y;
        cin >> a >> x >> y;

        if (a == 1)
        {
            cout << query(1, 1, n, x, y).sub << endl;
        }
        else
        {
            update(1, 1, n, x, y);
        }
    }
    return 0;
}