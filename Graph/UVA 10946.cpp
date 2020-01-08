#include <bits/stdc++.h>
#define BLACK -1
#define WHITE 1
#define ii pair <int, char> 
using namespace std;

int n,m,ans;
char a[50][50];
int check[50][50];

void dfs(int i, int j, char c)
{
	//cout << i << " " << j << " " << c << endl;
	if (i<0 || j<0 || i>=n || j>=m) return;
	
	if (a[i][j] != c || check[i][j] == BLACK) return;
	else
	{
		ans++;
		check[i][j] = BLACK;
		dfs(i,j+1,c);
		dfs(i,j-1,c);
		dfs(i+1,j,c);
		dfs(i-1,j,c);
	} 
}

main(){
	vector <ii> res;
	int test = 0;
	//freopen ("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	
	while (cin >> n >> m)
	{
		test++;
		if (n == 0 && m == 0) break;
		memset(a,'.',sizeof(a));
		res.clear();
		for (int i=0; i<50; i++)
			for (int j=0; j<50; j++) check[i][j] = WHITE;
		
		for (int i = 0; i < n ; i++)
			for (int j = 0; j < m; j++) cin >> a[i][j];
			
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m ; j++)
			{
				if (a[i][j] != '.' && check[i][j] == WHITE)
				{
					ans = 0 ;
					dfs(i,j, a[i][j]);
					res.push_back(ii(-ans,a[i][j]));
				}
			}
		cout << "Problem " << test << ":" << endl;
		//cout << res.size() << endl;
		sort(res.begin(),res.end());
		for (int i=0; i<res.size(); i++) cout << res[i].second << " " << -res[i].first << endl;
	}
}

