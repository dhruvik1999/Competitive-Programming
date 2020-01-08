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

vector<int> dp(26,0);

char getMin(  ){
	for(int i=0;i<26;i++){
		if( dp[i]!=0 ){
			return ((char)(i+'a'));
		}
	}
}

int32_t main(){
	fastio();

	string s;
	cin >> s;
	int n = s.length();
	
	for(int i=0;i<n;i++){
		dp[ s[i]-'a' ]++;
	}

	stack<char> st;
	string ans = "";
	int i=0;
	char t;
	while(i<=n){

		if(st.size()!=0){
			dp[ st.top()-'a' ]++;
		}

		if( st.size()!=0 && getMin()==st.top() ){
			ans+=st.top();
			dp[ st.top()-'a' ]--;
			st.pop();
		}else{
			if(st.size()!=0){
			dp[ st.top()-'a' ]++;
		}
			st.push( s[i] );
			dp[s[i]-'a']--;
			i++;
		}
	}

	while(st.size()!=0){
		ans+=st.top();
		st.pop();
	}

	cout << ans << "\n";


	return 0;
}




