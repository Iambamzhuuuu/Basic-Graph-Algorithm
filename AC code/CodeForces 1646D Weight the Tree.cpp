#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
#define F first
#define S second

using namespace std;

const int MAXN=2e5+5;

int n;
vector<int> g[MAXN];

// 0 -> bad  1-> gud
// first -> gud vertices   second -> min sum
pair<int,int> dp[2][MAXN]{};
//roll back
vector<int> k[MAXN]{};

pair<int,int> add(pair<int,int> a,pair<int,int> b){
    return {a.first+b.first,a.second+b.second};
}

void dfs(int a,int p){
    dp[0][a]={0,-1};
    dp[1][a]={1,-(int)g[a].size()};
    for(auto i:g[a]){
        if(i!=p){
            dfs(i,a);
            dp[0][a]=add(dp[0][a],max(dp[0][i],dp[1][i]));
            dp[1][a]=add(dp[1][a],dp[0][i]);
            if(dp[0][i]>dp[1][i]) k[a].emplace_back(0);
            else k[a].emplace_back(1);
        }
    }
}

vector<int> rollback(MAXN);

void findans(int a,int p,int tmp){
    if(tmp==0) rollback[a]=1;
    else rollback[a]=g[a].size();
    int cnt=0;
    for(auto i:g[a]){
        if(i!=p){
            if(tmp==0) findans(i,a,k[a][cnt++]);
            else findans(i,a,0);
        }
    }
}

signed main(){
    fastio

    cin>>n;
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    if(n==2) return cout<<2<<" "<<2<<'\n'<<1<<" "<<1<<'\n',0;

    dfs(1,-1);
    if(dp[0][1]>dp[1][1]) findans(1,-1,0);
    else findans(1,-1,1);

    pair<int,int> ans=max(dp[0][1],dp[1][1]);
    cout<<ans.F<<" "<<-ans.S<<'\n';
    for(int i=1;i<=n;++i){
        cout<<rollback[i]<<" ";
    }
    cout<<'\n';
}
