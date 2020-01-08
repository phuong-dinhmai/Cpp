#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
#define vi vector <int>
#define maxN 105
using namespace std;

int check[maxN][maxN];
int ok[maxN];
int n;
vi ans;

void init()
{
	for (int i = 0; i < maxN; i++) 
	{
		ok[i] = WHITE;
		for (int j = 0; j < maxN; j++) check[i][j] = WHITE;
	}
	ans.clear();
}

void topo(int k)
{
	for (int i = 1; i <=n; i++)
		if (ok[i] == WHITE)
			{
				if (check[i][k] == BLACK) return;
				if (check[k][i] == BLACK) 
				{
					ok[i] = BLACK;
					topo(i);
					ok[i] = WHITE;
				} 
			}
	ans.push_back(k);
}

main(){
	bool blank = false;
	long long  m;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	while (cin >> n >> m)
	{
		init();
		
		if (n == 0 && m == 0) break;
		for (long long  i = 0; i < m; i++) 
		{
			int x, y;
			cin >> x >> y;
			check[x][y] = BLACK;
		}
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					if (check[j][i] == BLACK && check[i][k] == BLACK) check[j][k] = BLACK;
					
		for (int i = 1; i <= n; i++) 
		{
			ok[i] = BLACK;
			topo(i);
			ok[i] = WHITE;
		}
		
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) 
		{
			if (i != 0) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
}
