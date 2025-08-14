#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;

void solve(){
	int n,h,m;
	cin>>n>>h>>m;
	vector<PII>a(n+10);
	for(int i=1;i<=n;i++){
		auto&[x,y]=a[i];
		cin>>x>>y;
	}
	vector<vector<int>>f(n+10,vector<int>(h+10,-1));//f[i][h] 打败完前i个消耗h且最大剩余w
	f[0][0]=m;
	int ans=0;
	for(int i=1;i<=n;i++){
		auto [H,W]=a[i];
		for(int j=0;j<=h;j++){
			//消耗h
			if(j-H>=0)f[i][j]=max(f[i][j],f[i-1][j-H]);
			//消耗w
			if(f[i-1][j]-W>=0)f[i][j]=max(f[i][j],f[i-1][j]-W);
			if(f[i][j]>=0)ans=i;
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
