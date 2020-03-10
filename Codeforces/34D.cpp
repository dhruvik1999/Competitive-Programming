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

vector<int> dp(1000000,0);

void solve( vector<int> *tree, int node, int par, vector<bool> &vis ){
	vis[node]=true;
	dp[ node ]=par;


	for(int i=0;i<tree[node].size();i++){
		if( vis[ tree[node][i] ]==false ){
			solve(tree,tree[node][i],node,vis);
		}
	}

}

int32_t main(){
	fastio();

	int n,r1,r2;
	cin >> n >> r1 >> r2;

	vector<int> tree[n+1];
	int t;
	for(int i=1;i<=n;i++){
		if( i!=r1 ){
			cin >> t;
			tree[t].push_back(i);
			tree[i].push_back(t);
		}
	}

	vector< bool > vis(1000000,false);
	solve( tree, r2, -1, vis );

	for(int i=1;i<=n;i++){
		if(i!=r2){
			cout << dp[i] << " ";
		}

	}
	cout << "\n";
	
	return 0;
}