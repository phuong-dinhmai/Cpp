#include <bits/stdc++.h>
#define WHITE 0
#define BLACK -1
#define RED 1
#define vi vector <int>
using namespace std;

main(){
	 int test;
	 //freopen("in.inp","r",stdin);
	 //freopen("out.out","w",stdout);
	 
	 cin >> test;
	 for (int k = 0; k < test; k++)
	 {
	 	int n, m;
	 	cin >> n >> m;
	 	vi a[n];
	 	for (int i = 0; i < m; i ++)
	 	{
	 		int x, y;
	 		cin >> x >> y;
	 		a[x].push_back(y);
	 		a[y].push_back(x);
	 	}
	 	
	 	vi color(n, WHITE);
	 	bool is = true;
	 	int ans = 0;
	 	
	 	for (int j = 0; j < n; j++)
	 	{
	 		if (!is) break;
	 		if (color[j] == WHITE)
	 		{
	 			queue <int> ok;
	 			ok.push(j);
	 			color[j] = RED;
	 			int check = 0, red = 0;
	 			
	 			while (!ok.empty() && is)
			 	{
			 		int x = ok.front();
			 		ok.pop();
			 		check++;
			 		if (color[x] == RED) red++;
			 		for (int i = 0; i < a[x].size(); i++)
			 			if (color[a[x][i]] == WHITE)
			 			{
			 				if (color[x] == RED)  color[a[x][i]] = BLACK;
			 				else color[a[x][i]] = RED;
			 				ok.push(a[x][i]);
			 			}
			 			else
			 			{
			 				if (color[x] == color[a[x][i]])
			 				{
			 					is = false;
			 					break;
			 				}
			 			}
			 	}
			 	if (check == 1) ans++; else ans += min(red, check - red);
	 		}
	 	}
	 	
	 	if (!is) cout << "-1" << endl; else cout << ans << endl;
	 }
}
