#include <bits/stdc++.h>
#define ll long long
#define vi vector <ll>
#define ii pair <ll, int>
#define maxN (int) (1e6+7)
using namespace std;

ll a[maxN], b[maxN], f[maxN];
ll sum = 0;
int n;
priority_queue <ii> val;
vi save;

main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	f[0] = a[0];
	for (int i = 1; i < n; i++) f[i] = f[i-1] + a[i];
	for (int i = 0; i < n; i++)
	{
		if (val.empty() && b[i] <= f[i]) 
		{
			val.push(ii(b[i], i));
			sum += b[i];
		}
		else
		{
			if (val.empty()) continue;
			if (f[i] - sum < b[i])
			{
			 	if (val.top().first > b[i])
			 	{
			 		sum -= val.top().first;
			 		val.pop();
			 		val.push(ii(b[i], i));
			 		sum += b[i];
				}
			} 
			else
			{
				sum += b[i];
				val.push(ii(b[i], i));
			}
		}
		//cout << f[i] << " " << sum << endl;
	}
	vi save;
	while (!val.empty())
	{
		save.push_back(val.top().second);
		val.pop();
	}
	sort(save.begin(), save.end());
	cout << save.size() << endl;
	for (int i = 0; i < save.size(); i++) cout << save[i]+1 << " ";
 	cout << endl;
}
