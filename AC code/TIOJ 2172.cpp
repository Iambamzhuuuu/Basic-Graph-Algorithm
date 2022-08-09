#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
 
using namespace std;
 
const int MAXN=2e5+5;
 
int n,q;
vector<vector<int>> g(MAXN);
vector<int> in(MAXN),out(MAXN);
vector<vector<int>> v(20,vector<int>(MAXN));
vector<int> dpt(MAXN);
int t=0;
 
void dfs(int now,int p,int d){
    v[0][now]=p;
    in[now]=t++;
    dpt[now]=d;
    for(auto i:g[now]){
        if(i==p) continue;
        dfs(i,now,d+1);
    }
    out[now]=t++;
}
 
bool valid(int a,int b){
    return in[a]<=in[b]&&out[a]>=out[b];
}
 
int lca(int a,int b){
    if(valid(a,b)) return a;
    for(int i=19;i>=0;--i){
        if(!valid(v[i][a],b)) a=v[i][a];
    }
    return v[0][a];
}
 
signed main(){
    fastio
 
    cin>>n>>q;
    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(0,0,0);
    for(int i=1;i<20;++i){
        for(int j=0;j<n;++j) v[i][j]=v[i-1][v[i-1][j]];
    }
    while(q--){
        int u,v;cin>>u>>v;
        int dd=lca(u,v);
        cout<<dpt[u]+dpt[v]-2*dpt[dd]<<'\n';
    }
}
