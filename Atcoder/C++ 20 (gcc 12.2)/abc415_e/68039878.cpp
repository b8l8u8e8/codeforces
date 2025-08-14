#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;

void solve(){
	int n,m;
	cin>>n>>m;
	vector a(n+10,vector<int>(m+10));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	vector<int>b(n+m+10);
	for(int i=1,x;i<=n+m-1;i++){
		cin>>b[i];
	}
	vector f(n+10,vector<int>(m+10,1e18));
	f[n][m]=0;
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			f[i][j]=min(f[i][j],f[i+1][j]);
			f[i][j]=min(f[i][j],f[i][j+1]);
			f[i][j]=max(f[i][j]-(a[i][j]-b[i+j-1]),0ll);
		}
	}
	cout<<f[1][1]<<endl;
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}