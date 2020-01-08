#include <bits/stdc++.h>
#define ll long long
#define ii pair <ll, ll>
#define vi vector <ll>
#define vii vector <ii>
#define fi first
#define se second
using namespace std;
 
vi A, B;
int pos = 0, n;
 
bool bad(int t1, int t2, int t3)
{
	return ((B[t3] - B[t1])*(A[t1] - A[t2]) < (B[t2] - B[t1])*(A[t1] - A[t3]));	
}
 
void add(ll a, ll b)
{
	A.push_back(a);
	B.push_back(b);
	while (A.size() > 2 && bad(A.size()-3, A.size()-2, A.size()-1)) 
	{
		A.erase(A.end() - 2);
		B.erase(B.end() - 2);
	}
	/*for (int i = 0; i < A.size(); i++) 
	{
		cout << A[i] << " " << B[i] << endl;
	}
	cout << endl;*/
}
 
ll query(int x)
{
	if (pos > A.size() - 1) pos = A.size() - 1;
	while ((pos < A.size() - 1) && (A[pos+1] * x + B[pos+1] < A[pos] * x + B[pos])) pos++;
	//cout << x << " " << A[pos] << " " << B[pos] << endl;
	return A[pos]*x + B[pos];
}
 
main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	ii a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].fi >> a[i].se;
	}
	sort(a, a+n, greater <ii>());
	
	vii b;
	b.push_back(ii(0, 0));
	for (int i = 0; i < n; i++)
	{
		if (a[i].se > b.back().se) b.push_back(a[i]);
	}
	add(b[1].fi, 0);
	ll res = 0;
	
	for (int i = 1; i < b.size(); i++)
	{
		res = query(b[i].se);
		//cout << res << endl;
		if (i != b.size() - 1) add(b[i+1].fi, res);
	}
	cout << res << endl;
}
