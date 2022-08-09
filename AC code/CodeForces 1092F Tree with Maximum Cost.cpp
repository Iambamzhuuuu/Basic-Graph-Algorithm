#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
 
using namespace std;

const int MAXN=2e5+5;

long long ans=0,now=0;
vector<int> v(MAXN),g[MAXN];
vector<long long> dp(MAXN,0);

void dfs1(int u,int p,long long d){
    now+=d*v[u];
    dp[u]=v[u];
    for(auto i:g[u]){
        if(i!=p){
            dfs1(i,u,d+1);
            dp[u]+=dp[i];
        }
    }
}

void dfs2(int u,int p){
    ans=max(ans,now);
    for(auto i:g[u]){
        if(i!=p){
            now-=dp[i];
            dp[u]-=dp[i];
            now+=dp[u];
            dp[i]+=dp[u];
            dfs2(i,u);
            dp[i]-=dp[u];
            now-=dp[u];
            dp[u]+=dp[i];
            now+=dp[i];
        }
    }
}

signed main(){
    fastio
 
    int n;cin>>n;
    
    for(int i=1;i<=n;++i) cin>>v[i];
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs1(1,-1,0);
    dfs2(1,-1);

    cout<<ans<<'\n';
}
