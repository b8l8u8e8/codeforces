#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>g(n+10,vector<int>(n+10));
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		g[x][y]=1;
		g[y][x]=1;
	}
	vector<int>a(n+10);
	int ans=1e9;
	for(int i=1;i<=n;i++)a[i]=i;
	auto get=[&](int l,int r){
		int cnt=0,cnt2=0;
		//一个环
		for(int i=l+1;i<=r+1;i++){
			if(i<=r){
				if(!(g[a[i-1]][a[i]]==1||g[a[i]][a[i-1]]==1)){//
					cnt++;
				}else{
					cnt2++;
				}
			}else{
				if(!(g[a[l]][a[r]]==1||g[a[r]][a[l]]==1)){//
					cnt++;
				}else{
					cnt2++;
				}
			}
		}
		return (m-cnt2+cnt);
	};
	auto get2=[&](int l,int r,int mid){
		int cnt=0,cnt2=0;
		//两个环
		for(int i=l+1;i<=mid+1;i++){
			if(i<=mid){
				if(!(g[a[i-1]][a[i]]==1||g[a[i]][a[i-1]]==1)){//
					cnt++;
				}else{
					cnt2++;
				}
			}else{
				if(!(g[a[l]][a[mid]]==1||g[a[mid]][a[l]]==1)){//
					cnt++;
				}else{
					cnt2++;
				}
			}	
		}
		for(int i=mid+2;i<=n+1;i++){
			if(i<=n){
				if(!(g[a[i-1]][a[i]]==1||g[a[i]][a[i-1]]==1)){//
					cnt++;
				}else{
					cnt2++;
				}
			}else{
				if(!(g[a[mid+1]][a[n]]==1||g[a[n]][a[mid+1]]==1)){//
					cnt++;
				}else{
					cnt2++;
				}
			}	
		}	
		return (m-cnt2+cnt);
	};
	do{
		ans=min(ans,get(1,n));
		for(int i=3;i+3<=n;i++){
			ans=min(ans,get2(1,n,i));
		}
	}while(next_permutation(a.begin()+1,a.begin()+1+n));
	cout<<ans<<endl;
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}
