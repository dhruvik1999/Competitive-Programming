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

vector<int> dp(1001,-1);
vector< vector<int> > ncr( 1001 , vector<int>(1001,0) );

void solve1(){
	for(int i=0;i<=1000;i++){
		ncr[i][0]=1;
	}

	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
		}
	}
}

void solve(){
	dp[0]=1;
	dp[1]=0;
	dp[2]=1;
	dp[3]=2;
	dp[4]=9;
}

int32_t main(){
	fastio();

	int n,k;
	cin >> n >> k;

	solve1();
	solve();

	int ans = 0;

	for(int i=n-k;i<=n;i++){
		ans += ncr[n][i]*dp[n-i];
	}

	cout << ans << "\n";






	return 0;
}




