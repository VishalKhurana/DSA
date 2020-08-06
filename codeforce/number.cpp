#include<bits/stdc++.h>
using namespace std;
string as="Ashishgup";
string fin="FastestFinger";
	bool isPrime(long long int n)
	{
		  if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
 
    if (n % 2 == 0 || n % 3 == 0) 
        {return false;} 
  
    for (int i = 5; i * i <= n; i = i + 6) 
	{
        if (n % i == 0 || n % (i + 2) == 0) 
            {return false; }
	}
  
    return true;
		
	}
string sol(long long int n)
{
    int odd_factors=0;
    int val=0;
    for(long long int i=3;i<=(n/2)+1;i++)
    {
        if(((i%2)!=0)&&(n%i==0))
        {
           
			if(isPrime(i))
			{
            odd_factors++;
			   val=i;
			}
            
        }
    }
    //cout<<odd_factors<<endl;
    if(odd_factors==0)
    {
        if(n==2)
        {
            return as;
        }
        return fin;
    }
    //cout<<odd_factors<<endl;
    if((odd_factors)%2==0)
    {
        return as;
    }
    if(odd_factors==1)
    {
        int d=n/val;
        if((d%2==0)&&(d!=2))
        {
            return as;
        }

    }
    return fin;
}
int main()
{
       ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    for(int p=0;p<t;p++)
    {
    long long int n;
    cin>>n;
    if(n==1)
    {
        cout<<fin<<endl;
        continue;
    }
    if(n%2!=0)
    {
    cout<<as<<endl; 
    }
    else
    {
        string ans=sol(n);
        cout<<ans<<endl;
    }
    
}
}