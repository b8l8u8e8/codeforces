#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
typedef struct my{
	double a;
	int b,c;
	bool operator<(const my other)const {
		return a<other.a;
	}
}my;
void solve(){
	int n,q,A=-1;
	cin>>n>>q;
	vector<my>a(q+10);
	for(int i=1;i<=q;i++){
		cin>>a[i].b>>a[i].c;
		A=max(A,a[i].b);
		a[i].a=-1.0*a[i].c/(a[i].b-a[i].c);
	}
	A=90000;
	sort(a.begin()+1,a.begin()+1+q);
	map<int,my>mp;
	vector<int>temp(500);
	for(int i=1;i<=q;i++){
		if(!mp.count(a[i].b)||(mp.count(a[i].b)&&a[i].c>temp[a[i].b])){
			temp[a[i].b]=a[i].c;
			mp[a[i].b]=a[i];
		}
	}
	a.clear();
	a.push_back({0,0,0});
	for(auto [x,y]:mp){
		a.push_back(y);
	}
	q=a.size()-1;
	sort(a.begin()+1,a.begin()+1+q);
	int ans=n;
	if(n>A){
		int t=(n-A+a[1].b-a[1].c-1)/(a[1].b-a[1].c);
		n=n-t*a[1].b+t*a[1].c;
		ans+=t*a[1].c;
	}
	vector<int>f(A+10);
	for(int j=1;j<=A;j++){
		for(int i=1;i<=q;i++){	
			if(j>=a[i].b)f[j]=max(f[j],f[j-a[i].b+a[i].c]+a[i].c);
		}
	}
	cout<<ans+f[n]<<endl;
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}
