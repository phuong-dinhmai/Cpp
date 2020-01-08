#include <bits/stdc++.h>
using namespace std;

	stack <int > sta,ans;
	int n; 

void xuly()
{
		for (;;)
		{ 
			int check=0;
			while (sta.size() > 0) sta.pop(); 
			while (ans.size() > 0) ans.pop();
			for (int i=0; i<n; i++) 
			{
				int x;
				cin>>x;
				if (x == 0) return;
				ans.push(x);
			}
			for (int i=n; i>=1; )
			{
				if (!sta.empty() && sta.top() == i)
				{
					i--;
					sta.pop();
					continue;
				}
				if (ans.empty()) break;
				if (ans.top() != i) sta.push(ans.top()); else i--;
				ans.pop();
			}
			//cout << sta.size() << " " << ans.size() << endl;
			if (sta.empty() && ans.empty()) cout << "Yes" << endl; else cout << "No" << endl;
		}
}

main(){
	
	freopen ("in.inp","r",stdin);
	for (;;) 
	{
		cin>>n;
		if (n == 0) return 0;
		xuly();
		cout<<endl;
	}
}
