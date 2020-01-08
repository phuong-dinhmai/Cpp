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
		vi a[n+1];
		int x, y;
		while (cin >> x >> y)
		{
			if (x == 0 && y == 0) break;
			a[x].push_back(y);
			a[y].push_back(x);
		} 
		
		bool is = true;
		queue <int> q;
		vi color(n+1, WHITE);
		color[1] = RED;
		q.push(1);
		
		while (!q.empty() && is)
			{
				int x = q.front();
				q.pop();
				for (int i = 0; i < a[x].size(); i++)
					if (color[a[x][i]] == WHITE)
					{
						if (color[x] == RED) color[a[x][i]] = BLACK;
						else color[a[x][i]] = RED;
						q.push(a[x][i]);
					}
					else if (color[x] == color[a[x][i]])
					{
						is = false;
						break;
					}
			}
		if (is) cout << "YES" << endl; else cout << "NO" << endl;
 	}
}
