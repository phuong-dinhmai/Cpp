#include <bits/stdc++.h>
#define vi vector <int>
#define ii pair <int, int>
#define vii vector <pair <int, ii> >
#define inf 2147383647
using namespace std;

vii edge;
vi father, size_of_set;
int n, m;

void init()
{
	father.assign(n,0);
	for (int i = 0; i < n; i++) father[i] = i;
	size_of_set.assign(n, 1);
	edge.clear();
}

void input()
{
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edge.push_back(make_pair(z, ii(x,y)));
	}
	sort(edge.begin(), edge.end(), greater < pair<int, ii> >());
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
	}
	else
	{
		father[y] = x;
		size_of_set[x] += size_of_set[y];
	}
}

main(){
	int test;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	cin >> test;
	for (int k = 0; k < test; k++)
	{
		cin >> n >> m;
		init();
		input();
		int mn = inf;
		
		for (int i = 0; i < edge.size(); i++) 
			if (!same_set(edge[i].second.first, edge[i].second.second))
			{
				make_set(edge[i].second.first, edge[i].second.second);
				mn = min (mn, edge[i].first);
			}
		
		cout << "Case #" << k+1 << ": " << mn << endl; 
	}
}
