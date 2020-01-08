#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

vi father, size_of_set;
int n;

void init()
{
	father.assign(n,0);
	size_of_set.assign(n,1);
	for (int i = 0; i < n; i++)
	{
		father[i] = i;
	}
}

int find(int x)
{
	return (x == father[x]? x : (father[x] = find(father[x])));
}

bool same_set(int x, int y)
{
	return (find(x) == find (y));
}

void make_set(int i, int j)
{
	int x = find(i);
	int y = find(j);
	if (size_of_set[x] > size_of_set[y])
	{
		father[x] = y;
		size_of_set[y]+=size_of_set[x];
	}
	else
	{
		father[y] = x;
		size_of_set[x]+=size_of_set[y];
	}
}
main(){
	int m, test = 0;
	freopen("in.inp","r",stdin);
	freopen("out.out","w",stdout);
	
	while (cin >> n >> m)
	{
		test++;
		if (m == 0 && n == 0) break;
		int ans = n;
		init(); 
		
		for (int i = 0; i < m; i++)
		{
			int x,y;
			cin >> x >> y;
			x--; y--;
			if (!same_set(x,y)) 
			{
				make_set(x,y);
				ans--;
			}
		}
		cout << "Case " << test << ": " << ans << endl;
	}
}
