#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 105;
const int mod = 1e9+7;

int n;
ll f[maxN][maxN];
ll C[maxN][maxN];
int a[10];
ll res = 0;

void init(int n)
{
	for (int i = 0; i <= n; i++) C[0][i] = C[i][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
		{
			C[i][j] = (C[i-1][j] + (j ?C[i-1][j-1]: 0)) % mod;
		}
		
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	for (int i = 0; i < 10; i++) cin >> a[i];
	init(n);
	for (int i = 0; i <= n; i++) f[9][i] = (i >= a[9]? 1: 0);
	for (int i = 8; i > 0; i--)
		for (int j = 0; j <= n; j++)
			for (int x = a[i]; x <= j; x++)
			{
				if (j < x) continue;
				ll ans;
				if (i) ans = f[i+1][j-x] * C[j][x] % mod;
				f[i][j] += ans;
				f[i][j] %= mod;
			}
	for (int i = 0; i <= n; i++)
		for (int j = a[0]; j < i; j++) res = (res + f[1][i-j] * C[i-1][j]) % mod;
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++) cout << f[i][j] << " ";
		cout << endl;
	}*/
	cout << res << endl;
}
