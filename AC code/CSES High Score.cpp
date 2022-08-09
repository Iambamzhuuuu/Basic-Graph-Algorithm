#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
 
using namespace std;
 
const long long INF=1e18;
 
struct edge{
    int a,b;
    long long c;
};
 
signed main(){
    fastio
 
    int n,m;cin>>n>>m;
    vector<edge> edges(m);
    vector<long long> dis(n+1,-INF);
    for(int i=0;i<m;++i){
        cin>>edges[i].a>>edges[i].b>>edges[i].c;
    }
    dis[1]=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(dis[edges[j].a]==-INF) continue;
            dis[edges[j].b]=max(dis[edges[j].b],dis[edges[j].a]+edges[j].c);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
           if(dis[edges[j].a]==-INF) continue;
           if(dis[edges[j].b]<(dis[edges[j].a]+edges[j].c)) dis[edges[j].b]=INF;
        }
    }
    if(dis[n]==INF) cout<<"-1"<<'\n';
    else cout<<dis[n]<<'\n';
}
