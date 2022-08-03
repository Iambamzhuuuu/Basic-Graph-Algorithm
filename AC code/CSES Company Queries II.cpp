#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
 
using namespace std;
 
const int MAXN=2e5;
 
int n,q;
vector<vector<int>> g;
vector<int> in(MAXN),out(MAXN);
vector<vector<int>> v;
int t=0;
 
void dfs(int now,int p){
	v[0][now]=p;
	in[now]=t++;
	for(auto i:g[now]){
		if(i==p) continue;
		dfs(i,now);
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
	g.resize(n+1);
	v.resize(20,vector<int>(n+1));
	for(int i=2;i<n+1;++i){
		int u;cin>>u;
		g[u].emplace_back(i);
	}
	dfs(1,1);
	for(int i=1;i<20;++i){
		for(int j=1;j<=n;++j) v[i][j]=v[i-1][v[i-1][j]];
	}
	while(q--){
		int u,v;cin>>u>>v;
		cout<<lca(u,v)<<'\n';
	}
}
