#include <bits/stdc++.h>
#define ll long long
#define vi vector <long long>
using namespace std;

const int N = 1e5+7;

struct data {
	ll t, a, b;
} piz[N];

int n, ti;
ll suma[N], sumb[N], sumtb[N], f[N];
int pos = 0;
vi A, B;

bool cmp(const data &x, const data &y)
{
	return ((x.t < y.t) || (x.t == y.t && x.a < y.a) || (x.t == y.t && x.a == y.a && x.b < y.b));
}

bool bad(int t1, int t2, int t3)
{
	return ((B[t1] - B[t2])*(A[t2] - A[t3]) < (B[t3] - B[t2])*(A[t2] - A[t1]));
}

void add(ll a, ll b)
{
	A.push_back(a);
	B.push_back(b);
	while (A.size() > 2 && bad(A.size() - 3, A.size() - 2, A.size() - 1))
	{
		A.erase(A.end() - 2);
		B.erase(B.end() - 2);
	}
}

ll query(ll x)
{
	if (pos > A.size()-1) pos = A.size() - 1;
	while (pos < A.size() - 1 && A[pos]*x + B[pos] < A[pos+1]*x + B[pos+1]) pos++;
	//cout << A[pos] << " " << B[pos] << endl;
	return A[pos]*x + B[pos];
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	cin >> n >> ti;
	for (int i = 1; i <= n; i++)
	{
		cin >> piz[i].t >> piz[i].a >> piz[i].b;
	}
	
	sort(piz+1, piz+n+1, cmp);
	for (int i = 1; i <= n; i++) 
		sumb[i] = sumb[i-1] + piz[i].b,
		suma[i] = suma[i-1] + piz[i].a,
		sumtb[i] = sumtb[i-1] + piz[i].t * piz[i].b;
		
	f[1] = piz[1].a - ti;
	add(sumb[1], -sumtb[1] - suma[1] + f[1]);
	for (int i = 2; i <= n; i++)
	{
		ll x = suma[i] + sumtb[i] - sumb[i] * piz[i].t - ti;
		f[i] = query(piz[i].t);
		//cout << x << " " << f[i] << endl;
		f[i] += x;
		f[i] = max(f[i], suma[i] + sumtb[i-1] - piz[i].t * sumb[i-1] - ti);
		if (i != n) add(sumb[i], -sumtb[i] - suma[i] + f[i]);
	}
	//for (int i = 1; i <= n; i++) cout << suma[i] << " " << sumb[i] << " " << sumtb[i] << endl;
	//for (int i = 1; i <= n; i++) cout << f[i] << " " ;
	//cout << endl;
	printf("%lld\n", f[n]);
}
