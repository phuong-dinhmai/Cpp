#include <bits/stdc++.h>
#define ll long long
using namespace std;

int money[11] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};

ll cnt[6005][11];

ll ans(int n, int k)
{
	if (n == 0) return 1;
	if (n < 0) return 0;
	if (cnt[n][k] != -1) return cnt[n][k];
	ll res = 0;
	for (int i = k; i < 11; i++)
		res += ans(n - money[i], i);
	return cnt[n][k] = res; 
}

main(){
	float m;
	int n;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	for (int i = 0; i <= 6000; i++) 
		for (int j = 0; j < 11; j++) cnt[i][j] = -1;
	while (scanf("%f", &m) && (m != 0))
	{
		int	n = m * 20;
		printf("%6.2f%17.lld\n", m, ans(n, 0));
	}
}

