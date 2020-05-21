#include<bits/stdc++.h>
using namespace std;
#define ll long long

// SAME CODE FOR PAINTER PARTIION PROBLEM
bool possible(ll a[],ll n,ll students,ll d)
{
	ll s=1;
	ll cnt=0;
	for(ll i=0;i<n;i++)
	{
		if(a[i]>d)
		{
			return false;
		}
		if(a[i]+cnt>d)
		{
			
			s++;
			cnt=a[i];
			
			if(s>students) return false;
		}
		else
		{
			cnt+=a[i];
		}
	}
	return true;
}






ll solve(ll a[],ll n,ll students)
{
	if(n<students) return -1;
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		sum+=a[i];
	}
	ll left=0;
	ll right=sum;
	ll res=INT_MAX;
	while(left<=right)
	{
		ll mid=left+(right-left)/2;
		if(possible(a,n,students,mid))
		{
			res=min(res,mid);
			right=mid-1;
		}
		else
		{
			left=mid+1;
		}
	}
	return res;
}





int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++) cin>>a[i];
		ll students;
		cin>>students;
		cout<<solve(a,n,students)<<endl;
	}
	return 0;
}
