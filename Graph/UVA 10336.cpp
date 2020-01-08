#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
#define maxN 1001
#define ii pair <int, char>
using namespace std;

int n,m,check[maxN][maxN];
char a[maxN][maxN];
vector < ii > res;

void dfs(int i, int j, char c)
{
	if (i<0 || j<0 || i>=n || j>=m) return;
	if (a[i][j] != c || check[i][j] == BLACK) return;
	check[i][j] = BLACK;
	dfs(i+1,j,c);
	dfs(i-1,j,c);
	dfs(i,j+1,c);
	dfs(i,j-1,c);
}

main(){
	int test;
	//freopen ("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	
	cin >> test;
	for (int k = 0; k < test; k++)
	{
		cin >> n  >> m ;
		for (int i = 0; i < n; i++)	
			for (int j = 0; j < m; j++) cin >> a[i][j];
			
		for (int i = 0; i < maxN; i++)
			for (int j = 0; j < maxN; j++) check[i][j] = WHITE;
		res.clear();
		
		for (int i = 0; i < n ; i++)
			for (int j = 0 ; j < m; j++)
				if (check[i][j] == WHITE )
				{
					bool  ok = false;
					for (int x = 0; x < res.size(); x++)
						if (a[i][j] == res[x].second) 
						{
							res[x].first--;
							ok = true;
							break;
						}
					if (!ok) res.push_back(ii(-1,a[i][j]));
					dfs(i,j,a[i][j]);
				}
						
		cout << "World #" << k+1 << endl;
		sort(res.begin(),res.end());
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i].second << ": " << -res[i].first << endl;
		}
	}
}
