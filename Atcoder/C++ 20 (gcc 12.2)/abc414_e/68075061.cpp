#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n+10);
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==m){
		cout<<0<<endl;
		return ;
	}
	sort(a.begin()+1,a.begin()+1+n);
	if(m==1){
		cout<<a[n]-a[1]<<endl;
		return ;
	}
	vector<PII>b;
	for(int i=2;i<=n;i++){
		b.push_back({a[i]-a[i-1],i});
	}
	sort(b.begin(),b.end(),greater<PII>());
	int cnt=0;
	map<int,int>mp;
	for(auto [x,y]:b){
		cnt++;
		mp[y]=1;
//		cout<<y<<endl;
		if(cnt==m-1)break;
	}
	int pre=1,ans=0;
//	for(auto [x,y] :mp)cout<<x<<" "<<y<<endl;
//	cout<<endl;
	for(int i=2;i<=n;i++){
//		cout<<i<<endl;
		if(mp.count(i)){
//			cout<<i<<endl;
			ans+=a[i-1]-a[pre];
//			cout<<a[i-1]<<" "<<a[pre]<<endl;
			pre=i;
//			break;
		}
//		pre+=a[i];
	}
	ans+=a[n]-a[pre];
	cout<<ans<<endl;
	
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}

