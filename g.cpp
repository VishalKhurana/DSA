class Solution {
public:
    void computeLPS(vector<int>&lps,string pattern,int size)
    {
        int i=0;
        int j=1;
        while(i<size&&j<size)
        {
            if(i!=0&&pattern[i]!=pattern[j])
            {
            while(i!=0&&pattern[i]!=pattern[j])
            {
                i=lps[i-1];
            }
            }
        
        if(i==0&&pattern[i]!=pattern[j])
        {
            lps[j]=0;
            j++;
        }
        else if(pattern[i]==pattern[j])
        {
            lps[j]=i+1;
            j++;
            i++;
        }
        }
    }
    bool KMP(string str,string pattern,vector<int>&lps)
    {
      int i=0;
        int j=0;
        while(i<str.size())
        {
            if(pattern[j]==str[i])
            {
                i++;
                j++;
            }
            if(j==pattern.size())
            {
                return true;
            }
            else if(i<str.size()&&pattern[j]!=str[i])
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
        return false;
    }
    bool rotateString(string A, string B) {
        if(A.size()==0&&B.size()==0)
        {
            return true;
        }
        if(A.size()!=B.size())
        {
            return false;
        }
        string A1=A.append(A);
        cout<<A1<<endl;
        int size=B.size();
        vector<int>lps(size,0);
        computeLPS(lps,B,size);
        cout<<lps[0]<<endl;
        bool ans=KMP(A1,B,lps);
        return ans;
        
    }
};