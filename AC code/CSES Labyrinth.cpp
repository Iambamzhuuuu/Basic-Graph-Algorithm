#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
 
using namespace std;
 
const int MAXN=1005;
 
int n,m,cnt=0;
char g[MAXN][MAXN];
int vis[MAXN][MAXN];
queue<pair<int,int>> q;
int pre[MAXN][MAXN];
vector<int> v;
bool ans;
 
int nx[4]={0,0,1,-1};
int ny[4]={1,-1,0,0};
string steps="RLDU";
 
int valid(int xxx,int yyy){
	if(xxx>=n||xxx<0) return false;
	if(yyy>=m||yyy<0) return false;
	if(vis[xxx][yyy]) return false;
	if(g[xxx][yyy]=='#') return false;
	return true;
}
 
void BFS(int x,int y){
	vis[x][y]=true;
	q.push({x,y});
	while(!q.empty()){
		pair<int,int> now=q.front();
		q.pop();
		for(int i=0;i<4;++i){
			int xx=now.first+nx[i],yy=now.second+ny[i];
			if(valid(xx,yy)&&!vis[xx][yy]){
				//cout<<xx<<" "<<yy<<'\n';
				pre[xx][yy]=i;
				if(g[xx][yy]=='B') {ans=true;return;}
				vis[xx][yy]=true;
				q.push({xx,yy});
			}
		}
	}
}
 
signed main(){
	fastio
 
	cin>>n>>m;
	pair<int,int> end,begin;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) cin>>g[i][j];
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(g[i][j]=='A') {begin={i,j};BFS(i,j);}
			if(g[i][j]=='B') end={i,j};
		}
	}
	if(ans){
		cout<<"YES\n";
		while(end!=begin){
			cnt++;
			int p=pre[end.first][end.second];
			v.emplace_back(p);
			end={end.first-nx[p],end.second-ny[p]};
		}
		reverse(v.begin(),v.end());
		cout<<cnt<<'\n';
		for(auto i:v) cout<<steps[i];
	}
	else cout<<"NO\n";
}
