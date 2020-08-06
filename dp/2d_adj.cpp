    vector<vector<int>>dp(2,vector<int>(A.size()));
    dp[0][0]=A[0][0];
    dp[0][1]=max(dp[0][0],A[0][1]);
    for(int i=2;i<A[0].size();i++)
    {
        dp[0][i]=max(dp[0][i-1],A[0][i]+dp[0][i-2]);
        
    }
    dp[1][0]=max(dp[0][0],max(dp[0][1],A[1][0]));
    dp[1][1]=max(dp[1][0],max(dp[0][0],dp[0][1]));
    for(int i=2;i<A[0].size();i++)
    {
        dp[1][i]=max(dp[1][i-2],dp[0][i-2])+A[1][i];
        
    }
    int max_=INT_MIN;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
    
            max_=max(max_,dp[i][j]);
        }
       
    }
    return max_;