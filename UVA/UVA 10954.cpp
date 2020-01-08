#include <bits/stdc++.h>
using namespace std;

main(){
	 
	 priority_queue <int, vector <int>, greater <int> > ans;
	//freopen ("in.inp","r",stdin);
	for (;;)
	{
		long long sum=0,n;
		cin>>n;
		if (n == 0) return 0;
		for (int i=0; i<n; i++) 
		{
			int x;
			cin >> x;
			ans.push(x);
		}
		sum = 0;
		while (ans.size() > 1)
		{
			int x,y;
			x=ans.top();
			ans.pop();
			y=ans.top();
			ans.pop();
			sum+=(x+y);
			ans.push(x+y);
		}
		ans.pop();
		cout << sum << endl;
	}
}
