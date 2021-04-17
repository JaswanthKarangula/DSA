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
    int n=0,m;
    cin>>n;
    vi a(n);
    int sum=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(a[i]%2)sum^=i;
    }
    if(sum==0)cout<<"Second";
    else cout<<"First";
    
    
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
