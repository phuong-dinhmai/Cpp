#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e3+7;
const int mod = 1e9+7;

ll sum[N], f[N][N], ans = 0LL;
char s[N];
int n, k;

void process()
{
	f[0][0] = sum[0] = 1LL;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++)
		{
			ll res = 1LL * sum[j] * (s[i] - 'a') % mod;
			for (int l = 0; l < i; l++)
			{
				int x = j - (l + 1)*(n - i + 1);
				if (x < 0) break;
				res = (res + 1LL * f[i-l-1][x] * ('z' - s[i]) % mod) % mod;
			}
			f[i][j] = res;
			sum[j] = (sum[j] + res) % mod;
		}
}

main(){
	//freopen("in.inp","r",stdin);
	scanf("%d%d\n", &n, &k);
	scanf("%s", s+1);
	
	process();
	
	for (int i = 0; i <= n; i++) ans = (ans + f[i][k]) % mod;
	printf("%I64d\n", ans);
}
