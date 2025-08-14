#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;

void solve(){
	int n;
	cin>>n;
	auto ask=[&](int x){
		cout<<"? "<<x<<endl;
		cin>>x;
		return x;
	};
	auto submit=[&](int x){
		cout<<"! "<<x<<endl;
	};
	int l=0,r=n+1,ans;
	while(l+1<r){
		int mid=l+r>>1;
		int res=ask(mid);
		if(res==0)l=mid,ans=l;
		else r=mid,ans=r-1;
	}
	submit(ans);	
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}