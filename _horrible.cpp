#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define ll long long

//Remaining task: Have to do it using segment tree lazy propagation

ll b1[100005];
ll b2[100005];
ll arr[100005];

ll query(ll* fen, int n, int r)
{
    ll res = 0;
    for(++r; r > 0; r -= r&-r)
        res += fen[r];
    return res;
}

void update(ll* fenwick, int n, int i, ll val)
{
    // cout << "Updating ..." << endl;
    for(++i; i <= n; i += i & -i)
        fenwick[i] += val;

    // for(int i = 1; i <= n; i++)
    //     cout << fenwick[i] << " ";
    // cout << endl;

}


void range_add(int n, int l, int r, ll x) {
    update(b1, n, l, x);
    update(b1, n, r+1, -x);
    update(b2, n, l, x*(l-1));
    update(b2, n, r+1, -x*r);
}

//below two just constitute like: (query(b1, n, r)*r - query(b1, n, l-1)*l-1) - (query(b2, n, r) - query(b2, n, l-1)); 

ll prefix_sum(int n, int idx)
{
    return query(b1, n, idx)*idx - query(b2, n, idx);
}

ll range_sum(int n, int l, int r)
{
    return prefix_sum(n, r) - prefix_sum(n, l-1);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        memset(b1, 0, sizeof(b1));
        memset(b2, 0, sizeof(b2));

        int n, c;
        cin >> n >> c;
        while(c--)
        {
            int a, p, q;
            ll v;
            cin >> a;
            if(a == 0)
            {
                cin >> p >> q >> v;
                range_add(n, --p, --q, v);
            }
            else if(a == 1)
            {
                cin >> p >> q;
                cout << range_sum(n, --p, --q) << endl;
            }
        }
    }
    return 0;
}