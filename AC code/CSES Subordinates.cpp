#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
 
#pragma GCC optimize("Ofast")
using namespace std;
 
const int MAXN=2e5+5;
 
int dp[MAXN]{};
vector<int> g[MAXN];
 
void dfs(int v){
    for(auto i:g[v]){
        dfs(i);
        dp[v]+=dp[i];
        dp[v]++;
    }
}
 
signed main() {
    fastio
 
    int n;cin>>n;
    for(int i=2;i<=n;++i){
        int p;cin>>p;
        g[p].emplace_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;++i) cout<<dp[i]<<" ";
    cout<<'\n';
}
