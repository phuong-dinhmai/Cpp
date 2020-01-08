#include <bits/stdc++.h>
using namespace std;

main(){
	
	int n;
	
	//freopen ("in.inp","r",stdin);
	while (cin>>n)
	{
		stack <int> test1;
		queue <int> test2;
		priority_queue <int> test3;
		bool kt1=1,kt2=1,kt3=1;
		for (int i=0; i<n; i++) 
		{
			int th,num;
			cin >> th >> num;
			if (th == 1)
			{
				test1.push(num);
				test2.push(num);
				test3.push(num);
			}
			else 
			{
				if (!test1.empty())
				{
					int x=test1.top();
					test1.pop();
					if (x == num && kt1) kt1=true; else kt1=false;
				}
				else kt1=false;
				if (!test2.empty())
				{
					int x=test2.front();
					test2.pop();
					if (x == num && kt2) kt2=true; else kt2=false;
				}
				else kt2=false;
				if (!test3.empty())
				{
					int x=test3.top();
					test3.pop();
					if (x == num && kt3) kt3=true; else kt3=false;
				} else kt3=false;
				//cout << kt1 << " " << kt2 << " " << kt3 << endl;
			}
		}
		if (kt1 && !kt2 && !kt3) cout << "stack" << endl;
		else if (!kt1 && kt2 && !kt3) cout << "queue" << endl;
		else if (!kt1 && !kt2 && kt3) cout << "priority queue" << endl;
		else if (!kt1 && !kt2 && !kt3) cout << "impossible" << endl;
		else cout << "not sure" << endl;
	}
}
