#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
using namespace std;

const int MAXN=1e5+5;

int n;
vector<vector<int>> g(MAXN);
vector<pair<int,int>> v;

// dp1 -> l   dp2 -> r  
vector<int> dp1(MAXN,0),dp2(MAXN,0);

void init(){
    cin>>n;
    v.clear();g.clear();
    g.resize(n+1);
    v.emplace_back(make_pair(0,0));
    for(int i=1;i<=n;++i){
        int l,r;cin>>l>>r;
        v.emplace_back(make_pair(l,r));
    }
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
}

void dfs(int a,int p){
    dp1[a]=dp2[a]=0;
    for(auto i:g[a]){
        if(i!=p){
            dfs(i,a);
            dp1[a]+=max(dp1[i]+abs(v[i].first-v[a].first),dp2[i]+abs(v[i].second-v[a].first));
            dp2[a]+=max(dp1[i]+abs(v[i].first-v[a].second),dp2[i]+abs(v[i].second-v[a].second));
        }
    }
}

void solve(){
    init();
    
    dfs(1,-1);
    cout<<max(dp1[1],dp2[1])<<'\n';
}

signed main(){
    fastio

    int T;cin>>T;
    while(T--){
        solve();
    }
}
