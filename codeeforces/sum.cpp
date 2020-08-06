#include<bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		
		int arr[n];
		for(int i=0;i<n;i++)
		 cin>>arr[i];
		
		int sum=0;
		for(int i=0;i<n;i++)
			{
				sum+=arr[i];
			}
		
	int right=sum;
	int left=sum;
	int ans1=-1;
	int ans2=-1;
		for(int i=0;i<n;i++)
		{
			if(right%x)
			{
				ans1=n-i;
				break;
			}
			
			right-=arr[i];
		
		}
//		cout<<ans1<<endl;
		for(int i=n-1;i>=0;i--)
		{
//			cout<<left<<endl;
			if(left%x)
			{
				ans2=n-(n-i-1);
				break;
			}
//			cout<<"the left"<<ans2<<endl;
			left-=arr[i];
		
		}
		
		cout<<max(ans1,ans2)<<endl;
		
		
			
	
		 
	
	}
}