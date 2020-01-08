#include <bits/stdc++.h>
#define vi vector <int>
#define ii pair <int, int>
#define inf 1e9+7
using namespace std;

ii pla[1005];
vi a[1005];
int n;
bool vis[1005];

bool near(int x, int y)
{
	if (pla[x].first < pla[y].first || (pla[x].first == pla[y].first && pla[x].second < pla[y].second)) return true;
	else return false;
}

int dis(int x, int y)
{
	int l = pla[x].first - pla[y].first;
	int w = pla[x].second - pla[y].second;
	return (l*l + w*w);
}

void building()
{
	for (int i = 0; i < n; i++)
	{
		a[i].clear();
		vis[i] = false;
		int mn = inf;
		int b = 1;
		for (int j = 0; j < n; j++)
			if (i != j)
			{
				int x = dis(i,j);
				if (mn > x) 
				{
					mn = x;
					b = j;
				}
				else
				if (mn == x)
					if (near(i,j)) b = j;
			}
		a[i].push_back(b);
		
		if (n > 2)
		{
			mn = inf;
			for (int j = 0; j < n; j++)
				if (j != a[i][0] && j != i) 
				{
					int x = dis(i,j);
					if (mn > x) 
					{
						mn = x;
						b = j;
					}
					else if (mn == x)
						if (near(i,j)) b = j;
				}
			a[i].push_back(b);
		}
	}
}

void dfs(int i)
{
	vis[i] = true;
	for (int j = 0; j < a[i].size(); j++) if (!vis[a[i][j]]) dfs(a[i][j]);
}

bool result ()
{
	for (int i = 0; i < n; i++)
		if (!vis[i]) return false;
	return true;
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	while (cin >> n)
	{
		if (n == 0) break;
		for (int i = 0; i < n; i++) cin >> pla[i].first >> pla[i].second;
		if (n == 1) cout << "All stations are reachable." << endl;
		else
		{
			building();
			dfs(0);
			if (result()) cout << "All stations are reachable." << endl;
			else cout << "There are stations that are unreachable." << endl;
		}
	}
}
