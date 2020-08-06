#include<bits/stdc++.h>
using namespace std;
vector<int>buildLPS(string &pattern)
{
    int size=pattern.size();
    vector<int>lps(size);
    lps[0]=0;
   int i=1,j=0;
   while(i<size&&j<size)
   {
         if(j!=0&&pattern[i]!=pattern[j])
       {
           while(j!=0&&pattern[i]!=pattern[j])
           {
              j=lps[j-1];

           }
       }
       if(pattern[i]==pattern[j])
       {
           lps[i]=j+1;
           i++;
           j++;
       }
       else if((j==0)&&(pattern[i]!=pattern[j]))
       {
           lps[i]=0;
           i++;
       }
      
       
   }
   return lps;

}
vector<int>KMP(vector<int>&lps,string&pattern,string &text)
{
    int i=0,j=0;
    int size=text.size();
    
    vector<int>ans;
    while(i<size)
    {
         
        if(text[i]==pattern[j])
        {
            i++;
            j++;

        }
        if(j==pattern.size())
        {
        
              ans.push_back(i-j);
              j=lps[j-1];
        }
       
        else if(i<size&&pattern[j]!=text[i])
        {
             if(j!=0)
             {
                 j=lps[j-1];
             }
             else
             {
                 i++;
             }
             
        }
        
    }
    return ans;
}
vector<int> sol(string &text,string &pattern)
{
    vector<int>LPS=buildLPS(pattern);
    // for(int i=0;i<LPS.size();i++)
    // {
    //     cout<<LPS[i]<<" ";
    // }
    vector<int>indices=KMP(LPS,pattern,text);
    return indices;
}
int main()
{
    string pattern,text;
    cin>>text>>pattern;
    vector<int>ans=sol(text,pattern); //ans will contain all indices where the pattern occurred in the string 
    // COUT<ANS.SIZE()
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}