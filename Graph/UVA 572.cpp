#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
using namespace std;

int n,m;
int check[100][100];
char a[100][100];


void dfs(int i, int j)
{
	if (i<0 || j<0 || i>=n || j>=m) return;
	if (a[i][j] == '*' || check[i][j] == BLACK) return;
	check[i][j] = BLACK;
	dfs(i,j+1);
	dfs(i,j-1);
	dfs(i+1,j);
	dfs(i-1,j);
	dfs(i+1,j+1);
	dfs(i+1,j-1);
	dfs(i-1,j+1);
	dfs(i-1,j-1);
}

main(){
	//freopen ("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) cin >> a[i][j];
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++) check[i][j] = WHITE;
		int ans = 0;
		
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++)
				if (a[i][j] == '@' && check[i][j] == WHITE)
				{
					ans++;
					dfs(i,j);
				}
		cout << ans << endl;
	}
}
