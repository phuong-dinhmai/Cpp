#include<iostream>
#include<cmath>
#include<cstring>
//-----------
unsigned long long gt(unsigned long long n){
	if (n<2) return 1; else return gt(n-1)*n;
}
//-----------
using namespace std;
int main()
{
	unsigned long long a,n;
	string dpt;
	while(cin>>a>>n)
	{
	    cin>>dpt;
		if (dpt=="On")
			{if (n<=a) cout<<"AC"<<endl; else cout<<"TLE"<<endl;}
		if (dpt=="Onlogn") 
			{if ((n*log2(n)<=a) && (n<=40000000)) cout<<"AC"<<endl; else cout<<"TLE"<<endl;}
		if(dpt=="On^(3/2)") 
			{if((n*sqrt(n)<=a) && (n<=1000000)) cout<<"AC"<<endl; else cout<<"TLE"<<endl;}
		if(dpt=="On^2") 
			{if ((n*n<=a) && (n<=31622)) cout<<"AC"<<endl; else cout<<"TLE"<<endl;}
		if(dpt=="On^2logn") 
			{if ((n*n*log2(n)<=a) && (n<=8739)) cout<<"AC"<<endl; else cout<<"TLE"<<endl;}
		if(dpt=="On^3") 
			{if ((n*n*n<=a) && (n<=1000)) cout<<"AC"<<endl; else cout<<"TLE"<<endl;}
		if(dpt=="On^4") 
			{if ((n*n*n*n<=a) && (n<=177)) cout<<"AC"<<endl; else cout<<"TLE"<<endl;}
		if(dpt=="O2^n") 
			{if ((pow(2,n)<=a) && (n<=29)) cout<<"AC"<<endl; else cout<<"TLE"<<endl;}
		if(dpt=="On!") 
			{if ((n<=12) && (gt(n)<=a)) cout<<"AC"<<endl; else cout<<"TLE"<<endl;}
	}
}
