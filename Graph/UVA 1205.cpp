#include <bits/stdc++.h>
#define maxN 1005
using namespace std;


main(){
	int n, root;
	bool exist[maxN];
	int t[maxN];
	int cost[maxN];
	int father[maxN];
	int w[maxN];
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	while (cin >> n >> root)
	{
		if (n == 0 && root == 0) break;
		for (int i = 1; i <= n; i++) 
		{
			cin >> w[i];
		}
		for (int i = 1; i < n; i++)
		{
			int x, y; 
			cin >> x >> y;
			father[y] = x;
		}
		
		for (int i = 1; i <= n; i++)
		{
			exist[i] = true;
			t[i] = 1;
			cost[i] = w[i];
		}
		
		for (int i = 1; i < n; i++)
		{
			int maxX = -1;
			double maxP = -1;
			
			for (int j = 1; j <= n; j++)
				if (exist[j] && maxP < (double)w[j]/t[j] && j != root)
				{
					maxX = j;
					maxP = (double)w[j] / t[j];
				}
			for (int j = 1; j <= n; j++)
					if (father[j] == maxX) father[j] = father[maxX];

			w[father[maxX]] += w[maxX];
			cost[father[maxX]] += t[father[maxX]] * w[maxX] + cost[maxX] ;
			t[father[maxX]] += t[maxX];
			exist[maxX] = false;
		}
		cout << cost[root] << endl;
	}
}
