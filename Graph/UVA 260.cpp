#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
using namespace std;

int n;
char a[500][500];
int check[500][500];
bool ok;


void dfs(int i, int j)
{
	if (i<0 || j<0 || i>=n || j>=n)
	{
		if (j == n) ok=true;
		return;
	}
	if (a[i][j] == 'b' || check[i][j] == BLACK) return ;
	else 
	{
		check[i][j] = BLACK;
		dfs(i-1,j-1);
		dfs(i,j+1);
		dfs(i,j-1);
		dfs(i+1,j);
		dfs(i-1,j);
		dfs(i+1,j+1);
	}
}

main(){
	//freopen ("in.inp", "r", stdin);
	//freopen ("out.out", "w", stdout);
	
	int test=0;
	while (cin >> n)
	{ 
		if (n == 0) break;
		test++;
		memset(check, WHITE, sizeof(check));
		ok = false; 
		
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++) cin>>a[i][j];
		for (int i=0; i<n; i++)
			if (a[i][0] == 'w')
			{
				dfs(i,0);
				if (ok) break;
			}
		if (ok) cout << test << " " << "W" << endl;
		else cout << test << " " << "B" << endl;
	}
}
