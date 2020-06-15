#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;
// int freq[1000005], ans[2000005], arr[30005];
int bit[30005], ans[2000005];
unordered_map<int, int> occ;
int q, n, block;

class quer
{
public:
    int l;
    int r;
    int ind;
    quer() {}
    quer(int l, int r, int ind)
    {
        this->l = l;
        this->r = r;
        this->ind = ind;
    }
};

vector<quer> qarr;

//using BITree (not giving right output)
//what to do? process input and query at the same time
//mistake in the below is code is that I'm making all updates at the same time.. 
//if query.r is equal to the last index you have updated.. find the sum till that 
//reference: 
/*
int posOfLast[2e6] = {-1, -1 ....};
int a[n];
int cnt[n];
// input 

for (int i = 0; i < n; ++i) {
	if (posOfLast[a[i]] != -1)
		cnt[posOfLast[a[i]]]--;
	posOfLast[a[i]] = i;
	cnt[posOfLast[a[i]]]++;

	for (all q in Queries where q.R == i) {
		sum = 0;

		// { this part can be done in O(Log(n))
		// using Range Sum Query structure, or fenvick tree, or segment tree
		for (int j = q.L; j <= q.R; j++)
			sum += cnt[j];
		// }

		ans[q.Id] = sum;
	}
}
*/

void update(int i, int v)
{
    for(; i <= n; i += i&-i)
        bit[i] += v;
}

int query(int i)
{
    int sum = 0;
    for(; i > 0; i -= i&-i) sum += bit[i];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(bit, 0, sizeof(bit));
    cin >> n;
    int val;
    for(int i = 1; i <= n; i++)
    {
        cin >> val;
        if(occ[val] == 0) { update(i, 1); occ[val] = i;}
        else { update(i, 1); update(occ[val], -1);  occ[val] = i;}
    }

    cin >> q;
    int x, y;
    for(int i = 1; i <= q; i++)
    {   
        cin >> x >> y;
        qarr.push_back(quer(x, y, i));
    }

    sort(qarr.begin(), qarr.end(), [&](quer& a, quer& b) {
        return (a.r < b.r) || ((a.r == b.r) && (a.l < b.l));
    });

    for(int i = 1; i <= q; i++)
    {
        ans[qarr[i].ind] = query(qarr[i].r);
    }

    for(int i = 1; i <= q; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}


//Using MO's algo
/*

void solve() {
    int currl = qarr[0].l;
    int currr = currl;
    freq[arr[currl]]++;
    int count = 1;
    for(auto query: qarr)
    {
        while(currl < query.l)
        {
            freq[arr[currl]]--;
            if(freq[arr[currl]] == 0)
                count--;
            currl++;
        }

        while(currl > query.l)
        {
            currl--;
            freq[arr[currl]]++;
            if(freq[arr[currl]] == 1) 
                count++;
        }

        while(currr < query.r)
        {
            currr++;
            freq[arr[currr]]++;
            if(freq[arr[currr]] == 1)
                count++;
        }

        while(currr > query.r)
        {
            freq[arr[currr]]--;
            if(freq[arr[currr]] == 0)
                count--;
            currr--;
        }

        ans[query.ind] = count;
    }

    for(int i = 1; i <= q; i++)
    {
        cout << ans[i] << endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    block = (int)sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    cin >> q;

    int x, y;
    for (int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        qarr.push_back(quer(x, y, i));
    }

    sort(qarr.begin(), qarr.end(), [&](quer &a, quer &b) {
        if(a.l/block != b.l/block) return a.l < b.l; 
        else return a.r < b.r; 
    });

    solve();

    return 0;
}
*/