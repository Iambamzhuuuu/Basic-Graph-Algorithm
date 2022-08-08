#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int m;
bool check;
vector<int> ans;
vector<bool> vis;
vector<vector<pair<int,int>>> g;

void init(){
	check=false;
	ans.clear();
	g.clear();g.resize(505);
	vis.clear();vis.resize(m);
	
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;
		g[u].emplace_back(make_pair(v,i));
		g[v].emplace_back(make_pair(u,i));
	}
}

void dfs(int now){
	sort(g[now].begin(),g[now].end());
	for(auto i:g[now]){
		int to=i.first,id=i.second;
		if(vis[id]) continue;
		vis[id]=true;
		dfs(to);
	}
	ans.emplace_back(now);
}

signed main(){
	fastio

	while(cin>>m){
		if(m==0) continue;
		for(int i=1;i<=500;++i){
			if(g[i].size()%2){
				dfs(i);
				check=true;
				break;
			}
		}
		if(!check) for(int i=1;i<=500;++i){
			if(g[i].size()){
				dfs(i);
				break;
			}
		}
		reverse(ans.begin(),ans.end());
		for(auto i:ans) cout<<i<<'\n';
                cout<<'\n';
	}
}
