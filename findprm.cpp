#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define endl '\n'
// #define range 5000003

bool primes[10000003];
int counts[10000003];

void getprimes() {
    memset(primes, true, sizeof(primes));
    for(int i = 2; i < sqrt(10000003)+1; i++) {
        if(primes[i])
        for(int j = i*i; j < 10000003; j += i) {
            {
                primes[j] = false;
            }
        }
    }

    for(int i = 2; i < 10000003; i++) {
        if(primes[i]) {
            counts[i] = counts[i-1] + 1;
        }
        else 
            counts[i] = counts[i-1];
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    getprimes();

    while(t--) {
        int n;
        cin >> n;
        cout << counts[n]-counts[n/2] << endl;
    }

    return 0;
}