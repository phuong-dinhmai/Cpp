#include <bits/stdc++.h>
#define maxN 30
#define vi vector <int>
using namespace std;

vi a[maxN];
bool vis[maxN];
int n;

void init()
{
	for (int i = 0; i < maxN; i++)
	{
		vis[i] = false;
		a[i].clear();
	}
}

void dfs(int u)
{
	vis[u] = true;
	for (int i = 0; i < a[u].size(); i++)
	{
		int v = a[u][i];
		if (!vis[v]) dfs(v);
	}
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	int test;
	string s;
	cin >> test;
	getchar();
	getchar();
	for (int k = 0; k < test; k++)
	{
		init(); 
		
		getline(cin ,s);
		n = s[0] - 'A' + 1;
		int ans = 0;
		char x,y;
		while (getline(cin, s))
		{
			if (s.empty()) break;
			a[s[0] - 'A'].push_back(s[1] - 'A');
			a[s[1] - 'A'].push_back(s[0] - 'A');
		}
		
		for (int i = 0; i < n; i++)
			if (!vis[i]) 
			{
				dfs(i);
				ans++;
			}
		
		cout << ans << endl;
		if (k != test - 1) cout << endl;
	}
}
