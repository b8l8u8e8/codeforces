#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
typedef struct my{
	long long a,b,c;
	bool operator>(const my& other) const {
		if(a > other.a){
			return true;
		}else if(a==other.a){
			return b>other.b;
		}
		return false;
	}
}my;
void solve(){
	long long n,m;
	cin>>n>>m;
	vector<my>a(m+10);
	priority_queue<my,vector<my>,greater<my>>s;
	for(int i=1;i<=m;i++){
		cin>>a[i].b>>a[i].c;
		a[i].a=a[i].b-a[i].c;
		s.push(a[i]);
	}
	long long cnt=0;
	while(n>0&&s.size()){
		auto t=s.top();
		while(n<t.b&&s.size()){
			s.pop();
			if(s.size()>=1)t=s.top();
		}
//		if(n==3)cout<<s.top().b<<endl;
		if(s.size()==0)break;
		auto t2=s.top();
		t=t2;
		
//		cout<<n<<" "<<t.b<<endl;
		long long ans=(n-t.b)/t.a+1;
//		cout<<ans<<endl;
		if(ans>0){
//			cout<<n<<" "<<ans*t.a<<endl;
			n=n-ans*t.a;
			cnt+=ans;
		}
//		cout<<"# "<<n<<endl;
	}
	cout<<cnt<<endl;
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}
