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
	int t;
	cin >> t;

	while(t--){

		int n;
		cin >> n;
		string s;
		cin >> s;

		// int ans = 0,ls=0;
		// for(int i=1;i<n;i++){
		// 	if(s[i]=='P' && s[i-1]=='A'){
		// 		ls=1;
		// 	}else if( ls!=0 && s[i]=='P' && s[i-1]=='P' ){
		// 		ls++;
		// 		ans = max( ans , ls );
		// 	}else{
		// 		ls=0;
		// 	}
		// }

		// ans= max(ans , ls);

		// cout << ans << "\n";

		vector<int> dp(n,0);
		int ans =  0;
		for(int i=1;i<n;i++){
			if( s[i]=='P' && s[i-1]=='A' ){
				dp[i]=1;
			}else if(s[i]=='P' && s[i-1]=='P' && dp[i-1]!=0)  {
				dp[i] = dp[i-1]+1;
			}
			ans = max( ans , dp[i] );
		}

		cout  << ans << "\n";

	}

	return 0;
}




