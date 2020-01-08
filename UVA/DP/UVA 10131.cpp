#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

typedef struct ele 
{
	int w, s, pos;
} ele;

vector <ele> a;
vi f, trace;

bool cmp(const ele &a, const ele &b) 
{
	return (a.w < b.w);
}

main(){
	//freopen("in.inp","r",stdin);
	ele t;
	while (scanf("%d%d", &t.w, &t.s) == 2) 
	{
		t.pos = a.size();
		a.push_back(t);
	}
	sort(a.begin(), a.end(), cmp);
	f.assign(a.size(), 1);
	trace.assign(a.size(), -1);
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < i; j++)
			if (a[i].s < a[j].s && a[i].w > a[j].w)
			{
				if (f[j] + 1 > f[i]) 
				{
					f[i] = f[j] + 1;
					trace[i] = j;
				}
			}
	int ans = 0;
	int lis_end = 0;
	vi res;
	for (int i = 0;  i < a.size(); i++) 
		{
			if (ans < f[i])
			{
				ans = f[i];
				lis_end = i;
			}
		}
	printf("%d\n", ans);
	//for (int i = 0; i < a.size(); i++) cout << f[i] << " " << trace[i] << endl;
	while (lis_end != -1) 
	{
		res.push_back(a[lis_end].pos);
		lis_end = trace[lis_end]; 
	}
	for (int i = ans - 1; i >= 0; i--) printf("%d\n", res[i] + 1);
}
