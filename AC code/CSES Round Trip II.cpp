#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
 
using namespace std;
 
const int MAXN=1e5+1;
 
int n,m;
stack<int> s;
vector<int> g[MAXN];
vector<int> vis(MAXN);

void dfs(int now){
    s.push(now);
    vis[now]=1;
    for(auto i:g[now]){
        if(vis[i]==1){
            vector<int> ans;
            while(s.top()!=i){
                ans.emplace_back(s.top());
                s.pop();
            }
            ans.emplace_back(i);
            reverse(ans.begin(),ans.end());
            ans.emplace_back(i);
            cout<<ans.size()<<'\n';
            for(auto j:ans) cout<<j<<" ";
            exit(0);
        }
        if(vis[i]==0) dfs(i);
    }
    s.pop();
    vis[now]=2;
}
 
signed main(){
    fastio
 
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v;cin>>u>>v;
        g[u].emplace_back(v);
    }
 
    for(int i=1;i<=n;++i) if(!vis[i]) dfs(i);
 
    cout<<"IMPOSSIBLE\n";
}
