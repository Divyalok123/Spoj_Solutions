#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int gcd = __gcd(a, b);
        int output = 1;
        int val = 2;
        while (gcd > 1)
        {
            int count = 0;
            while (gcd % val == 0)
            {
                count++;
                gcd /= val;
            }
            output *= count + 1;
            val++;
        }
        printf("%d\n", output);
    }

    return 0;
}
