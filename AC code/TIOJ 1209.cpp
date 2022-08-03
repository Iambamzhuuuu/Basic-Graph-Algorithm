#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

const int MAXN=5e5+5;

vector<vector<int>> g;
vector<int> color;
bool ans;

void dfs(int now,int c){
	color[now]=c;
	for(auto i:g[now]){
		if(color[i]==-1) dfs(i,!c);
		if(color[i]==c) ans=false ;
	}
}

signed main(){
	fastio

	int n,m;
	while(cin>>n>>m){
		if(n==0&&m==0) break;
		ans=true;
		g.clear();g.resize(n+1);
		color.clear();color.resize(n+1,-1);

		for(int i=0;i<m;++i){
			int u,v;cin>>u>>v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		for(int i=1;i<=n;++i){
			if(color[i]==-1)dfs(i,0);
		}
		if(ans) cout<<"Yes\n";
		else cout<<"No\n";
	}

}
