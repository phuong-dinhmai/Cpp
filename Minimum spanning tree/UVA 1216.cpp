#include <bits/stdc++.h>
#define ii pair <long, long >
#define vfi vector <pair <double, ii> >
#define vi vector <long >
#define inf (long)2e9+7
using namespace std;

vfi edge; 
vector<double> x, y;
vi father, size_of_set;
long n,m;

void init()
{
	father.assign(n,0);
	for (long i = 0; i < n; i++) father[i] = i;
	size_of_set.assign(n,1);
	edge.clear();
	x.clear();
	y.clear();
}

double dis (long i, long j)
{
	return sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
}

void input()
{	
	for (long i = 0; i < n; i++)
		for (long j = 0; j < i; j++) 
			if (i != j)
			{
				double r = dis(i,j);
				edge.push_back(make_pair(r, ii(i,j)));
			}
	sort(edge.begin(), edge.end());
}

long find(long x)
{
	return (x == father[x]? x : (father[x] = find(father[x])));
}

bool same_set(long x, long y)
{
	return (find(x) == find(y));
}

void make_set(long i, long j)
{
	long x = find(i);
	long y = find(j);
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
	freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	long test;
	cin >> test;
	while (test--)
	{
		cin >> m;
		long k;
		while (cin >> k)
		{
			if (k == -1) break;
			else 
			{
				x.push_back(k);
				cin >> k;
				y.push_back(k);
			}
		}
		n = x.size();
		init();
		input();
		double mx = -inf;
		long ans = n;
		
		for (long i = 0; i <  edge.size(); i++)
			if (!same_set(edge[i].second.first, edge[i].second.second))
			{
				make_set(edge[i].second.first, edge[i].second.second);
				if (ans != m)
				{
					mx = edge[i].first;
					ans--;
				}
			}	
		cout << (long long)ceil(mx) << endl;
	}
}
