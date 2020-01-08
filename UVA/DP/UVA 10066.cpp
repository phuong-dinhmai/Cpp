#include <bits/stdc++.h>
using namespace std;

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	int n, m;
	int a[101];
	int b[101];
	int f[101][101];
	int test = 0;
	while (scanf ("%d%d", &n, &m) && (n + m))
	{
		test++;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int j = 1; j <= m; j++) scanf("%d", &b[j]);
		for (int i = 0; i <= n; i++) f[i][0] = 0;
		for (int j = 0; j <= m; j++) f[0][j] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
				else f[i][j] = max(f[i-1][j], f[i][j-1]);
		printf("Twin Towers #%d\n", test);
		printf("Number of Tiles : %d\n\n", f[n][m]);
	}
}
