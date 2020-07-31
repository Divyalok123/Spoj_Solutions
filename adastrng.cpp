#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

void countsort(vector<int>& p, vector<int>& c) {
    int n = p.size();
    vector<int> pos(n), count(n), new_p(n);

    for(int i = 0; i < n; i++)
        count[c[i]]++;

    pos[0] = 0;
    for(int i = 1; i < n; i++) 
        pos[i] = count[i-1] + pos[i-1];

    for(auto a: p) {
        int ind = c[a];
        new_p[pos[ind]] = a;
        pos[ind]++;
    }

    p = new_p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    s += '$';
    int n = s.length();

    vector<int> p(n), c(n);
    {
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++)
            v[i] = {s[i], i};

        sort(v.begin(), v.end());

        for(int i = 0; i < n; i++)
            p[i] = v[i].second;

        c[p[0]] = 0;
        for(int i = 1; i < n; i++)
        {
            if(v[i].first == v[i-1].first)
                c[p[i]] = c[p[i-1]];
            else
                c[p[i]] = c[p[i-1]] + 1;
        }
    }

    int k = 0;
    while((1 << k) < n) {
        for(int i = 0; i < n; i++) 
            p[i] = (p[i]-(1<<k)+n)%n;

        countsort(p, c);

        vector<int> new_c(n);
        new_c[p[0]] = 0;
        for(int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i]+(1<<k))%n]};
            pair<int, int> pre = {c[p[i-1]], c[(p[i-1] + (1<<k))%n]};

            if(cur == pre)
                new_c[p[i]] = new_c[p[i-1]];
            else
                new_c[p[i]] = new_c[p[i-1]]+1;
        }
        c = new_c;
        k++;
    }

    vector<int> lcp(n);
    k = 0;
    for(int i = 0; i < n-1; i++) {
        int ind = c[i];
        int pind = p[ind-1];
        while(s[i+k] == s[pind+k])
            k++;
        lcp[ind] = k;
        k = max(k-1, 0);
    }

    using ll = long long;
    ll ans = 0;
    ll sum = 0;
    for(int a: lcp)
        sum += (ll)a;
    n--;
    (ll)n;

    n = ((n*n) + n)/2;
    ans = n-sum;
    cout << "Number of distinct substrings: " << ans << endl;

    return 0;
}