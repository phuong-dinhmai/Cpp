#include <bits/stdc++.h>
using namespace std;

struct tri
{
	int a, b, c;
	tri() {a = 0, b = 0, c = 0;}
	tri(int _a, int _b, int _c){a = _a, b = _b, c = _c;}
};

vector <tri> triangle;
vector <int> edge[1005], centre;
int a[5], n;

int dfs(int u, int pa, int root)
{
	int res = 0, sum = 0;
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (v == pa) continue;
		int tmp = dfs(v, u, root);
		res = max(res, tmp);
		sum += tmp;
	}
	if (u == root) return sum+1; else return res+1;
}

bool next_to(tri x, tri y)
{
	bool check1 = ((x.a == y.a && x.b == y.b) || (x.a == y.b && x.b == y.c) || (x.a == y.a && x.b == y.c));
    bool check2 = ((x.b == y.a && x.c == y.b) || (x.b == y.b && x.c == y.c) || (x.b == y.a && x.c == y.c));
    bool check3 = ((x.a == y.a && x.c == y.b) || (x.a == y.b && x.c == y.c) || (x.a == y.a && x.c == y.c));
    return (check1 || check2 || check3);
}

main(){
//	freopen("in.inp","r",stdin);
//	freopen("out.out","w",stdout);
	scanf("%d", &n);
	n -= 2;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &a[0], &a[1], &a[2]);
		sort(a, a+3);
		triangle.push_back(tri(a[0], a[1], a[2]));
	}
	
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (next_to(triangle[i], triangle[j])) edge[i].push_back(j), edge[j].push_back(i);
			
	for (int i = 0; i < n; i++)
		if (edge[i].size() == 3) centre.push_back(i);
	if (centre.size() <= 1) 
	{
		printf("%d\n", n);
	}
	else
	{
		int ans = 0;
		for (int i = 0; i < centre.size(); i++)
		{
			ans = max(ans, dfs(centre[i], centre[i], centre[i]));
		}
		printf("%d\n", ans);
	}
}
