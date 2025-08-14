#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;

void solve(){
	int n;
	cin>>n;
	n=1<<n;
	vector<int>a(n+10);
	for(int i=1;i<=n;i++)cin>>a[i];
	auto dfs=[&](auto dfs,int l,int r)->vector<int>{
		if(l==r)return {a[l]};
		int mid=l+r>>1;
		vector<int>A=dfs(dfs,l,mid);
		vector<int>B=dfs(dfs,mid+1,r);
		if(A[0]>B[0])swap(A,B);
		for(auto i : B)A.push_back(i);
		return A;
	};
	vector<int>ans=dfs(dfs,1,n);
	for(auto i : ans)cout<<i<<" ";
	cout<<endl;
	
	
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}