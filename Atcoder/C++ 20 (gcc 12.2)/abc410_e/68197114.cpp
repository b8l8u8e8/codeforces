#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;

void solve(){
	int n;
	cin>>n;
	int lim=sqrt(n);
	vector<int>primes(lim+10),st(lim+10);
	int cnt=0;
	auto get_prime=[&](){
		for(int i=2;i<=lim;i++){
			if(!st[i])primes[cnt++]=i;
			for(int j=0;primes[j]<=lim/i;j++){
				st[i*primes[j]]=1;
				if(i%primes[j]==0)break;
			}
		}	
	};
	get_prime();
//	cout<<lim<<endl;
	int ans=0;
	for(int i=0;i<cnt;i++){
		int t=primes[i]*primes[i];
		int lim2=n/t;//a^2*b
		int p=upper_bound(primes.begin(),primes.begin()+cnt,min(lim2,primes[i]-1))-primes.begin();
		p--;
		for(int j=p;j>=0;j--){
			int t2=primes[j];
			int lim3=lim2/t2;//a^2
			int p2=upper_bound(primes.begin(),primes.begin()+cnt,min((int)sqrt(lim3),t2-1))-primes.begin();
			p2--;
//			if(p2>=0&&p2<cnt)cout<<primes[p2]<<" "<<t2<<" "<<primes[i]<<endl;
			if(p2>=0&&p2<cnt)ans+=p2+1;
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
