#include <bits/stdc++.h>
#define maxN 100
#define vi vector <int>
#define inf 1e9+7
using namespace std;

int n;
int t;
vi a[maxN];
bool mark[maxN];
int num[maxN], low[maxN], sl_con[maxN];

void init()
{
	for (int i = 0; i < maxN; i++) 
	{
		a[i].clear();
		mark[i] = false;
		num[i] = 0;
		sl_con[i] = 0;
		low[i] = inf;
	}
	t = 0;
	
}

void dfs(int v)
{
	//t++;
	num[v] = ++t;
	
	for (int i = 0; i < a[v].size(); i++)
		if (num[a[v][i]] == 0)
		{
			sl_con[v]++;
			dfs(a[v][i]);
			if (low[a[v][i]] >= num[v]) mark[v] = true;
			if (low[a[v][i]] < low[v]) low[v] = low[a[v][i]];
		}
		else
		{
			if (low[v] > num[a[v][i]]) low[v] = num[a[v][i]];
		}
}

main(){
	int n;
	string k;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	 
	 while (getline(cin,k))
	 {
	 	istringstream m(k); 
	 	init();
	 	m >> n;
	 	if (n == 0) break;

	 	string line;
	 	while (getline(cin,line))
	 	{
	 		istringstream ss(line);
	 		int x, f;
	 		ss >> f;
	 		if (f == 0) break;
	 		while (ss >> x)
	 		{
	 			a[f-1].push_back(x-1);
	 			a[x-1].push_back(f-1);
	 		}
	 	}
	 	
	 	for (int i = 0; i < n; i++)
	 		if (num[i] == 0)
			{
				dfs(i);
				if (sl_con[i] < 2) mark[i] = false;
 			} 
 		int sl = 0;
 		for (int i = 0; i < n; i++) 
 			if (mark[i]) sl++;
 		cout << sl << endl;
	 }
}
