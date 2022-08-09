#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
 
using namespace std;

bool b;
int n,m;
int sz[400005]{},dsu[400005]{};

void init(){
    b=true;
    for(int i=1;i<=n*2;++i){
        dsu[i]=i;
        if(i<=n) sz[i]=1;
        else sz[i]=0;
    }
}

int findDSU(int a){
    if(dsu[a]!=a) dsu[a]=findDSU(dsu[a]);
    return dsu[a];
}

void unionDSU(int a,int b){
    a=findDSU(a);
    b=findDSU(b);
    if(a==b) return;
    if(sz[a]<sz[b]) swap(a,b);
    dsu[b]=a;
    sz[a]+=sz[b];
    sz[b]=0;
}

signed main(){
    fastio

    int T;cin>>T;
    while(T--){
        cin>>n>>m;
        if(m==0){
            cout<<n<<'\n';
            continue;
        }
        init();
        for(int i=1;i<=m;++i){
            int u,v;string s;cin>>u>>v>>s;
            if(s=="imposter"){
                unionDSU(n+u,v);
                unionDSU(u,n+v);
            }else{
                unionDSU(n+u,n+v);
                unionDSU(u,v);
            }
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            if(findDSU(n+i)==findDSU(i)){
                b=false;
                cout<<-1<<'\n';
                break;
            }else{
                ans+=max(sz[findDSU(n+i)],sz[findDSU(i)]);
                sz[findDSU(n+i)]=sz[findDSU(i)]=0;
            }
        }
        if(b) cout<<ans<<'\n';
    }
}
