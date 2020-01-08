#include <bits/stdc++.h>
#define maxN 27
#define vi vector <int>
using namespace std;

int k;
vi a[maxN];
bool candle[maxN];
int step;

void init()
{
	for (int i = 0; i < maxN; i++)	
		{
			a[i].clear();
			candle[i] = false;
		}
	step = 0;
}

int dfs(int u, int m)
{
	step++;
	if (step % k == 0) candle[u] = true;
	for (int i = 0; i < a[u].size(); i++)
	{
		int v = a[u][i];
		if (!candle[v] && v != m)
		{
			if (candle[u]) cout << char(u + 'A') << " ";
			return dfs(v, u);
		}	
	}
	cout << "/" << char(u + 'A') << endl; 
	return 0;
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w", stdout);
	
	string line;
	
	while (1)
	{
		getline(cin, line);
		if (line == "#") break;
		int i,st = 0,e[2];
		
		init();
		for (i = 0; i < line.size(); i++)
		{
			if (line[i] == '.')  break;
			if (line[i] == ':' || line[i] == ';')
			{
				if (line[i] == ':') st = 1; else  st = 0;
			}
			else 
			{
				e[st] = line[i];
				if (st == 1) 
				{
					a[e[0] - 'A'].push_back(e[1] - 'A');
				}
			}
		}
		
		int s,t;
		i++;
		while (line[i] == ' ') i++;
		s = line[i++] - 'A';
		while (line[i] == ' ') i++;
		t = line[i++] - 'A';
		while (line[i] == ' ') i++;
		k = 0;
		while (i < line.size()) 
		{
			k = k*10 + line[i] - '0';
			i++;
		}
		int n = dfs(s, t);
	}
}
