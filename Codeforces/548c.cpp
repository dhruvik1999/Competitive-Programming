#include<bits/stdc++.h>

#define fast1 ios_base::sync_with_stdio(false)
#define fast2 cin.tie(NULL)
#define ll long long
#define mod 1000000007

using namespace std;

vector<int> v[100005];
vector<bool> vis(100005,false);
int cnt;
void dfs(int i){
	vis[i]=true;
	cnt++;
	for(int j=0;j<v[i].size();j++){
		if(!vis[v[i][j]]){
			dfs(v[i][j]);
		}
	}
}

ll po(ll x,ll y){
	if(y==0){
		return 1;
	}else if(y%2==0){
		ll temp = po(x,y/2)%mod;
		return ((temp%mod)*temp+++)%mod;
	}else{
		ll temp = po(x,y/2)%mod;
		 return((((temp%mod)*temp)%mod)*x)%mod;
	}

}


int main(){

	fast1;
	fast2;

	int n,k;
	cin >> n >> k;

	int p,q,r;
	for(int i=0;i<n-1;i++){
		cin >> p >> q >> r;
		if(r==0){
			v[p].push_back(q);
			v[q].push_back(p);
		}
	}
	int  ans = po(n,k)%mod;
	//cout << ans << "\n";
	for(int i=1;i<=n;i++){
		cnt=0;
		if(!vis[i]){
			dfs(i);

		ans = (ans - po(cnt,k));
		if(ans < 0)
			ans+=mod;
		}
	}

	cout << ans%mod << "\n";






	return 0;
}