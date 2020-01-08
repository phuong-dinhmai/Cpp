#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
using namespace std;

int n,m,ans = 0,mx;
char a[50][50],c;
int check[50][50];

void dfs(int i, int j)
{
	if (i<0 || j<0 || i>=n || j>=m ) return;
	if (a[i][j] != c || check[i][j] == BLACK) return;
	else
	{
		ans++;
		check[i][j] = BLACK;
		if (j == 0) dfs(i,m-1);
		dfs(i,j+1);
		dfs(i,j-1);
		dfs(i-1,j);
		dfs(i+1,j);
	} 
}

main(){
	//freopen ("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	
	while (cin >> n >> m)
	{
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++) cin >>a[i][j];
		memset(check,WHITE,sizeof(check));
		int x,y;
		cin >> x >> y;
		c = a[x][y];
		dfs(x,y);
		mx = 0;
		
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				if (a[i][j] == c)
				{
					ans = 0;
					dfs(i,j);
					mx=max(mx,ans); 
				}
		cout << mx << endl;
	}
}
