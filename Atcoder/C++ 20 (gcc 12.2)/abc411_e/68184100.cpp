#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
const int mod=998244353;
int qi_mi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void solve(){
	int n;
	cin>>n;
	vector<vector<int>>a(n+10,vector<int>(10));
	vector<int>s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++){
			cin>>a[i][j];
			s.push_back(a[i][j]);
		}
	}
	sort(s.begin(),s.end());
	s.erase(unique(s.begin(),s.end()),s.end());
	vector<vector<int>>upd(s.size()+10,vector<int>(0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++){
			upd[lower_bound(s.begin(),s.end(),a[i][j])-s.begin()].push_back(i);
		}
	}
	vector<int>b(n+10,0);
	int pre=0;
	int prob=1;
	int b0_cnt=n;
	int ans=0;
	int inv6_n=qi_mi(qi_mi(6,mod-2),n);
	for(int i=0;i<s.size();i++){
		int wid=s[i]-pre;
		int high=0;
		if(b0_cnt==0){
			high=prob*inv6_n%mod;
		}
		high=(1-high+mod)%mod;
		ans=(ans+wid*high%mod)%mod;
		for(auto j:upd[i]){
			if(b[j]==0){
				b0_cnt--;
			}
			if(b[j]!=0)prob=prob*qi_mi(b[j],mod-2)%mod;
			b[j]++;
			prob=prob*b[j]%mod;
		}
		pre=s[i];
	}
	cout<<ans<<endl;
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}