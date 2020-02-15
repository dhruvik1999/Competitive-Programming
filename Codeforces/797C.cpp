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

	string s;
	cin >> s;

	priority_queue< char  , vector<char> , greater<int> 	> pq;

	int n = s.length();
	vector<char> dp(n);
	string ans = "";

	for(int i=0;i<n;i++){
		pq.push( s[i] );
	}
	dp[n-1] = s[n-1];
	for(int i=n-2;i>=0;i--){
		dp[i] = min( dp[i+1] , s[i] );
	}

	stack<int> stk;

	for(int i=0;i<n;i++){

		while( stk.size()!=0 && stk.top() <= dp[i] ){
			ans+=stk.top();
			stk.pop();
		}

		if( s[i] == dp[i] ){
			ans+=s[i];
		}else{
			stk.push( s[i] );
		}

	}
	
	while( stk.size()!=0 ){
		ans+=stk.top();
		stk.pop();
	}

	cout << ans << "\n";


	return 0;
}




