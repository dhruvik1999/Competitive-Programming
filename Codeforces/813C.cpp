#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007
#define maxlen 9223372036854775807
#define minlen -9223372036854775807
#define fin(n) for(int i=0;i<n;i++)

int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
vector<int> primeFact(int n){vector<int> ans;for(int t=2;t<=sqrt(n);t++){if(n%t==0){ans.push_back(t);while(n%t==0){n=n/t;}}}if(n>2)ans.push_back(n);return ans;}
vector<int> fact(int n){vector<int> ans;for(int i=1;i<=sqrt(n);i++){if(n%i==0){if( i*i == n ){ans.push_back(i);}else{ans.push_back(i);ans.push_back(n/i);}}}return ans;}
int powerr(int base,int exp,int mod) { if(exp==0)return 1;int t = powerr(base,exp/2,mod)%mod;if(exp%2==0){return (t%mod*t%mod)%mod;}else{return (t%mod*t%mod*base%mod)%mod;}} 
void fastio(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}

int dfs( vector< int > tree[], int n, vector<int> &par, int pp, vector<bool> &vis,int node,vector<int> &mlen){
	vis[node]=true;
	par[node]=pp;


	for(int i=0;i<tree[node].size();i++){
		if( vis[ tree[node][i] ]==false ){
			mlen[node] = max( mlen[node] , dfs( tree,n,par,node,vis,tree[node][i], mlen ) );
		}
	}

	mlen[node]+=1;

	return mlen[node];
}

int32_t main(){
	fastio();

	int n,x;
	cin >> n >> x;

	vector< int > tree[n+1];
	int p,q;

	for(int i=0;i<n-1;i++){
		cin >> p >> q;
		tree[p].push_back(q);
		tree[q].push_back(p);
	}
	vector<int> par( n+10 , 0 );
	vector< bool > vis(n+1,false);
	vector< int > mlen(n+1,0);
	dfs( tree, n, par, -1, vis, 1, mlen);
	// for(int i=1;i<=n;i++){
	// 	cout << i << " " << par[i] << "\n";
	// }

	deque<int> path;
	int t = x;
	path.push_front(t);

	while(t!=1){
		t=par[t];
		path.push_front(t);
	}

	// for(int i=0;i<path.size();i++){
	// 	cout << path[i] << " ";
	// }
	// cout << "\n";

	int ans = 0;

	int aa=1,bb=x,cp=0;

	if( par[bb]!=aa ){
		while( par[bb]!=aa && par[bb]!=path[cp+1] ){
			bb=par[bb];
			cp++;
			aa=path[cp];
			ans+=2;
		}
	}

	ans+= 2*( mlen[bb]-1 );
	if( par[bb]==aa ){
		ans+=2;
	}else if( par[bb]==path[cp+1] ){
		ans+=4;
	}

	cout << ans << "\n";


	return 0;
}
