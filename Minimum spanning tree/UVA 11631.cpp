#include <bits/stdc++.h>
#define ii pair <int, int>
#define vi vector <int>
#define vii vector < pair <int, ii> >
using namespace std;

vii edge;
vi father, size_of_set;
int n,m;
long total;

void init()
{
	father.assign(n,0);
	for (int i = 0; i < n; i++) father[i] = i;
	size_of_set.assign(n,1);
	edge.clear();
	total = 0;
}

void input()
{
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		total += z;
		edge.push_back(make_pair(z, ii(x,y)));
	}
	sort (edge.begin(), edge.end());
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
		size_of_set[y] += size_of_set[x];
		father[x] = y; 
	}
	else
	{
		size_of_set[x] += size_of_set[y];
		father[y] = x; 	
	}
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	while (cin >> n >> m)
	{
		if (m == 0 && n == 0) break;
		init();
		input();
		
		int cost = 0;
		
		for (int i = 0; i <  edge.size(); i++)
			if (!same_set(edge[i].second.first, edge[i].second.second)) 
			{
				make_set(edge[i].second.first, edge[i].second.second);
				cost += edge[i].first;
			}
			
		cout << total - cost << endl;
	}
}
