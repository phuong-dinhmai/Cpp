#include <bits/stdc++.h>
#define maxN 2000
using namespace std;

int tree[maxN][maxN];

void update(int x, int y, int val, int n)
{
	while (x <= n)
	{
		int ty = y;
		while(ty <= n)
		{
			tree[x][ty] += val;
			ty += (ty & (-ty));
		}
		x += (x & (-x));
	}
}

int query(int x, int y)
{
	int ans = 0;
	while(x)
	{
		int ty = y;
		while (ty)
		{
			ans += tree[x][ty];
			ty -= (ty & (-ty));
		}
		x -= (x & (-x));
	}
	return ans;
}

main(){
	int n;
	//freopen("in.inp","r",stdin);
	while (1)
	{
		int type;
		scanf("%d", &type);
		switch(type)
		{
			case 0: 
			{
				scanf("%d", &n);
				for (int i = 0; i < maxN; i++)
					for (int j = 0; j < maxN; j++) tree[i][j] = 0;
				break;
			}
			case 1:
			{
				int x, y, val;
				scanf("%d %d %d", &x, &y, &val);
				update(x+1, y+1, val, n+9); 
				break;
			}
			case 2:
			{
				int x1, x2, y1, y2;
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				int ans = query(x2 + 1, y2 + 1) + query(x1, y1) - query(x1, y2 + 1) - query(x2 + 1, y1);
				printf("%d\n", ans);
				break;	
			}
			case 3: return 0;
		}
	} 
}
