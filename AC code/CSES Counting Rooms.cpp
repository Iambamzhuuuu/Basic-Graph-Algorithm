#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
 
using namespace std;
 
const int MAXN=1005;
 
int nx[4]={0,0,1,-1};
int ny[4]={1,-1,0,0};
int n,m;
char g[MAXN][MAXN];
int vis[MAXN][MAXN];
 
int valid(int xxx,int yyy){
	if(xxx>=n||xxx<0) return false;
	if(yyy>=m||yyy<0) return false;
	if(vis[xxx][yyy]) return false;
	if(g[xxx][yyy]=='#') return false;
	return true;
}
 
void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;++i){
		int xx=x+nx[i],yy=y+ny[i];
		if(valid(xx,yy)) dfs(xx,yy);
	}
}
 
signed main(){
	fastio
 
	cin>>n>>m;
	int ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) cin>>g[i][j];
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(g[i][j]=='.'&&vis[i][j]==0){
				dfs(i,j);ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
