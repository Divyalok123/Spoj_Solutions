#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1e7
int arr1[1004], arr2[1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n1, n2;
        cin >> n1;
        for(int i = 0; i < n1; i++)
            cin >> arr1[i];

        cin >> n2;
        for(int i = 0; i < n2; i++)
            cin >> arr2[i];
        
        sort(arr1, arr1 + n1);
        sort(arr2, arr2 + n2);

        int minim = MAX;
        int i = n1-1, j = n2-1;
        while(i >= 0 && j >= 0)
        {
            if(arr1[i] > arr2[j])
            {
                minim = min(minim, abs(arr1[i]-arr2[j]));
                i--; 
            }

            else if(arr2[j] > arr1[i])
            {
                minim = min(minim, abs(arr2[j]-arr1[i]));
                j--;
            }

            else
            {
                minim = 0;
                break;
            }
            
        }

        cout << minim << endl;
    }
    return 0;
}