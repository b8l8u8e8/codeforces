#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
int mod=998244353;
void solve(){
	int n;
	cin>>n;
	vector<int>a(n+10);
	map<int,int>mp;
	for(int i=1;i<=n;i++)cin>>a[i],mp[a[i]]++;
	sort(a.begin()+1,a.begin()+1+n,[](int a,int b){
		return abs(a)<abs(b);
	});
	if(n<=2){
		cout<<"Yes"<<endl;
		return ;
	}
	if(mp.size()==1){
		cout<<"Yes"<<endl;
	}else if(mp.size()==2){
		vector<PII>s;
		for(auto [x,y]:mp){
			s.push_back({x,y});
		}
		if(s[0].first*-1==s[1].first&&abs(s[0].second-s[1].second)<=1){
			cout<<"Yes"<<endl;
		}else cout<<"No"<<endl;
	}else{
		for(int i=2;i<n;i++){
			if(a[i]*a[i]!=a[i-1]*a[i+1]){
				cout<<"No"<<endl;
				return;
			}
		}
		cout<<"Yes"<<endl;
	}
	
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}