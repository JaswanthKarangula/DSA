class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int MOD=1e9+7;
        int n=hats.size();
        int m=41;
        vector<vector<int>> dp(m,vector<int>((1<<n),0));
        vector<vector<int>> possible_persons(m);
        for(int i=0;i<n;++i){
            for(auto j:hats[i]){
                possible_persons[j].push_back(i);
            }
        }
        
        for(int j=0;j<m;++j)
             dp[j][0]=1;
        
        for(int i=1;i<m;++i){
            for(int mask=0;mask<(1<<n);++mask){
                dp[i][mask]=dp[i-1][mask];
                for(int person:possible_persons[i]){
                    if(mask&(1<<person)){
                        dp[i][mask]=dp[i][mask]+dp[i-1][mask^(1<<person)];
                        dp[i][mask]=dp[i][mask]%MOD;
                    }
                }
            }
        }
        return dp[m-1][(1<<n)-1];
    }
};
//https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/
