#include <bits/stdc++.h>
#define maxN 2000
using namespace std;

long long  tree[maxN][maxN];

void update(int x, int ty, int val, int n)
{
	while(x <= n)
	{
		int y = ty;
		while(y <= n)
		{
			tree[x][y] += val;
			y += (y & (-y));
		}
		x += (x & (-x));
	}
}

long long query(int x, int ty)
{
	long long ans = 0;
	while(x)
	{
		int y = ty;
		while (y)
		{
			ans += tree[x][y];
			y -= (y & (-y));
		}
		x -= (x & (-x));
	}
	return ans;
}

main(){
	//freopen("in.inp","r",stdin);
	int test;
	int n;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		getchar();
		for (int i = 0; i < maxN; i++)
			for (int j = 0; j < maxN; j++) tree[i][j] = 0;
		char s[10];
		while (1)
		{
			scanf("%s", &s);
			if (s[2] == 'D') break;
			if (s[1] == 'E')
			{
				int x, y, val;
				scanf("%d %d %d", &x, &y, &val);
				int pre_val = query(x+1, y+1) + query(x,y) - query(x, y+1) - query(x+1, y);
				update(x+1, y+1, val - pre_val, n+9);
 			}
 			if (s[1] == 'U')
 			{
 				int x1, x2, y1, y2;
 				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
 				long long  ans = query(x2 + 1, y2 + 1) + query(x1, y1) - query(x2 + 1, y1) - query(x1, y2 + 1);
 				printf("%lld\n", ans);
 			}
		}
		printf("\n");
	}
}
