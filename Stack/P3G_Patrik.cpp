#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define hei first
#define cnt second
#define maxN 500005
#define inf (int) (1e9+7)
using namespace std;

int n, x;
stack <ii> st;
ll ans = 0LL;

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false);
	cin >> n;
	cin >> x;
	st.push(make_pair(x, 1));
	for (int i = 2; i <= n; i++)
	{
		cin >> x;
		bool flag = false;
		while(!st.empty())
		{
			if (x < st.top().hei) 
			{
				ans++;
				st.push(make_pair(x, 1));
				flag = true;
				break;
			}
			if (x == st.top().hei)
			{
				ans += st.top().cnt;
				if (st.size() >= 2) ans++;
				st.top().cnt++;
				flag = true;
				break;
			} 
			if (x > st.top().hei)
			{
				ans += st.top().cnt;
				st.pop();
			}
		}
		if (!flag) st.push(make_pair(x, 1));
		//cout << ans << endl;
	}
	printf("%lld\n", ans);
}
