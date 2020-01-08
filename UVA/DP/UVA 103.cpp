#include <bits/stdc++.h>
using namespace std;

int a[40][30];
int f[40];
int trace[40];
int n, m;
int pos[40];

bool check(int x, int y)
{
	for (int i = 0; i < n; i++)
		if (a[x][i] >= a[y][i]) return false;
	return true; 
}

main(){
	//freopen("in.inp","r",stdin);
	
	while (cin >> m >> n)
	{
		for (int i = 0; i <= m; i++) 
		{
			trace[i] = -1;
			f[i] = 1;
			pos[i] = i;
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) cin >> a[i][j];
		for (int i = 0; i < m; i++) sort(a[i], a[i]+n);
		for (int i = 0; i < m; i++)
			for (int j = i+1; j < m; j++)
			{
				for (int k = 0; k < n; k++)
					if (a[i][k] > a[j][k])
					{
						swap(a[i], a[j]);
						swap(pos[i], pos[j]);
						break;
					}
					else if (a[i][k] == a[j][k]) continue; else break;
			}
		/*for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++) cout << a[i][j] << " ";
				cout << endl;
			}*/
		for (int i = 0; i < m; i++)
			for (int j = 0; j < i; j++)
				if (check(j,i)) 
					{
						if (f[i] < f[j] + 1) 
						{
							trace[i] = j;
							f[i] = f[j] + 1;
						}
					}
		int best = 0;
		int bestend = 0;
		for (int i = 0; i < m; i++) 
			if (best < f[i]) 
			{
				best = f[i];
				bestend = i;
			}
		vector <int> ans;
		while (bestend != -1) 
		{
			ans.push_back(pos[bestend]);
			bestend = trace[bestend];
		}
		cout << best << endl;
		for (int i = best - 1; i >= 0; i--) 
			if (i != 0) cout << ans[i]+1 << " "; else cout << ans[i] + 1 << endl;
	}
}
