#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

vi size_of_set, father;
int n;
int mx;

void init()
{
	father.assign(n, 0);
	for (int i = 0; i < n; i++) father[i] = i;
	size_of_set.assign(n,1);
}

int find(int x)
{
	return (x == father[x])? x: (father[x] = find(father[x]));
}

bool same_set(int x, int y)
{
	return (find(x) == find(y));
}

void make_set(int i, int j)
{
	int x = find(i);
	int y = find(j);
	if (size_of_set[x] > size_of_set[y])
	{
		father[x] = y;
		size_of_set[y] += size_of_set[x];
	}
	else
	{
		father[y] = x;
		size_of_set[x] += size_of_set[y];
	}
	mx = max (mx, max(size_of_set[x], size_of_set[y]));
}

main(){
	freopen("in.inp","r",stdin);
	freopen("out.out","w",stdout);
	int test, m;
	
	cin >> test;
	while (test--)
	{
		cin >> n >> m;
		mx = 0;
		init(); 
		
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			x--; y--;
			if (!same_set(x,y))
			{
				make_set(x,y);
			}
		}
		cout << mx << endl;
	}
}
