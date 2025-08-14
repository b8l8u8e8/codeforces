#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;

bool is_primes(int x){
	for(int i=2;i<=x/i;i++){
		if(x%i==0)return false;
	}
	return true;
}
void solve(){
	int n,p;
	cin>>n>>p;
	vector<int>primes;
	for(int i=2;i<=p;i++){
//		cout<<i<<endl;
		if(is_primes(i))primes.push_back(i);
	}
	vector<int>a={1},b={1};
	auto get=[&](vector<int>&c,int p2){
		int m=c.size();
		for(int i=0;i<m;i++){
			int t=c[i];
			for(;t<=n/p2;){
				c.push_back(t*p2);
				t*=p2;
			}
		}
	};
	for(auto i : primes){
		if(a.size()<=b.size())get(a,i);
		else get(b,i);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int ans=0,j=b.size()-1;
	for(int i=0;i<a.size();i++){
		int lim=n/a[i];
		while(j>=0&&b[j]>lim)j--;
		if(j<0)break;
		ans+=j+1;
	}
	cout<<ans<<endl;
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}