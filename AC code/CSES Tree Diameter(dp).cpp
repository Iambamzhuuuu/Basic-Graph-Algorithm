#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
const int MAXN=2e5+1;

int dp[MAXN],ans=0;
vector<int> g[MAXN];

void dfs(int u,int p){
    int mx=0,smx=0;
    for(auto& i:g[u]){
        if(i==p) continue;
        dfs(i,u);
        if(dp[i]>mx) smx=mx,mx=dp[i];
        else if(dp[i]>smx) smx=dp[i];
    }
    dp[u]=mx+1;
    ans=max(ans,mx+smx);
}
 
signed main(){
    fastio

    int n;cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs(1,1);
 
    cout<<ans<<'\n';
}
