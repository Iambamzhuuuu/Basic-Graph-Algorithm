#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

string a,b;
bool bb=true;
vector<int> v[26];
vector<int> in(26,0);
vector<int> ans;

int r=0;

void build(string a,string b){
	r=0;
	while(r<a.size()&&r<b.size()){
		if(a[r]!=b[r]){
			v[a[r]-'a'].emplace_back(b[r]-'a');
			in[b[r]-'a']++;
			return;
		}
		r++;
	}
	if(b.size()<a.size()) bb=false;
}

signed main(){
	fastio

	int n;cin>>n;
	cin>>a;
	for(int i=1;i<n;++i){
		cin>>b;
		build(a,b);
		a=b;
	}
	if(!bb){
		cout<<"Impossible\n";
		return 0;
	}
	queue<int> q;
	for(int i=0;i<26;++i){
		if(in[i]==0) q.push(i);
	}
	while(!q.empty()){
		int now=q.front();
		ans.emplace_back(now);
		q.pop();
		for(auto i:v[now]){
			in[i]--;
			if(in[i]==0) q.push(i);
		}
	}
	if(ans.size()!=26) cout<<"Impossible\n";
	else{
		for(auto i:ans) cout<<char('a'+i);
		cout<<'\n';
	}
}
