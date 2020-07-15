#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void count_sort(vector<int> &p, vector<int> &c)
{
    int n = p.size();
    vector<int> count(n);
    vector<int> pos(n);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
        count[c[i]]++;

    pos[0] = 0;
    for (int i = 1; i < n; i++)
    {
        pos[i] = pos[i - 1] + count[i - 1];
    }

    for (auto x : p)
    {
        int ind = c[x];
        ans[pos[ind]] = x;
        pos[ind]++;
    }
    p = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        s += '$';

        int n = s.size();
        vector<int> p(n), c(n);

        {
            vector<pair<char, int>> v(n);

            for (int i = 0; i < n; i++)
                v[i] = {s[i], i};

            sort(v.begin(), v.end());

            for (int i = 0; i < n; i++)
                p[i] = v[i].second;
            c[p[0]] = 0;
            for (int i = 1; i < n; i++)
            {
                if (v[i].first == v[i - 1].first)
                    c[p[i]] = c[p[i - 1]];
                else
                    c[p[i]] = c[p[i - 1]] + 1;
            }
        }

        int k = 0;
        while ((1 << k) < n)
        {
            for (int i = 0; i < n; i++)
                p[i] = (p[i] - (1 << k) + n) % n;

            count_sort(p, c);

            vector<int> new_c(n);
            new_c[p[0]] = 0;
            for (int i = 1; i < n; i++)
            {
                pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << k)) % n]};
                pair<int, int> pre = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
                if (cur == pre)
                    new_c[p[i]] = new_c[p[i - 1]];
                else
                    new_c[p[i]] = new_c[p[i - 1]] + 1;
            }
            c = new_c;
            k++;
        }

        vector<int> lcp(n);

        k = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int ind = c[i];
            int pi = p[ind - 1];

            while (s[i + k] == s[pi + k])
            {
                k++;
            }

            lcp[ind] = k;
            k = max(k - 1, 0);
        }

        int count = 0;
        for (int i = 1; i < n; i++)
        {
            count += (n - 1 - lcp[i] - p[i]);
        }

        cout << count << endl;
    }
    return 0;
}