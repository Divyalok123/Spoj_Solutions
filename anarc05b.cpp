#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, int> oneind;
unordered_map<int, int> twoind;

int arr1[10005], arr2[10005];
int n1, n2;
int memo1[10005], memo2[10005];

//memoization
// int solve(int i, int *firstarr, int size1, int *secondarr, int size2, int k)
// {
//     if (i > size1)
//         return 0;
//     if(k == 0 && memo1[i] != -1) return memo1[i];
//     if(k == 1 && memo2[i] != -1) return memo2[i];

//     if (k == 0 && twoind[firstarr[i]] > 0)
//     {
//         memo1[i] = firstarr[i] + max(solve(i + 1, firstarr, size1, secondarr, size2, k),
//                    solve(twoind[firstarr[i]]+1, secondarr, size2, firstarr, size1, 1-k));
//         return memo1[i];
//     }

//     if(k == 1 && oneind[firstarr[i]] > 0)
//     {
//         memo2[i] = firstarr[i] + max(solve(i + 1, firstarr, size1, secondarr, size2, k),
//                    solve(oneind[firstarr[i]]+1, secondarr, size2, firstarr, size1, 1-k));
//         return memo2[i];
//     }
//     if(k == 0) { memo1[i] = firstarr[i] + solve(i + 1, firstarr, size1, secondarr, size2, k); return memo1[i];}
//     if(k == 1) { memo2[i] = firstarr[i] + solve(i + 1, firstarr, size1, secondarr, size2, k); return memo2[i];}
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n1;
    while (n1 != 0)
    {
        int firstsum = 0;
        for (int i = 1; i <= n1; i++)
        {
            cin >> arr1[i];
            oneind[arr1[i]] = i;
            firstsum += arr1[i];
            // for greedy
            if(i == 1) memo1[i] = arr1[i];
            else memo1[i] = arr1[i] + memo1[i-1];
        }

        int secondsum = 0;
        cin >> n2;
        for (int i = 1; i <= n2; i++)
        {
            cin >> arr2[i];
            twoind[arr2[i]] = i;
            secondsum += arr2[i];
            //for greedy
            if(i == 1) memo2[i] = arr2[i];
            else memo2[i] = arr2[i] + memo2[i-1];
        }

        if (n2 == 0)
        {
            cout << firstsum << endl;
            continue;
        }

        // memset(memo1, -1, sizeof(memo1));
        // memset(memo2, -1, sizeof(memo2));
        // int ans = max(solve(1, arr1, n1, arr2, n2, 0), solve(1, arr2, n2, arr1, n1, 1));
        // cout << ans << endl;

        //greedy
        int sum = 0;
        int pointer1 = -1;
        int pointer2 = -1;
        for(int i = 1; i <= n1; i++)
        {
            if(i == n1)
            {
                if(pointer1 == -1)
                {
                    sum = memo1[i];
                }
                else
                {
                    sum += max(memo1[i] - memo1[pointer1], memo2[n2] - memo2[pointer2]);
                }
            }

            else if(twoind[arr1[i]])
            {
                if(pointer1 == -1)
                {
                    if(memo2[twoind[arr1[i]]] > memo1[i])
                    {
                        sum += memo2[twoind[arr1[i]]];
                        pointer1 = i;
                        pointer2 = twoind[arr1[i]];
                    }
                    else
                    {
                        sum += memo1[i];
                        pointer1 = i;
                        pointer2 = twoind[arr1[i]];
                    }
                }
                else
                {
                    if(memo2[twoind[arr1[i]]] - memo2[pointer2] > memo1[i] - memo1[pointer1])
                    {   
                        sum += memo2[twoind[arr1[i]]] - memo2[pointer2];
                        pointer1 = i;
                        pointer2 = twoind[arr1[i]];
                    }
                    else
                    {
                        sum += memo1[i] - memo1[pointer1];
                        pointer1 = i;
                        pointer2 = twoind[arr1[i]];
                    }
                }
            }
        }

        int sum2 = 0;
        pointer1 = -1;
        pointer2 = -1;
        for(int i = 1; i <= n2; i++)
        {
            if(i == n2)
            {
                if(pointer1 == -1)
                {
                    sum2 = memo2[i];
                }
                else
                {
                    sum2 += max(memo2[i] - memo2[pointer1], memo1[n1] - memo1[pointer2]);
                }
            }
            else if(oneind[arr2[i]])
            {
                if(pointer1 == -1)
                {
                    if(memo1[oneind[arr2[i]]] > memo2[i])
                    {
                        sum2 += memo1[oneind[arr2[i]]];
                        pointer1 = i;
                        pointer2 = oneind[arr2[i]];
                    }
                    else
                    {
                        sum2 += memo2[i];
                        pointer1 = i;
                        pointer2 = oneind[arr2[i]];
                    }   
                }
                else
                {
                    if(memo1[oneind[arr2[i]]] - memo1[pointer2] > memo2[i] - memo2[pointer1])
                    {   
                        sum2 += memo1[oneind[arr2[i]]] - memo1[pointer2];
                        pointer1 = i;
                        pointer2 = oneind[arr2[i]];
                    }
                    else
                    {
                        sum2 += memo2[i] - memo2[pointer1];
                        pointer1 = i;
                        pointer2 = oneind[arr2[i]];
                    }
                }
            }  
        }

        cout << max(sum, sum2) << endl;

        oneind.clear();
        twoind.clear();
        cin >> n1;
    }

    return 0;
}
