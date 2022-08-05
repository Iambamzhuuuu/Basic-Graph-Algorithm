#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
 
using namespace std;

const int MAXN=1e5+1;
const int INF=1e5+1;

vector<int> dis(MAXN,INF);
vector<pair<int,int>> g[MAXN];
 
signed main(){
    fastio
 
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v;cin>>u>>v;
        g[u].emplace_back(make_pair(v,0));
        g[v].emplace_back(make_pair(u,1));
    }
    dis[1]=0;
    deque<int> dq;
    dq.push_front(1);
    while(!dq.empty()){
        int now=dq.front();
        dq.pop_front();
        for(auto i:g[now]){
            int v=i.first,w=i.second;
            if(dis[now]+w<dis[v]){
                dis[v]=dis[now]+w;
                if(w==1) dq.push_back(v);
                else dq.push_front(v);
            }
        }
    }
    if(dis[n]==INF) cout<<-1<<'\n';
    else cout<<dis[n]<<'\n';
}
