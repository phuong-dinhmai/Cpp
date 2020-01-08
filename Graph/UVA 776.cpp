#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
using namespace std;

int n,m;
char s[1001][1001],s1[2002][2002];
int ans,check[1001][1001],res[1001][1001],ok[1001][1001],width[1001];

void dfs(int i, int j, char c)
{
	if (i<0 || j<0 || i>=n || j>=m) return;
	if (check[i][j] == BLACK || s[i][j] != c) return;
	check[i][j] = BLACK;
	res[i][j] = ok[i][j] = ans;
	dfs(i+1,j,c);
	dfs(i-1,j,c);
	dfs(i,j+1,c);
	dfs(i,j-1,c);
	dfs(i-1,j-1,c);
	dfs(i-1,j+1,c);
	dfs(i+1,j+1,c);
	dfs(i+1,j-1,c);
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	n  = 0;
	
	while (gets(s1[0]))
	{
		n = 1;
		while (gets(s1[n])) 
		{
			if (s1[n][0] == '%') break;
			n++;
		}
		
		m = 0; 
		ans = 0;
		int x = strlen(s1[0]);
		for (int i = 0; i < 1001; i++) 
			for (int j = 0; j < 1001; j++) check[i][j] = WHITE;
		x=strlen(s1[0]);
		for (int i = 0; i < n ; i++)
		{
			m = 0;
			for (int j = 0; j < x; j++) 
			{
				if (s1[i][j] != 32) 
				{
					s[i][m] = s1[i][j];
					m++;
				}
			}
		}
		for (int i = 0; i < m; i++) width[i] = 0;
			
		for(int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (check[i][j] == WHITE)
					{
						ans++;
						dfs(i,j,s[i][j]);
					}
			
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				int digit = 0;
				while (ok[j][i] != 0)
				{
					ok[j][i]/=10;
					digit++;
				}
				width[i] = max(width[i],digit);
			}
		
		for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++) 
				{
					if (j != 0) cout << " ";
					cout << setw(width[j]) << res[i][j];
				}
				cout << endl;
			}
		cout << "%" << endl;
		
		n = 0;
	} 
}
