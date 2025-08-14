#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	vector<PII>a(q+10);
	vector<vector<int>>dis(n+10,vector<int>(m+10,-1)),cnt(n+10,vector<int>(m+10));
	queue<PII>qu;
	for(int i=1;i<=q;i++){
		auto [x,y]=a[i];
		cin>>x>>y;
		dis[x][y]=0;
		qu.push({x,y});
	}
	int ans=0;
	while(qu.size()){
		auto [x,y]=qu.front();
		qu.pop();
		ans+=dis[x][y];
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<1||nx>n||ny<1||ny>m)continue;
			cnt[nx][ny]++;
			if(dis[nx][ny]==-1&&cnt[nx][ny]==2){
				dis[nx][ny]=dis[x][y]+1;
				qu.push({nx,ny});
			}
		}
	}
	cout<<ans<<endl;
	
	
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}
