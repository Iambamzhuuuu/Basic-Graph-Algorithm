#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
 
using namespace std;
 
const int MAXN=1e5+5;
const int MOD=1e9+7;
 
int n,m;
vector<int> g[MAXN];
vector<int> deg(MAXN),ans(MAXN);
queue<int> q;
 
signed main(){
	fastio
 
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;
		g[u].emplace_back(v);
		deg[v]++;
	}
	int k;
	for(int i=1;i<=n;++i){
		if(deg[i]==0) q.push(i);
	}
	ans[1]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(auto i:g[now]){
			ans[i]+=ans[now];
			ans[i]%=MOD;
			deg[i]--;
			if(deg[i]==0) q.push(i);
		}
	}
	cout<<ans[n]<<'\n';
}
