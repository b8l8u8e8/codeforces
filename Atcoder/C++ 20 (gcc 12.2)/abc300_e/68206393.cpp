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
	map<int,int>f;
	f[n]=1;
	auto dfs=[&](auto dfs,int x){//求f[x] 当前为x需要投筛子到n
		if(f.count(x))return f[x];
		if(x>n)return 0ll;
		int res=0;
		for(int i=2;i<=6;i++){
			res+=dfs(dfs,x*i);
		}
		return f[x]=res*qi_mi(5,mod-2)%mod;
	};
	cout<<dfs(dfs,1)<<endl;
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}