#include <bits/stdc++.h>
#define vi vector <int>
#define vii vector <vi> 
#define WHITE -1
#define BLACK 1
using namespace std;

int dfs_num[105],n,m;
vii f;

void dfs(int n)
{
	//dfs_num[n] = BLACK;
	for (int i=0; i<f[n].size(); i++)
		if (dfs_num[f[n][i]] == WHITE)
		{
			dfs_num[f[n][i]] = BLACK;
			dfs(f[n][i]);
		}
}

void result()
{
	vi res;
	int ans=0;
	//for (int i=0; i<n; i++) cout << dfs_num[i] << " ";
	for (int i=0; i<n; i++)
		if (dfs_num[i] == WHITE) 
		{
			ans++;
			res.push_back(i);
		}
	cout << ans;
	for (int i=0; i<res.size(); i++) cout << " " << res[i]+1;;
	cout << endl;
}

main(){
	//freopen ("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	
	while (cin >> n)
	{
		if (n == 0) break;
		
		f.clear();
		f.resize(n);
		 
		int a;
		while (cin >> a)
		{
			if (a == 0) break;
			int b;
			while (cin >> b)
			{
				if (b == 0) break;
				f[a-1].push_back(b-1);
			}
		}
		cin >> m;
		for (int i=0; i<m; i++)
		{
			int k;
			cin >> k;
			for (int i=0; i<105; i++) dfs_num[i]= WHITE;
			dfs(k-1);
			result();
		}
	}
}
