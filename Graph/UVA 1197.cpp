#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
#define maxN 30005
#define vi  vector <int> 
using namespace std;

vi a[maxN];
int check[maxN];
int ans,n;

void find(int i)
{
	if (i<0 || i>n) return;
	if (check[i] == BLACK) return;
	check[i] = BLACK;
	ans++;
	for (int j = 0; j < a[i].size(); j++) find(a[i][j]);
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	int m;
	
	
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		ans = 0; 
		for (int i = 0; i < maxN; i++) a[i].clear();
		for (int i = 0; i < maxN; i++) check[i] = WHITE;
		
		for (int i = 0; i < m; i++) 
		{
			int t;
			cin >> t;
			int tg[maxN];
			for (int j = 0; j < t; j++) cin >> tg[j];
			for (int j = 0; j < t; j++) 
				for (int  k = 0; k < t; k++)
					if (j != k) a[tg[j]].push_back(tg[k]);
		}
		
		find(0);
		cout << ans << endl;
	}
}
