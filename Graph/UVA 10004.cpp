#include <bits/stdc++.h>
#define WHITE 0
#define BLACK -1
#define RED 1
#define vi vector <int>
using namespace std;

main(){
	int n;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	while (cin >> n)
	{
		if (n == 0) break;
		vi a[n];
		int m;
		
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int x,y;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		
		queue <int> ok;
		ok.push(0);
		vi color (n, 0);
		bool bicolor = true;
		color[0] = RED;
		while (!ok.empty() && bicolor)
		{
			int k = ok.front();
			ok.pop();
			for (int i = 0; i < a[k].size(); i++)
				if (color[a[k][i]] == WHITE) 
				{
					if (color[k] == BLACK) color[a[k][i]] = RED; else color[a[k][i]] = BLACK;
					ok.push(a[k][i]);
				}
				else
					if (color[a[k][i]] == color[k]) 
					{
						bicolor = false;
						break;
					}
		}
		if (bicolor) cout << "BICOLORABLE." << endl; else cout << "NOT BICOLORABLE." <<endl;
	}
}
