#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
#define maxN 100
using namespace std;

char a[maxN][maxN];
int check[maxN][maxN];
int n, ans;

void dfs(int i, int j)
{
	if (i<0 || j<0 || i>=n || j>=n) return;
	if (a[i][j] == '.' || check[i][j] == BLACK) return;
	check[i][j] = BLACK;
	dfs(i+1,j);
	dfs(i-1,j);
	dfs(i,j+1);
	dfs(i,j-1);
}

main(){
	int test;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	cin >> test;
	for (int k = 0; k < test; k++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) cin >> a[i][j];
		
		for (int i = 0; i < maxN; i++)
			for (int j = 0; j < maxN; j++) check[i][j] = WHITE;
		ans = 0;
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] == 'x' && check[i][j] == WHITE)
				{
					ans++;
					dfs(i,j);
				}
			}
		cout << "Case " << k+1 << ": " << ans << endl;
	}
}
