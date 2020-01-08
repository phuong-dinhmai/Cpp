#include <bits/stdc++.h>
#define mod (long long) (1e9+7)
using namespace std;

long long f[1001];
long long a[1001];
long long sum [1001];
long long th[1002][1002];

void comb()
{
	for (int i = 1; i < 1002; i++) 
	{
		th[0][i] = 1;
		th[i][i] = 1;
		th[1][i] = i;
	}
	th[0][0] = 0;
	for (long long i = 2; i < 1002; i++)
		for (long long j = 1; j < 1002; j++) th[i][j] = (th[i-1][j-1] + th[i][j-1]) % mod;
}

main()
{
	long long n;
	cin >> n;
	f[0] = 1;
	sum[0] = 0;
	for (long long i = 1; i <= n; i++) 
	{
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
		f[i] = 0;
	}
	comb();
	f[1] = 1;
	for (long long i = 2; i <= n; i++) 
	{
		f[i] = (f[i-1]*th[a[i] - 1][sum[i] - 1]) % mod;
	}
	cout << f[n] % mod << endl;
}
