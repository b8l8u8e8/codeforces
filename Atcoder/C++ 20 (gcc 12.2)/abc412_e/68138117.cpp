#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
int cnt,prime[10000010],st[10000010];
void solve(){
	int l,r;
	cin>>l>>r;
	int n=sqrt(r);
	l++;
	for(int i=2;i<=n;i++){
		if(!st[i])prime[cnt++]=i;
		for(int j=0;prime[j]<=n/i;j++){
			st[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	int ans=0;
	for(int i=0;i<cnt;i++){
		int t=prime[i],t2=t;
		if(t>=l)ans++;
		for(;t<=r/t2;t*=t2){
			if(t*t2>=l){
				ans++;
//				cout<<t*t<<endl;
			}
		}
	}
	vector<int>st2(r-l+10);
	for(int i=0;i<cnt;i++){
		int t=prime[i];
		for(int j=t*((l+t-1)/t);j<=r;j+=t){
			if(st2[j-l])continue;
			st2[j-l]=1;
		}
	}
	for(int i=l;i<=r;i++){
//		cout<<i<<" "<<st2[i-l]<<endl;
		if(st2[i-l]==0)ans++;
	}
	cout<<ans+1<<endl;
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}