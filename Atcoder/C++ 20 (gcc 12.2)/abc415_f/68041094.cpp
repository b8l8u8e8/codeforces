#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
typedef struct{
	int l,r,leftn,rightn,is_,ans;
	char leftc,rightc;
}my;
void solve(){
	int n,q;
	cin>>n>>q;
	string a;
	cin>>a;
	a=" "+a;
	vector<my>tr(4*n+10);
	auto push_up=[&](my lef,my rig){
		my res={lef.l,rig.r};
		res.ans=1;
		res.leftc=lef.leftc,res.rightc=rig.rightc;
		if(lef.is_==1&&rig.is_==1){
			if(lef.leftc==rig.rightc){
				res.leftn=res.rightn=lef.leftn+rig.rightn;
				res.ans=res.leftn;
				res.is_=1;
			}else{
				res.leftn=lef.leftn;
				res.rightn=rig.rightn;
				res.ans=max(res.leftn,res.rightn);
				res.is_=0;
			}	
		}else if(lef.is_){
			res.leftn=lef.leftn;
			res.rightn=rig.rightn;
			res.ans=max(res.leftn,rig.ans);
			res.is_=0;
			if(lef.rightc==rig.leftc){
				res.leftn=lef.rightn+rig.leftn;
				res.ans=max(res.ans,lef.rightn+rig.leftn);
			}
		}else if(rig.is_){
			res.leftn=lef.leftn;
			res.rightn=rig.rightn;
			res.ans=max(lef.ans,res.rightn);
			res.is_=0;
			if(lef.rightc==rig.leftc){
				res.rightn=lef.rightn+rig.leftn;
				res.ans=max(res.ans,lef.rightn+rig.leftn);
			}
		}else{
			res.leftn=lef.leftn;
			res.rightn=rig.rightn;
			res.ans=max(lef.ans,rig.ans);
			res.is_=0;
			if(lef.rightc==rig.leftc){
				res.ans=max(res.ans,lef.rightn+rig.leftn);
			}
		}
		return res;
	};
	auto push_up2=[&](int u){
		my lef=tr[u<<1],rig=tr[u<<1|1];
		auto res=push_up(lef,rig);
		return res;
	};
	auto build=[&](auto build,int u,int l,int r)->void{
		if(l==r)tr[u]={l,r,1,1,1,1,a[l],a[l]};
		else{
			tr[u]={l,r};
			int mid=l+r>>1;
			build(build,u<<1,l,mid),build(build,u<<1|1,mid+1,r);
			tr[u]=push_up2(u);
		}
	};
	auto modify=[&](auto modify,int u,int x,char c)->void{
		if(tr[u].l==tr[u].r&&tr[u].l==x)tr[u]={tr[u].l,tr[u].l,1,1,1,1,c,c};
		else{
			int mid=tr[u].l+tr[u].r>>1;
			if(x<=mid)modify(modify,u<<1,x,c);
			else modify(modify,u<<1|1,x,c);
			tr[u]=push_up2(u);
		}
	};
	auto query=[&](auto query,int u,int l,int r){
		if(tr[u].l>=l&&tr[u].r<=r)return tr[u];
		else{
			int mid=tr[u].l+tr[u].r>>1;
			if(r<=mid)return query(query,u<<1,l,r);
			else if(l>mid)return query(query,u<<1|1,l,r);
			else{
				my lef=query(query,u<<1,l,r),rig=query(query,u<<1|1,l,r);
				auto res=push_up(lef,rig);
				return res;
			}
		}
	};
	build(build,1,1,n);
	while(q--){
		int op;
		cin>>op;
		if(op==1){//修改
			int x;
			char c;
			cin>>x>>c;
			modify(modify,1,x,c);
		}else{//求
			int l,r;
			cin>>l>>r;
			cout<<query(query,1,l,r).ans<<endl;
		}
	}
}

signed main(){
	int t=1;ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}