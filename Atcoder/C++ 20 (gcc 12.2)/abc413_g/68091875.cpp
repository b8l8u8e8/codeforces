#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,1,0,-1,1,-1,1,-1};
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<PII>a(k+10);
	map<PII,int>mp;
	for(int i=1;i<=k;i++){
		cin>>a[i].first>>a[i].second;
		mp[a[i]]=i;
	}	
	vector<int>p(k+10);
	for(int i=1;i<=k+4;i++)p[i]=i;
	auto find=[&](auto find,int x)->int{
		if(p[x]!=x)p[x]=find(find,p[x]);
		return p[x];
	};
	auto merge=[&](int a,int b){
		int pa=find(find,a),pb=find(find,b);
		if(pa!=pb){
//			cout<<a<<" "<<b<<endl;
			p[pa]=pb;	
		}
	};
	for(int i=1;i<=k;i++){
		auto [x,y]=a[i];
		if(x==1)merge(i,k+1);
		if(x==n)merge(i,k+2);
		if(y==1)merge(i,k+3);
		if(y==m)merge(i,k+4);
		for(int j=0;j<8;j++){
			int nx=x+dx[j],ny=y+dy[j];
			if(nx<1||nx>n||ny<1||ny>m)continue;
			if(mp.count({nx,ny})){
				merge(i,mp[{nx,ny}]);
			}
		}
	}
	if(find(find,k+1)==find(find,k+2)||find(find,k+3)==find(find,k+4)||find(find,k+1)==find(find,k+3)||find(find,k+2)==find(find,k+4))cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}