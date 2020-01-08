#include <bits/stdc++.h>
#define ll long long
#define vi vector <ll>
#define ii pair <ll, ll>
#define fi first
#define se second
using namespace std;

const int N = 5e5+7;
const ll inf = 9223372036854775800;

ii a[N], b[N];
vi A, B;
int n, m;

bool bad(int t1, int t2, int t3)
{
	return ((B[t1] - B[t2])*(A[t2] - A[t3]) < (B[t3] - B[t2])*(A[t2] - A[t1]));
}

void update(ll x, ll y)
{
	A.push_back(x);
	B.push_back(y);
	while (A.size() > 2 && bad(A.size() - 3, A.size() - 2, A.size() - 1))
	{
		A.erase(A.end() - 2);
		B.erase(B.end() - 2);
	}
}

double cut(int t1, int t2)
{
	return ((double) (B[t1] - B[t2]) / (double)(A[t2] - A[t1]));
}

ll get(ll u, ll y)
{
	double x = (double) (u) / (double) (y);
	int lo = 0;
	int hi =  A.size()-1;
	int res;
	double lft, rght;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (mid == 0) lft = -inf; else lft = cut(mid, mid-1);
		if (mid == A.size() - 1) rght = inf; else rght = cut(mid, mid+1);
		if(lft <= x && x <= rght) 
		{
			res = mid;
			break;
		}
		if (x > rght) lo = mid + 1; 
		if (x < lft) hi = mid - 1;
	}
	return (A[res]*u + B[res]*y);
}

main(){
	//freopen("in.inp","r",stdin);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%I64d%I64d", &b[i].fi, &b[i].se);
	}
	
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%I64d%I64d", &a[i].fi, &a[i].se);
	}
	
	sort(a+1, a+m+1, greater <ii> ());
	
	for (int i = 1; i <= m; i++)
	{
		update(a[i].fi, a[i].se);
	}
	
	for (int i = 1; i <= n; i++)
	{
		printf("%I64d ", get(b[i].fi, b[i].se));
	}
}
