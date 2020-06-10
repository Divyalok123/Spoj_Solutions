#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define ll long long
#define endl '\n'



//using KMP
void KMP(int* lps, string needle, string haystack, int nsize, int hsize)
{
    bool flag = false;
    int i = 0;
    int j = 0;

    while(i < hsize)
    {
        if(needle[j] == haystack[i])
        {
            i++;
            j++;
            if(j == nsize)
            {
                flag = true;
                cout << i - j << endl;
                j = lps[j-1];
            }
        }
        else
        {
            // if(i < hsize)
            // {
                if(j > 0)
                {
                    j = lps[j-1];
                }
                else
                {
                    i++;
                }
            // }
        }
    }

    if(flag == false)
    {
        cout << endl << endl;
    }

}

// void solve(string needle, string haystack)
// {
//     int needlesize = needle.length();
//     int haystacksize = haystack.length();

//     int* lps = new int[needlesize];
//     lps[0] = 0;
//     int len = 0;
//     int j = 1;

//     while(j < needlesize)
//     {
//         if(needle[j] == needle[len])
//         {
//             len++;
//             lps[j] = len;
//             j++;
//         }
//         else
//         {
//             if(len > 0)
//             {
//                 len = lps[len-1];
//             }
//             else
//             {
//                 lps[j] = 0;
//                 j++;
//             }
//         }
//     }
//     // cout << "LPS: ";
//     // for(int i = 0; i < needlesize; i++)
//     // {
//     //     cout << lps[i] << " ";
//     // }
//     // cout << endl;

//     KMP(lps, needle, haystack, needlesize, haystacksize);
//     delete[] lps;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    string needle, haystack;
    int i = 1;
    while(cin >> n)
    {
        if(i != 1) cout << endl;
        cin >> needle >> haystack;
        // solve(needle, haystack);

        // cout << endl;
    }
    return 0;
}

