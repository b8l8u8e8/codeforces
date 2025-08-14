#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;

void solve(){
	int n;
	cin>>n;
	string str;
	cin>>str;
	vector<int>s(str.size()+10);
	for(int i=0;i<str.size();i++){
		if(str[i]=='1')s[i+1]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=1ll<<(i-1);
//	cout<<ans<<endl;
	map<int,int>st;
	auto bfs=[&](){
		queue<int>q;
		q.push(0);
		while(q.size()){
			int t=q.front();
//			cout<<t<<" "<<ans<<endl;
			q.pop();
			if(st[t])continue;
			st[t]=1;
			if(t==ans){
				cout<<"Yes"<<endl;
				return true;
			}
			for(int i=1;i<=n;i++){
				if(((t>>(i-1))&1)==0){
//					cout<<"#"<<" "<<t<<endl;
//					cout<<"#"<<" "<<s[t|(1ll<<(i-1))]<<" "<<(t|(1ll<<(i-1)))<<endl;
					if(s[t|(1ll<<(i-1))])continue;
					q.push(t|(1ll<<(i-1)));
					
				}
			}
		}
		return false;
	};
	if(bfs())return ;
	cout<<"No"<<endl;
	
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}