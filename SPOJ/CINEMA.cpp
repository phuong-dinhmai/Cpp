#include <iostream>
using namespace std;
main(){
	long long n,m,k,s;
	int a[10000]={0}, b[1000]={0};
	cin>>n>>m>>k;
	for (int i=0;i<k;i++) cin>>a[i];
	s=0;
	for (int i=0;i<n;i++)
		{
			if (i%2==0)
			{
				for (int j=0;j<m;j++)
				{
					if (a[s]!=0) {cout<<s+1<<" ", a[s]--;} 
					else {if (s<k-1) {s++; cout<<s+1<<" "; a[s]--;} else cout<<0<<" ";}
				}
				cout<<endl;
			}
			else 
			{
				for (int j=0;j<m;j++)
				{
					if (a[s]!=0) {b[j]=s+1; a[s]--;} 
					else {if (s<k-1) {s++; ;b[j]=s+1; a[s]--;} else b[j]=0;}
				}
				for (int j=m-1;j>=0;j--) cout<<b[j]<<" ";
				cout<<endl;
			}
		}
		
} 
