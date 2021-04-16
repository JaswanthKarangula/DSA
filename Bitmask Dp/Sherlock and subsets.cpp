#include<bits/stdc++.h>
using namespace std;
#define int                long long
#define x                  first
#define y                  second
#define pb                 push_back
#define all(x)             (x).begin(),(x).end()
#define pii                pair<int,int>
#define FOR(i, a, b)       for (int i=a; i<(b); i++)
#define F0R(i, a)          for (int i=0; i<(a); i++)
#define FORd(i,a,b)        for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a)          for (int i = (a)-1; i >= 0; i--)
typedef vector< int >      vi;
typedef vector< long long> vll;
const long long INF=1e18;
const int32_t MOD=998244353;


void solve(){
     int n;
     cin>>n;
     vi a(n),v(n);
     for(int i=0;i<n;++i)cin>>a[i];
      vector<int> x = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
        
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=0;j<15;j++)
            {
                if(a[i]%x[j]==0)
                {
                    temp |= (1ll<<j);
                }
            }
            v[i]=temp;
            //cout<<v[i]<<"   ";
            }
         vector<vi> dp(n,vi((1<<15),0));
//         //dp[i][mask]---maximum subset size that we can form using only primes set in mask 
    for(int i=0;i<n;++i)
    dp[i][v[i]]=1;
    int res=1;
    for(int i=1;i<n;++i){
        for(int mask=0;mask<(1ll<<15);++mask){
            dp[i][mask]=max(dp[i-1][mask],dp[i][mask]);
            if(((mask^v[i])&v[i])==0)
            dp[i][mask]=max(dp[i][mask],dp[i-1][mask^v[i]]+1);
          // res=max(res,dp[i][mask]);
        }
    }
    for(int mask=0;mask<(1<<15);++mask){
        res=max(res,dp[n-1][mask]);
    }
    
     cout<<res;
}
signed  main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int t=1;
    
    cin>>t;
    
    while(t){
        
        solve();
        cout<<endl;
        t--;
    }
    return 0;
}

