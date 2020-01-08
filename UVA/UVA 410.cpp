#include <bits/stdc++.h>
using namespace std;

main(){
	vector <int> a;
	freopen ("in.inp","r",stdin);
	long long n,m,dem=0,k,x=0, sum1;
	double sum=0,ans=0;
	while (cin>>n>>m)
	{
	a.clear();
	sum1=0;
	ans=0;
	k=0;
	for (int i=0;i<m;i++) 
	{
		int r;
		cin>>r;
		sum1=sum1+r;
		a.push_back(r);
	}
	dem++;
	cout<<"Set #"<<dem<<endl;
	sum=(double)sum1/n;
	while (a.size()<2*n) {a.push_back(0); k++;}
	sort(a.begin(),a.end());
	for (int i=0;i<n;++i)
	{
		cout<<" "<<i<<": ";
		if (a[i]!=0)
		{
			cout<<a[i]<<" "<<a[a.size()-1-i]<<endl;
		}
		else 
		if (a[a.size()-1-i]!=0) cout<<a[a.size()-1-i]<<endl;
			else cout<<endl;
		double  x=abs((double)((a[i]+a[a.size()-1-i]))-sum);
		ans=ans+x;
	}
	printf("IMBALANCE = %.5lf\n\n",ans);
	}
	return 0;
}

