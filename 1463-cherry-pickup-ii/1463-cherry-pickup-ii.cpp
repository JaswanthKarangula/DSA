class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        //dp[i][j][k]--number of ways//max cherries can collect  to reach row i col j and k 
        //dp(i,j,k)=max(dp(i-1,(3possible js,3possible ks  combination ) ))
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,INT_MIN)));
        int sum=0;
        if(m-1==0){
            sum=grid[0][0];
        }
        else{
            sum=grid[0][0]+grid[0][m-1];
            
        }
        dp[0][0][m-1]=sum;
        for(int i=1;i<n;++i){
            for(int j=0;j<m;++j){
                for(int k=0;k<m;++k){
                    int cell_sum=0;
                    if(j==k){
                       cell_sum=grid[i][j]; 
                    }
                    else{
                        cell_sum=grid[i][j]+grid[i][k];
                    }
                    int temp=INT_MIN;
                    for(int nj:{j,j+1,j-1}){
                        for(int nk:{k,k+1,k-1}){
                            if(nk<0 || nj<0 || nk>=m||nj>=m)continue;
                            temp=max(temp,dp[i-1][nj][nk]);
                        }
                    }
                    dp[i][k][j]=temp+cell_sum;
                }
            }
        }
        int res=0;
        for(int j=0;j<m;++j){
            for(int k=0;k<m;++k){
                res=max(res,dp[n-1][j][k]);
               // cout<<j<<"  "<<k<<"  "<<dp[n-1][j][k]<<endl;
            }
            
        }
        
        // [[0,8,7,10,9,10,0,9,6],
        //  [8,7,10,8,7,4,9,6,10],
        //  [8,1,1,5,1,5,5,1,2],
        //  [9,4,10,8,8,1,9,5,0],
        //  [4,3,6,10,9,2,4,8,10],
        //  [7,3,2,8,3,3,5,9,8],
        //  [1,2,6,5,6,2,0,10,0]]
        return res;
    }
};