#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <float, int> fi;
typedef vector <int> vi;
typedef vector <float> vf;
typedef vector < pair <float, ii> > vfii;

vfii l;
vi father, size_of_set;
vf x, y;
int n;

void init()
{
	father.assign(n,0);
	for (int i = 0; i < n; i++) 
	{
		father[i] = i;
	}
	size_of_set.assign(n, 1);
}

float dis(int i, int j)
{
	return sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
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
	if (size_of_set[x] < size_of_set[y])
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

void input()
{
	x.clear();
	y.clear();
	for (int i = 0; i < n; i++) 
	{
		float a, b;
		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}
		
	for (int i =  0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				{
					float k = dis(i,j);
					l.push_back(make_pair(k, ii (i,j)));
				}
	sort(l.begin(), l.end());
}

main(){
	int test; 
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	cin >>  test;
	while (test--)
	{
		cin >> n;
		init();
		l.clear();
		input();
		
		float cost = 0;
 		for (int i = 0; i < l.size(); i++)
		{
			if (!same_set(l[i].second.first, l[i].second.second))
			{
				make_set(l[i].second.first, l[i].second.second);
				cost += l[i].first;
			}
		}
		cout << setprecision(2) << fixed << cost << endl;
		if (test != 0) cout << endl;
	}
}
