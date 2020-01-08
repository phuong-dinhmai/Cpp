#include <bits/stdc++.h>
#define WHITE 1
#define GRAY 0
#define BLACK -1
using namespace std;

int n,m,ans = 0;
char a[50][50];
int check[50][50];
int mx; 

void dfs(int i, int j)
{
	if (a[i][j] == 'G' && check[i][j] != BLACK) 
	{
		ans++;
	}
	if (a[i][j] == '#' || check[i][j] == BLACK
	   || a[i+1][j] == 'T' || a[i-1][j] == 'T' 
	   || a[i][j+1] == 'T' || a[i][j-1] == 'T') 
	{
		mx = max(mx,ans);
		check[i][j] = BLACK;
		return;
	}
	else
	{
		check[i][j] = BLACK;
		dfs(i,j+1);
		dfs(i,j-1);
		dfs(i-1,j);
		dfs(i+1,j);
	}
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	
	while (cin >> m >> n)
	{
		mx  = 0;
		ans = 0;
		memset(check, WHITE, sizeof(check));
		int x, y;
		for (int i=0; i<n; i++) 
			for (int j=0; j<m; j++) 
			{
				cin >> a[i][j];
				if (a[i][j] == 'P')  
				{
					x = i;
					y = j;
				}
			}
		dfs(x,y);
		cout << mx << endl; 
	}
}
