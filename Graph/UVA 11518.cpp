#include <bits/stdc++.h>
#define maxN 10005
#define WHITE 1 
#define BLACK -1
#define vi vector <int> 
using namespace std;

int check[maxN];
int ans,n;
vi a[maxN];

void fall(int i)
{
	if (i<0 || i>n) return;
	if (check[i] == BLACK) return;
	ans++;
	check[i] = BLACK;
	for (int j = 0; j < a[i].size(); j++) fall(a[i][j]);
}

main(){
	int test;
	int m,l;
	//freopen  ("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	
	cin >> test;
	for (int k = 0; k < test; k++)
	{
		for(int i = 0; i < maxN; i++) check[i] = WHITE;
		for (int i = 0; i < maxN; i++) a[i].clear();
		ans = 0;
		
		cin >> n >> m >> l;
		for (int i = 0; i < m; i++) 
		{
			int x, y;
			cin >> x >> y;
			a[x].push_back(y);
		}
		 
		for (int i = 0; i < l; i++)
		{
			int p;
			cin >> p;
			if (check[p] == WHITE)
			{
				fall(p);
			}
		}
		cout << ans << endl;
	}
}
