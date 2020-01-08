#include <bits/stdc++.h>
#define inf 1e9+7
#define vi vector <int>
#define maxN 105
using namespace std;

map <string, int> map1;
map <int, string> map2;
int num[maxN], low[maxN], parent[maxN];
vi a[maxN];
vector <string> ans;
int t, n;
bool mark[maxN], vis[maxN];

void init(){
	for (int i = 0; i < maxN; i++)
	{
		num[i] = 0;
		low[i] = inf;
		vis[i] = false;
		mark[i] = false;
		parent[i] = inf;
		a[i].clear();
	}
	map1.clear();
	map2.clear();
	t = 0;
	ans.clear();
}

void dfs(int u, int root)
{
	num[u] = ++t;
	int chil = 0;
	vis[u] = true;
	for (int i = 0; i < a[u].size(); i++)
	{
		int v = a[u][i];
		if (!vis[v])
		{
			chil ++;
			parent[v] = u;
			dfs(v, root);
			low[u] = min(low[u], low[v]);
			if (u == root && chil > 1) mark[u] = true;
 			else if (low[v] >= num[u] && u != root) mark[u] = true; 
		}
		else 
			if (parent [u] != v) low[u] = min(low[u], num[v]);
	}
	
}

main(){
	int test = 0;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	while (cin >> n)
	{
		if (n == 0) break;
		
		init(); 
		
		test++;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			map1[s] = i;
			map2[i] = s;
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			string s1, s2;
			cin >> s1 >> s2;
			int x = map1[s1], y = map1[s2];
			a[x].push_back(y);
			a[y].push_back(x);	
		}
		
		for (int i = 0; i < n; i++)
			if (!vis[i]) dfs(i,i);
			
		for (int i = 0; i < n; i++) 
			if (mark[i]) ans.push_back(map2[i]);
			
		sort(ans.begin(), ans.end());
		
		if (test != 1) cout << endl;
		cout << "City map #" << test << ": " << ans.size() << " camera(s) found" << endl; 
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
	}
}
