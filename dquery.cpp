#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int freq[2000005], ans[2000005], arr[30005];
int q, n, block;

//Using MO's algo
/*
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