class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n=jobs.size();
        vector<vector<int>> dp((1<<n),vector<int>(k,0));
        vector<int> result((1<<n),0);
         for(int i = 0;i<(1<<n);i++)    
        {
            for(int j = 0;j<n;j++)
            {
                if(((1<<j)&i))
                {
                    result[i] += jobs[j];
                }
            }
        }
        for (int i = 0; i < (1<<n); ++i) {
            dp[i][0] = result[i];
        }
        
        for(int i=1;i<k;++i){
            for(int mask=0;mask<(1<<n);++mask){
                dp[mask][i]=dp[mask][i-1];
                for(int submask=mask;submask;submask=(submask-1)&mask){
                    dp[mask][i]=min(dp[mask][i],max(result[submask],dp[mask^submask][i-1]));
                }
                //cout<<dp[mask][i]<<"   ";
                    
            }
           // cout<<endl;
        }
        
        return dp[(1<<n)-1][k-1];
        
    }
};
