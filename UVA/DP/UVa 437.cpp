#include <bits/stdc++.h>
#define maxN 105
using namespace std;

struct type{
	int r, c, hi;
} block [maxN];
int f[maxN];
int n;
int test = 0;

int solve(int u)
{
	if (f[u] != -1) return f[u];
	int best = 0;
	for (int i = 0; i < n*3; i++)
	{
		if ((block[i].r < block[u].r && block[i].c < block[u].c ) || (block[i].c < block[u].r && block[i].r < block[u].c ))
		{
			best = max(best, solve(i));
		}
	}
	f[u] = best + block[u].hi;
	return f[u];
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	while (cin >> n && n)
	{
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			block[3*i].r = x; block[3*i].c = y; block[3*i].hi = z;
			block[3*i+1].r = y; block[3*i+1].c = z; block[3*i+1].hi = x;
			block[3*i+2].r = z; block[3*i+2].c = x; block[3*i+2].hi = y;
			f[3*i] = f[3*i+1] = f[3*i+2] = -1;
		}
		for (int i = 0; i < n*3; i++)
		{
			ans = max(ans, solve(i));
		}
		cout << "Case " << ++test << ": maximum height = " << ans << endl;
	}
}
