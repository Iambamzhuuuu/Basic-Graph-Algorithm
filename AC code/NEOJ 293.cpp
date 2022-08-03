#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

const int MAXN=1e5+1;

vector<int> g[MAXN];
int ans,n;

int dfs(int now,int p){
    int cnt=0,b=1;
    for(auto& i:g[now]){
        if(i==p) continue;
        int r=dfs(i,now);
        if(r>n/2) b=0;
        cnt+=r;
    }
    if((n-1-cnt)>n/2) b=0;
    if(b) ans=min(ans,now);
    return cnt+1;
}

signed main(){
    fastio

    int t;cin>>t;
    while(t--){
        cin>>n;
        fill(g,g+MAXN,vector<int>());
        for(int i=0;i<n-1;++i){
            int u,v;cin>>u>>v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        ans=MAXN;
        dfs(0,0);
        cout<<ans<<'\n';
    }
}
