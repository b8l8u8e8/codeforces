#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<PII>>g(n+10,vector<PII>({}));
	for(int i=1,b,c,v;i<=m;i++){
		cin>>b>>c>>v;
		g[b].push_back({c,v});
	}
	queue<PII>q;
	vector<vector<int>>st(n+10,vector<int>(1025));
	q.push({1,0});
	int ans=1e12;
	while(q.size()){
		auto [x,y]=q.front();
		q.pop();
		if(st[x][y])continue;
		st[x][y]=1;
		if(x==n)ans=min(ans,y);
		for(auto [a,b]:g[x]){
			q.push({a,b^y});
		}
	}
	cout<<(ans==1e12?-1:ans)<<endl;
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}