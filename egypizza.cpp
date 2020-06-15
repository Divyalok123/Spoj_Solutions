#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int c1 = 0,c2 = 0,c3 = 0;
    for(int i  = 0; i < n; i++)
    {
        int x, y;
        char a;
        cin >> x >> a >> y;

        float f = (float)x/(float)y;
        if(f == 0.5) c2++;
        else if(f == 0.25) c1++;
        else if(f == 0.75) c3++;
    }
    int count = 0;
    count += c3;

    c1 = max(0, c1-c3);
    count += c2/2;
    c2 %= 2;

    count += c1/4;
    c1 %= 4;

    if(c2 == 1)
    {
        if(c1 <= 2)
            count += 1;
        else
            count += 2;
    }
    else if(c1 >= 1)
    {
        count += 1;
    }

    cout << count+1 << endl;
    return 0;
}

// unordered_map<float, int> mp;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int n;
//     cin >> n;
//     vector<float> v;
//     int count = 1;
//     for (int i = 0; i < n; i++)
//     {
//         int a, b;
//         char x;
//         cin >> a >> x >> b;
//         float f = (float)a / (float)b;
//         v.push_back(f);
//         mp[f]++;
//     }

//     int c1 = mp[0.25];
//     int c2 = mp[0.5];
//     int c3 = mp[0.75];

//     if (c1 > c3 && c3 != 0)
//     {
//         c1 -= c3;
//         count += c3;
//         c3 = 0;
//     }

//     else if (c3 > c1 && c1 != 0)
//     {
//         c3 -= c1;
//         count += c1;
//         c1 = 0;
//     }

//     if (c3 > 0)
//     {
//         count += c3;
//         count += (int)ceil((float)c2 / 2);
//     }

//     else if (c1 > 0)
//     {
//         if (c1 > 2 * c2)
//         {
//             c1 -= 2 * c2;

//             count += c2;
//             c2 = 0;

//             if (c1 > 0)
//             {
//                 count += (int)ceil((float)c1 / 4);
//             }
//         }
//         else
//         {
//             c2 -= c1 / 2;
//             count += c1 / 2;
//             c1 = c1 % 2;

//             if (c1 > 0)
//                 c2++;

//             if (c2 > 0)
//                 count += (int)ceil((float)c2 / 2);
//         }
//     }

//     else
//     {
//         count += (int)ceil((float)c2 / 2);
//     }

//     cout << count << endl;

//     return 0;
// }