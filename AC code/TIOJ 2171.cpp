#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
 
using namespace std;

int a,b,s,m,k;
vector<int> g[1001];

int cnt=0,ans=0;
vector<bool> vis(1001);

void dfs(int a){
    if(g[a].size()%2) cnt++;
    vis[a]=true;
    for(auto i:g[a]){
        if(!vis[i]) dfs(i);
    }
}

signed main(){
    fastio
 
    cin>>a>>b>>s>>m>>k;
    for(int i=1;i<=k;++i){
        int u,v,w;cin>>u>>v>>w;
        g[u].emplace_back(v+a);
        g[v+a].emplace_back(u);
    }

    for(int i=1;i<=a+b;++i){
        if(!vis[i]&&g[i].size()!=0){
            dfs(i);
            ans+=max(cnt/2,1);
        }
        cnt=0;
    }

    cout<<ans<<'\n';
}
