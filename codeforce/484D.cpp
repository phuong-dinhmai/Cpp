#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18, N = 1e6+7;
int n, a[N];
ll f[N][2][2];

main(){
	//freopen("in.inp","r",stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 2; j++) 
			for (int k = 0; k < 2; k++) f[i][j][k] = -inf;
	f[0][0][0] = f[0][1][0] = 0LL;
	
	for (int i = 0; i < n; i++)
		for (int sign = 0; sign < 2; sign++)
			for (int last = 0; last < 2; last++)
			{
				ll res = f[i][sign][last];
				f[i+1][sign][last] = max(res, f[i+1][sign][last]);
				if (last == 0)
				{
					f[i+1][1][1] = max(f[i+1][1][1], res + 1LL*a[i+1]);
					f[i+1][0][1] = max(f[i+1][0][1], res - 1LL*a[i+1]);
				}
				else
				{
					if (sign == 0) f[i+1][1][0] = max(f[i+1][1][0], res + 1LL*a[i+1]); 
					else f[i+1][0][0] = max(f[i+1][0][0], res - 1LL*a[i+1]);
				}
			}
			
	printf("%I64d\n", max(f[n][1][0], f[n][0][0]));
}
