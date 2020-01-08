#include <bits/stdc++.h>
#define ii pair <int, int>
using namespace std;

map <int, int> mp;
int n, m, k, a;
int num;

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k >> a;
	int num = n/(a+1);
	if (n % (a+1) == a) num++;
	mp[1] = n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int pos;
		cin >> pos;
	 	map <int, int> :: iterator it = mp.upper_bound(pos);
	 	it--;
	 	int be = it -> first;
	 	int en = it -> second;
	 	num -= ((en - be+1) / (a + 1) + ((en - be+1) % (a + 1) == a));
	 	mp.erase(it);
	 	if (be != pos)
	 	{
	 		mp[be] = pos-1;
	 		num += ((pos - be) / (a + 1) + ((pos - be) % (a + 1) == a));
		}
		if (pos != en)
		{
			mp[pos+1] = en;
			num += ((en - pos) / (a + 1) + ((en - pos) % (a + 1) == a));
		}
		//cout << num << endl;
		if (num < k)
		{
			printf("%d\n", i+1);
			return 0;
		}
		//cout << mp.size() << endl;
	}
	printf("-1\n");
	return 0;
}
