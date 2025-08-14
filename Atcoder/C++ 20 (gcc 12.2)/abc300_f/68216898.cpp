#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	string s;
	cin>>s;
	s=" "+s;
	vector<int>s2(n+10);
	for(int i=1;i<=n;i++){
		if(s[i]=='x')s2[i]+=s2[i-1]+1;
		else s2[i]=s2[i-1];
	}
	auto get=[&](int x){
		if(x<=n)return s2[x];
		int t=x/n,t2=x%n;
		return t*s2[n]+s2[t2];
	};
	auto check=[&](int i,int mid){
		return get(mid)-get(i-1)<=k;
	};
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i-1,r=n*m+1;
		while(l+1<r){
			int mid=l+r>>1;
			if(check(i,mid))l=mid;
			else r=mid;
		}
		ans=max(l-i+1,ans);
	}
	cout<<ans<<endl;
	
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}
