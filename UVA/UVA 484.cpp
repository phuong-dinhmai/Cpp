#include <bits/stdc++.h>
using namespace std;

main(){
	string s;
	int num;
	int n = 0;
	vector <int> a;
	map <int, int> mp;
	//freopen("out.out","w",stdout);
	while (cin >> num)
	{
		mp[num]++;
		a.push_back(num);
	}
	for (int i = 0; i < a.size(); i++)
		if (mp[a[i]] > 0) 
		{
			cout << a[i] << " " << mp[a[i]] << endl;
			mp[a[i]] = -1;
		}
}	
