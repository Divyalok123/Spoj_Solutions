// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <cmath>
// #include <cstring>
// #include <unordered_map>
// #include <iomanip>
// #include <stdexcept>
// #include <stack>
// #include <queue>
// using namespace std;
// #define fast                          \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(0);                       \
//     cout.tie(0)
// #define ll long long
// #define uint unsigned int
// #define ull unsigned long long
// #define endl "\n"
// #define setbits(x) __builtin_popcountll(x)
// typedef priority_queue<int> maxheap;
// typedef priority_queue<int, vector<int>, greater<int>> minheap;

// uint gcd(uint a, uint b)
// {
//     if (b == 0)
//         return a;
//     else
//         return gcd(b, a % b);
// }

// int main()
// {
//     fast;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         uint n, m, a, d;
//         cin >> n >> m >> a >> d;
//         uint arr[5];
//         for (int i = 0; i < 5; i++)
//         {
//             arr[i] = a + i * d;
//         }

//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = i + 1; j < 5; j++)
//             {
//                 uint thisgcd = gcd(arr[i], arr[j]);
//                 if(thisgcd != arr[i] && arr[i]%thisgcd == 0 && i != 0) arr[i] /= thisgcd;
//                 if(thisgcd != arr[j] && arr[j]%thisgcd == 0) arr[j] /= thisgcd;
//             }
//         }

//         uint sum = 0;
//         for(int i = 0; i < 5; i++)
//         {
//             sum += ((m/arr[i]) - (n-1)/arr[i]);
//         }

//         cout << sum << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <limits>
#include <numeric>

/* !! Not Solved!! */

using namespace std;
typedef unsigned long long ull;

ull lcm1(ull a, ull b);
ull gcd(ull x, ull y);
int main()
{
    int t;
    cin >> t;
    for (; t > 0; t--)
    {
        ull d, d1, d2, val, s[5], n, m, a;
        int k = 5, tot, nb;
        cin >> n >> m >> a >> d;
        for (int i = 0; i < 5; i++)
        {
            s[i] = a + i * d;
        }
        tot = (1 << k);
        d1 = (--n), d2 = m;
        for (int i = 1; i < tot; i++)
        {
            val = 1, nb = 0;
            for (int j = 0; j < k; j++)
            {
                if (i & (1 << j))
                {
                    nb++;
                    val = lcm1(val, s[j]);
                }
            }
            if (nb & 1)
            {
                n -= d1 / val;
                m -= d2 / val;
            }
            else
            {
                n += d1 / val;
                m += d2 / val;
            }
        }
        cout << m - n << endl;
    }
    return 0;
}
ull lcm1(ull a, ull b)
{

    return (a * b / (gcd(a, b)));
}
ull gcd(ull x, ull y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}