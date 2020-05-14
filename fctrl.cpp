#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		
		long long ans = 0;
		
		for(int i = 5; n/i >= 1; i*=5)
		{
			ans += n/i;
		}
		
		cout << ans << "\n";
	}
	return 0;
}