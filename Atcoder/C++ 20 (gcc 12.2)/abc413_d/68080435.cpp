#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
int mod=998244353;
void solve(){
	int n;
	cin>>n;
	int ans=0;
	for(int i=2;i<=n;i++){
		int r=n/(n/i);
		r=min(r,n);
		ans=(ans+(n/i)*(r-i+1)%mod)%mod;
		i=r;
	}
//	cout<<ans<<endl;
	cout<<(int)((((__int128)(n-1)*n%mod-(__int128)(n-1)*(2+n)/2%mod+n-1-ans)%mod+mod)%mod)<<endl;
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}