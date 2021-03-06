#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MOD 1000000007
#define maxlen 1000005

int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
vector<int> primeFact(int n){vector<int> ans;for(int t=2;t<=sqrt(n);t++){if(n%t==0){ans.push_back(t);while(n%t==0){n=n/t;}}}if(n>2)ans.push_back(n);return ans;}
vector<int> fact(int n){vector<int> ans;for(int i=1;i<=sqrt(n);i++){if(n%i==0){if( i*i == n ){ans.push_back(i);}else{ans.push_back(i);ans.push_back(n/i);}}}return ans;}
int powerr(int base,int exp,int mod) { if(exp==0)return 1;int t = powerr(base,exp/2,mod)%mod;if(exp%2==0){return (t%mod*t%mod)%mod;}else{return (t%mod*t%mod*base%mod)%mod;}} 
void fastio(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}

int32_t main(){
	fastio();

	int n,m;
	cin >> n >> m;

	vector<int> graph[n+1];

	int p,q;
	for(int i=0;i<m;i++){
		cin >> p >> q;
		graph[p].push_back(q);
	}

	vector< vector<int> > dp(n+1 , vector<int>(n+1 , 0));

	for(int i=1;i<=n;i++){
		for(int j=0;j<graph[i].size();j++){
			for(int k=0;k<graph[graph[i][j]].size();k++){
				dp[i][graph[graph[i][j]][k]]++;
			}
		}
	}

	int ans =  0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if( dp[i][j]>=2 && i!=j ){
				ans += (dp[i][j]*(dp[i][j]-1))/2;
			}
		}
	}
	cout << ans << "\n";


	return 0;
}




