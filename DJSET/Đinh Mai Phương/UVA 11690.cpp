#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

int n;
vi a, father, size_of_set, val;

void init()
{
	father.assign(n,0);
	for (int i = 0; i < n; i++) father[i] = i;
	size_of_set.assign(n,1);
	//val.assign(n, 0);
	//for (int i = 0; i < n; i++) val[i] = a[i];
	a.assign(n,0);
}

int find(int x)
{
	return (x == father[x]? x : (father[x] = find(father[x])));
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
		val[y] += val[x];
	}
	else
	{
		father[y] = x;
		size_of_set[x] += size_of_set[y];
		val[x] += val[y];
	}
}

bool check()
{
	for (int i = 0; i < n; i++) 
		if (val[find(i)] != 0) return false;
	return true;
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	int test;
	cin >> test;
	while (test--)
	{
		long m;
		cin >> n >> m;
		init();
		val.assign(n,0);
		for (int i = 0; i < n; i++) 
		{
			cin >> a[i];
			val[i] = a[i];
		}
		
		for (long  i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			if (!same_set(x,y)) make_set(x,y);
		}
		if (check()) cout << "POSSIBLE" << endl; 
		else cout << "IMPOSSIBLE" << endl;
	}
}
