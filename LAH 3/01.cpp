#include <iostream>
using namespace std;
int a[21],n,t;
long long ans=0;
//------------------------
void track(int i)
{
	if (i==n)
	{
		long long dem1=0, dem2=0;
		for (int j=1;j<n-1;j++)
		{
			if (a[j-1]>a[j] && a[j]<a[j+1]) dem1++;
			if (a[j-1]<a[j] && a[j]>a[j+1]) dem2++;
		}
		if (dem1==t && dem2==t+1) ans++;
	}
	else 
	for (int j=1;j<5;j++)
	{
		a[i]=j;
		if (i!=0)
			{if (a[i-1]!=a[i]) track(i+1);}
		else track(i+1);
	}
	
}
//------------------------
main(){
	while (cin>>n>>t){
	if (2*t>=n) cout<<0<<endl; else{
	ans=0;
	t--;
	track(0);
	cout<<ans<<endl;}
}
}
