#include <bits/stdc++.h>
#define mod (int) 1e6
using namespace std;

main()
{
	int test; 
	cin >> test;
	while (test--)
	{
		long long n;
		long long ans = 0;
		cin >> n;
		long long a = 0, b = 0;
		while (1)
		{
			a = b+1;
			b = n / (n / a);
			ans += (((b-a+1)*(n/a)) % mod );
			if (b == n) break;
		}
		cout << ans % mod << endl;
	}
}
